#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
void print_from_CL();
void print_files(int num_files, char *argv[]);

int main(int argc, char *argv[]){
    int num_files = argc - 1;

    if(num_files == 0){
        print_from_CL();
    }else{
        print_files(num_files, argv);
    }
    
}
void print_from_CL(){
    char buff[2048];
    size_t count;
    count = read(0, buff, sizeof(buff));
    for(int i = 0; i < (int) sizeof(buff); i++){
        buff[i] = toupper(buff[i]);
    }
    write(1, buff, count);
}

void print_files(int num_files, char *argv[]){
    char *filename;
    int fd;
    char buff[2048];
    size_t count;
    for(int i = 0; i < num_files; i++){
        filename = argv[i+1];
        fd = open(filename, O_RDONLY);
        if(fd == -1){
            perror("\nError: ");
            exit(-1);
        }
        count = read(fd, buff, 2048);
        for(int i = 0; i < (int) sizeof(buff); i++){
            buff[i] = toupper(buff[i]);
        }
        write(1, buff, count);
        close(fd);
    }
}