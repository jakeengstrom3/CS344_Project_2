#include <stdio.h>

int main(void){
    int x = 12;
    float y = 3.14;
    char* s = "Hello, world!\n";

    printf("X is %d, Y is %f\n%s", x, y, s);
    
    for(int i = 0; i <= 5; i++){
        int product = i * 5;
        printf("%d x 5 = %d\n", i, product);
    }
}