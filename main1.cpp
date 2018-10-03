#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define O_RDWR 02

using namespace std;

int main(int argc, char *argv[])
{

    //Solution to problem 1

    if (argc != 3)
    {
       cout << "Invalid entry.  \n Usage: ./main source-file-name filename \n" << endl;
    }


    pid_t pid = fork();

    if (pid == 0)
    {

        int fd  = open(argv[2], O_RDWR);

        //cout << fd << endl;

        close(1);
        dup(fd);
        close(fd);

        if (fd == -1){
            perror(argv[2]);
            //exit(1);
        }else{

            execl( argv[1] , "-a", (char*) NULL ); //execl("/bin/ls" , "-l" );

        }

    }


    return 0;
}
