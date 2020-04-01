#include <stdio.h>

int main(int argc, char *argv[]){
    char c;
    int i = 1;
    while((c = getchar()) != EOF){
        if (i % 7 != 0) {
            putchar(c);
        }
    }
    return 0;
}
