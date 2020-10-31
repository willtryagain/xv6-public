#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
	int new_priority = atoi(argv[1]);
	int pid = atoi(argv[2]);
	//printf(1, "new_priority:%d pid:%d\n", new_priority, pid);
	int old = set_priority(new_priority, pid);
	printf(1, "old priority:%d\n", old);
	exit();
}
