#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#ifndef FIFO_NAME
#define FIFO_NAME "PIPE"
#endif

const int MAXLINE =100;
char buffer[MAXLINE];

int main()
{
	const char outFile[] = "server.txt";

	FILE *fp = fopen(outFile, "w");

	if (fp == 0) {
		printf("Could not write to file");
		return 1;
	}


	mknod(FIFO_NAME, S_IFIFO | 0666, 0);

	int fd = open(FIFO_NAME, O_RDONLY);

	if (fd > 0) {

		int num;

		while ((num = read(fd, buffer, MAXLINE)) > 0)
		{
			//int h = strcmp(buffer, "Stop\n\0");
			//printf("%d",h);
			if (strcmp(buffer, "Stop\n\0") == 10){

				break;
			}

			printf("%s\n", buffer);
			fprintf(fp, "%.*s", num, buffer);
		}

		close(fd);
	}
	fclose(fp);

	unlink(FIFO_NAME);

	return 0;
}
