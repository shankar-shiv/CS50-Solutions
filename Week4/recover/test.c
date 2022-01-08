#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int b = 0xE0;
    int low = b & 0x0F;
    int high = b >> 4;

    printf("%#08x \n", low);
    printf("%#04x \n", high);
}