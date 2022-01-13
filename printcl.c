#include <stdio.h>

int main(int argc, char *argv[]){
    for(int i = 0; i < argc; i++){
        char* arg = argv[i];
        printf("%d: %s\n", i, arg);
    }
}