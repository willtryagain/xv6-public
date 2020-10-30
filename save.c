#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int open;
int fd;

int main (void)
{

    printf(1,"My Name\n");
    fd = open("/home/kyle/Desktop/Projects/Assignment 2/xv6/Tom.txt", O_RDWR | O_CREATE);

    write(fd, "1 2 3 4", 7);
    close(fd);

}