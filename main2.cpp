#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fstream>
//#include <vector>
#include <sstream>
#include <string>
#include <algorithm>


using namespace std;

const  int MAXLINE = 256;
char line[MAXLINE];




int main(int argc, char *argv[])
{

    FILE *output = popen("find . -name \"*.c\"" , "w");

    string num;

    string cmd = "find . -name \"*.c\" | wc -l";
    cmd.append(" 2>&1");

    FILE *numFiles = popen(cmd.c_str(), "r");
    if (numFiles)
    {
        while (!feof(numFiles))

            if (fgets(line, MAXLINE, numFiles) != NULL) num.append(line);

        pclose(numFiles);
    }

    pclose(output);
    //pclose(numFiles);

    stringstream ss("find . -name \"*.c\" | mailx -s ", ios_base::app | ios_base::out);

    ss << "\"" << num << "\" " << argv[1];


    string str(ss.str());

    str.erase(remove(str.begin(), str.end(), '\n'), str.end());

    const char* command = str.c_str();

    //cout << command << endl;

    popen(command , "w" );


    return 0;
}
