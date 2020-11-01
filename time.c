#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[]) {
    //fork
    int pid = fork();
    if(pid == 0)
        exec(argv[1],argv+1);
    else {
        //in parent
        int waittime,runtime;
        int status;
        status = waitx(&waittime,&runtime);
        //print to stdout
        printf(1, "pid: %d\n", status);
        printf(1, "waittime: %d\n", waittime);
        printf(1, "runtime: %d\n", runtime);

    }
    exit();
}
