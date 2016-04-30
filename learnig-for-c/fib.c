#include <stdio.h>

int main()
{
    //斐波那契数列
    int fibarry[10]={1,1};
    for (int i=2; i<10; i++)
        fibarry[i] = fibarry[i-1] + fibarry[i-2];
    for (int i=0; i<10; i++)
        printf("fibarry[%d] = %d\n", i, fibarry[i]);

    //倒序输出
    int arrstart = 0;
    int arrstop = sizeof(fibarry)/sizeof(fibarry[0]) - 1;
    printf("sizeof fibarry = [%d]\n", arrstop);
    int tmp;
    while(arrstart < arrstop)
    {
        tmp = fibarry[arrstop];
        fibarry[arrstop] = fibarry[arrstart];
        fibarry[arrstart] = tmp;
        arrstart ++;
        arrstop --;
    }
    for (int i=0; i<10; i++)
        printf("fibarry[%d] = %d\n", i, fibarry[i]);
    return 0;
}
