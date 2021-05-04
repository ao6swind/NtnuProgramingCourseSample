#include <stdio.h>
#include <string.h>
int static globalStatic = 10;
int const globalConst = 10;
int globalValue = 10;
int *globalPtr;
int globalArray[5] = {0};

int square(int a)
{
    int b = a * a;
    printf("%p of a in function\n", &a);
    printf("%p of b in function\n", &b);
    return b;
}
int main()
{
    int static localStatic = 10;
    int const localConst = 10;
    int localValue = 10;
    int *localPtr;
    int localArray[5] = {0};

    printf("%p of main\n", &main);
    printf("% p of square\n", &square);

    printf("%p of globalStatic\n", &globalStatic);
    printf("%p of globalConst\n", &globalConst);
    printf("%p of globalValue\n", &globalValue);
    printf("%p of *globalPtr\n", &globalPtr);
    printf("%p of globalArray\n", globalArray);

    printf("%p of localStatic\n", &localStatic);
    printf("%p of localConst\n", &localConst);
    printf("%p of localValue\n", &localValue);
    printf("%p of *localPtr\n", &localPtr);
    printf("%p of localArray\n", localArray);

    square(localValue);
    return 0;
}
