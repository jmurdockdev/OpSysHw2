#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sstream>

#ifndef FIFO_NAME
#define FIFO_NAME "PIPE"
#endif

const int MAXLINE =100;
char buffer[MAXLINE];

int main()
{
	const char inputFile[] = "problem3.txt";

	FILE *fp = fopen(inputFile, "r");

	if (fp == 0) {
		printf("Could not read file");
		return 1;
	}

	mknod(FIFO_NAME, S_IFIFO | 0666, 0);

	int fd = open(FIFO_NAME, O_WRONLY);

	if (fd > 0) {

		while (fgets(buffer, MAXLINE, fp))
		{
			char a;
			for(int i = 0; i < MAXLINE; i++){
				a = buffer[i];
				a = toupper(a);
				buffer[i] =a;
			}

			int len = strlen(buffer);

			int num = write(fd, buffer, len);

			if (num != len) {
				perror("Failure ");
			}

			sleep(1);


		}

		 char stop[] = {'S','t','o','p','\n', '\0'};
		int len1 = strlen(stop);
		write(fd, stop, len1);
		sleep(1);

		close(fd);
	}

	fclose(fp);

	return 0;
}
