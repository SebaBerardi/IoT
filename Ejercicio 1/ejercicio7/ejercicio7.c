#include <stdio.h>

int main() {
    int num = 496;
    int tot = 0;

    
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            tot += i; 
        }
    }

    if (num == tot) {
        printf("%d es perfecto\n", num);
    } else {
        printf("%d no es perfecto\n", num);
    }

    return 0;
}

    