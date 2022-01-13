#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Incorrect Usage. use second commandline argument as filename\n");
        exit(1);
    }
    char *filename = argv[1];

    char buff[2048];
    int fd = open(filename, O_RDONLY);
    size_t count = read(fd, buff, 2048);
    write(1, buff, count);
    close(fd);
}