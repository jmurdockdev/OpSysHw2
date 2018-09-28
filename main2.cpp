#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fstream>


using namespace std;

const  int MAXLINE = 40;
char line[MAXLINE];

int main(int argc, char *argv[])
{

    string arr[10];

    FILE *output = popen("find . -name \"*.c\"" , "w");

    int i = 0;
    while (fgets(line, MAXLINE, output) != NULL)
    {
    //copy line into the array;
        puts (line);
    i++;
    }

    //pclose(output);

    for(int j = 0 ; j < 5 ; j++)
    {
        cout <<  line << endl;

    }

    return 0;
}
