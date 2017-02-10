#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <regex.h>

// function declarations
int error();
void help();
void printUsage();
int compile(char *);

// enum programs : for reference
enum language{
    c, cpp, java, python
};

// global variables
// name of the input file, and a boolean variable that holds existance of the input file in the command
char input[256];
int input_file_exists=0;

// name of the output file, and boolean variable that holds existance of the output file in the command
char output[256];
int output_file_exists=0;

void printUsage(){
    // usage syntax
    system("echo \"\\033[1mUSAGE: \\033[0m \"");
    system("echo \" exe program_file \\033[3moptions \\033[0m \"");
    system("echo \" exe program_file input_file output_file\"");
    system("echo \" exe program_file input_file \"");
    printf("\n");
    // options
    system("echo \"\\033[1mOPTIONS: \\033[0m \"");
    printf(" %-20s  \n","-i input_file");
    printf(" %-20s  To provide the input for the execution of the C program\n\n","--input input_file");
    printf(" %-20s  \n","-o output_file");
    printf(" %-20s  To redirect the output into output_file\n\n","--output output_file");
    printf(" %-20s  \n","-h");
    printf(" %-20s  Shows usage \n\n","--help");
    printf("\n");
}
void help(){
    // additional data : description
    system("echo \"\\033[1mDESCRIPTION: \\033[0m \"");
    puts(" This utility is used to compile and execute a C, Java, Python, C++ or any other imperative language program at a time");
    printf("\n");
    printUsage();
    // additional data : author
    system("echo \"\\033[1mAUTHOR: \\033[0m \"");
    printf(" Written by Manoj Vignesh");
    printf("\n");
    exit(0);
}

int error(){
    system("echo \"\\033[1;31m- Fatal Error! Exiting! -\\033[0m \" ");
    printf("\n");
    exit(-1);
}

int compile(char *input_file){
    char *file = malloc(256);
    strcpy(file,input_file);
    char *filetype, *token;
    while((token=strsep(&file,"."))!='\0') filetype=token;
    char *command = malloc(500);
    strcpy(command,"");
    int program = -1;
    if(strcmp(filetype,"c")==0) {
        strcat(command,"gcc --std=gnu11 ");
        strcat(command,input_file);
        program = 0;
    } else if(strcmp(filetype,"cpp")==0) {
        strcat(command,"g++ --std=c++11 ");
        strcat(command,input_file);
        program = 1;
    } else if(strcmp(filetype,"java")==0) {
        strcat(command,"javac ");
        strcat(command,input_file);
        program = 2;
    } else if(strcmp(filetype,"py")==0) {
        strcpy(command,"echo \"\\033[3;30mCompilation not required for python programs! \\033[0m\"");
        program = 3;
    } else {
        strcpy(command,"echo \"\\033[3;30mCompilation for this type is undefined \\033[0m\"");
        program = -1;
    }
    int ret = system(command);
    if(ret == 0) return program;
    return -1;
}

int main(int argc, char* argv[]){
    // If only the command is entered, or command is entered with '--help or -h' option then print the help text
    if(argc==1 || (argc==2 && (strcmp(argv[1],"-h")==0 || strcmp(argv[1],"-help")==0))) help();
    system("echo \"\\033[0;34m\\033[1mCompiling.... \\033[0m\"");

    // compile the input file
    int program = compile(argv[1]);
    if(program==-1) error();
    system("echo \"\\033[0;34m\\033[1mCompiled...Executing \\033[0m\"");

    // standard format of command program input output
    int contains_option = 0;
    for(int i=2;i<argc;i++){
        char* parameter = argv[i];
        if(parameter[0]=='-'){
            contains_option=1;
            break;
        }
    }

    // if it doesnt contain any option, then the command is in the standard format
    if(!contains_option){
        // if arguments count is greater than 2, then input file is provided in command line as third argument
        if(argc>2){
            char *input_file = argv[2];
            // check if the input file exists, and required permissions are present
            if(open(input_file,O_RDONLY)==-1){
                system("echo -n \"\\033[3;30m\"");
                perror("Input file ");
                system("echo \"\\033[0m\"");
                error();
            }
            strcpy(input,input_file);
            input_file_exists=1;
        }
        // if arguments count is greater than 3, then output file is provided in the command line as the fourth argument
        if(argc>3){
            char *output_file = argv[3];
            strcpy(output,output_file);
            output_file_exists=1;
        }
    }
    // general syntax with parameters and options
    for(int i=2;i<argc;i++){
        char* parameter = argv[i];
        // check if there is input file parameter mentioned; if it exists, then just after the option is the input file
        if(strcmp("-i",parameter)==0 || strcmp("--input",parameter)==0){
            if(argc<i+2) error();
            char* input_file = argv[i+1];
            // check if the input file exists, and has the required permissions to open it
            if(open(input_file,O_RDONLY)==-1){
                system("echo -n \"\\033[3;30m\"");
                perror("Input file ");
                system("echo \"\\033[0m\"");
                error();
            }
            strcpy(input,input_file);
            input_file_exists=1;
        }
        // check if there is output file parameter mentioned; if it exists, then use it in write only mode, else create it and use it.
        if(strcmp("-o",parameter)==0 || strcmp("--output",parameter)==0){
            if(argc<i+2) error();
            char* output_file = argv[i+1];
            if(open(output_file,O_CREAT|O_WRONLY,0644)==-1){
                system("echo -n \"\\033[3;30m\"");
                perror("Output file ");
                system("echo \"\\033[0m\"");
                error();
            }
            strcpy(output,output_file);
            output_file_exists=1;
        }
    }
    system("echo \"\\033[0;32m\\033[1m-----Output----------\\033[0m\"");
    printf("\n");
    if(output_file_exists) system("echo \"\\033[3;30mRedirecting output into a file...\\033[0m\"");

    // build the command to execute
    char *command=malloc(750);
    strcpy(command,"");
    if(program == 0 || program == 1){
        strcat(command,"./a.out");
    } else if(program == 2){
        strcat(command,"java ");
        strcat(command,strsep(argv+1,"."));
    } else if(program == 3){
        strcat(command,"python ");
        strcat(command,argv[1]);
    }
    if(input_file_exists){
        strcat(command,"<");
        strcat(command,input);
    }
    if(output_file_exists){
        strcat(command,">");
        strcat(command,output);
    }
    // execute the command
    system(command);
    system("echo  \"\"");

    if(output_file_exists) system("echo \"\\033[3;30mRedirected output output into the file\\033[0m\"");
    system("echo \"\\033[0;32m\\033[1m-----The End----------\\033[0m\"");
    return 0;
}
