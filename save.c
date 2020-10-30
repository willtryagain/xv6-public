#include "types.h"
#include "user.h"
#include "fcntl.h"

#define N 100

struct test {
    char name;
    int number;
};

void
save(void)
{
    int fd;
    struct test t;
    t.name = 's';
    t.number = 1;

    fd = open("backup", O_CREATE | O_RDWR);
    if(fd >= 0) {
        printf(1, "ok: create backup file succeed\n");
    } else {
        printf(1, "error: create backup file failed\n");
        exit();
    }

    int size = sizeof(t);
    if(write(fd, &t, size) != size){
        printf(1, "error: write to backup file failed\n");
        exit();
    }
    printf(1, "write ok\n");
    close(fd);
}

void
load(void)
{
    int fd;
    struct test t;

    fd = open("backup", O_RDONLY);
    if(fd >= 0) {
        printf(1, "ok: read backup file succeed\n");
    } else {
        printf(1, "error: read backup file failed\n");
        exit();
    }

    int size = sizeof(t);
    if(read(fd, &t, size) != size){
        printf(1, "error: read from backup file failed\n");
        exit();
    }
    printf(1, "file contents name %c and number %d", t.name, t.number);
    printf(1, "read ok\n");
    close(fd);
}

int
main(void)
{
    save();
    load();

    exit();
}