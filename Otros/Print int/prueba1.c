#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int main()
{
    int val = 6;
    float resto = fmodf(val, 1.0f);
    if (fmodf(val, 1.0f) == 0.0f)
    {
        printf("%d", (int)val);
    }
    

}
 