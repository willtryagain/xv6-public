#include "types.h"
#include "info.h"
#include "user.h"
#include "fcntl.h"

#define N 100



struct test {
    char name;
    int number;
};

void
save(int n, int pids_arr[])
{

    int fd = open("backup.txt", O_CREATE | O_RDWR);
    if(fd >= 0) {
        printf(1, "ok: create backup file succeed\n");
    } else {
        printf(1, "error: create backup file failed\n");
        exit();
    }

    int size = sizeof(n);
    if(write(fd, &n, size) != size){
        printf(1, "error: write to backup file failed\n");
        exit();
    }
    printf(1, "%d", pids_arr[n-1]);
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
int number;
int pids_arr[100];
get_number(&number);
//get_pids(&pids_arr);
  //for (int i = 0; i < index; ++i)
	//printf(1, "%d %d %d\n", info[index][0], info[index][1], info[index][2]);	
    save(number, pids_arr);
    //load();
   // printf(1, "%d %d\n", status, number);
    exit();
}
