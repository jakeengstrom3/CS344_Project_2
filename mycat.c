#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int num_files = argc - 1;

    char buff[2048];

    if(num_files == 0){
        size_t count = read(0, buff, sizeof(buff));
        write(1, buff, count);
        close(0);
        exit(0);
    }
    char *filename;
    int fd;
    size_t count;
    for(int i = 0; i < num_files; i++){
        filename = argv[i+1];
        fd = open(filename, O_RDONLY);
        if(fd == -1){
            printf("\nFile #%d: %s: Could not open file", i+1, filename);
            exit(-1);
        }
        count = read(fd, buff, 2048);
        write(1, buff, count);
        close(fd);
    }
}