#include "types.h"
#include "user.h"

#define N 10

int main() {
	int i;
	int pid;
	int priority;

	for (i = 0; i < N; i++) {
		pid = fork();

		
		/*if (pid < 0) {
			printf(1, "fork() fialed");
			
			exit();
		}
		else */if (pid == 0) {
			priority = (i + 5) * 3 * 8 % 7 + 1;

			printf(1, "Child process %d created with priority %d\n", getpid(), priority);
			set_proc_priority(getpid(), priority);
			
			exit();
		}
	}

	sleep(300);

	for (i = 0; i < N; i++)
		wait();

	exit();
}

/*
#include "user.h"
#include "fcntl.h"

int main() {
	int pid = 1;
	int priority = 10;

	if (set_proc_priority(pid, priority) == 0)
		printf("Success! set process %d priority to %d\n", pid, priority);
	else
		printf("failed\n");

	exit(0);
}
*/
