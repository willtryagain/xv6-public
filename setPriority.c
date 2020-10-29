#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
	int pid = atoi(argv[0]);
	int new_priority = atoi(argv[1]);
	int old = set_priority(new_priority, pid);
	printf(1, "old priority:%d\n", old);
	exit();
}
