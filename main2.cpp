#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fstream>
//#include <vector>
#include <sstream>

using namespace std;

const  int MAXLINE = 40;
char line[MAXLINE];

int main(int argc, char *argv[])
{

    //string arr[10];
    // email will be argv[1]



    FILE *output = popen("find . -name \"*.c\"" , "w");

    int i = 0;
    while (fgets(line, MAXLINE, output) != NULL)
    {
        //cout << i << endl;
        //copy line into the array;

        i++;
    }


    pclose(output);


    string num;
    stringstream convert;
    convert << i ;
    num = convert.str();

    stringstream ss("find . -name \"*.c\" | mailx -s ", ios_base::app | ios_base::out);

    ss << "\"" << num << "\" " << argv[1];

    string str(ss.str());

    const char* command = str.c_str();



    cout << command << endl;

    popen(command , "w" );



    return 0;
}
