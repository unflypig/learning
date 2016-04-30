#include <stdio.h>

int main()
{
    int fibarry[10]={1,1};
    for (int i=2; i<10; i++)
        fibarry[i] = fibarry[i-1] + fibarry[i-2];
    for (int i=0; i<10; i++)
        printf("fibarry[%d] = %d\n", i, fibarry[i]);

    return 0;
}
