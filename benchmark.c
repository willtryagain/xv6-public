#include "types.h"
#include "user.h"

int number_of_processes = 10;

int main(int argc, char *argv[])
{

    int n = atoi(argv[1]);
    for (int i = 0; i < n; ++i) {
	    volatile float a=0;
	    volatile float b=1.43;
	    volatile float c=1.35;
	    for(volatile int i=0;i<100000000;i++)
	    {
		a = (a + b * c);
	    }
   }
  exit();
}
