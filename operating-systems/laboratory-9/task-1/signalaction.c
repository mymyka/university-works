#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void signal_handler(int signo) {
	if (signo == SIGINT)
		printf("Taken SIGINT!\n");
	else if (signo == SIGTERM)
		printf("Taken SIGTERM!\n");
	else if (signo == SIGUSR1)
		printf("Taken SIGUSR1!\n");
	else {
		fprintf(stderr, "Error!\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}


int main (void) {
	struct sigaction sa;
    	sa.sa_handler = signal_handler;
     	
	
	if (sigaction(SIGINT, &sa, 0) != 0) {
		fprintf(stderr, "Error SIGINT!\n");
		exit(EXIT_FAILURE);
	}

	if (sigaction(SIGTERM, &sa, 0) != 0) {
		fprintf(stderr, "Error SIGTERM!\n");
		exit(EXIT_FAILURE);
	}


	if (sigaction(SIGUSR1, &sa, 0) != 0) {
		fprintf(stderr, "Error SIGUSR1!\n");
		exit(EXIT_FAILURE);
	}

	sa.sa_handler = SIG_DFL;
	if (sigaction(SIGPROF, &sa, 0) != 0) {
		fprintf(stderr, "Error SIGPROF!\n");
		exit(EXIT_FAILURE);
	}

	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGHUP, &sa, 0) != 0) {
		fprintf(stderr, "Error SlGHUP!\n");
		exit(EXIT_FAILURE);
	}
	for (;;) {
		pause();
	}
	return 0;
}
