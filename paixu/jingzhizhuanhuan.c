#include<stdio.h>

int main()
{
    int left[128] = {0};
    int num,base;
    int len = 0;
    printf("请输入需要转化的十进制整数,以回车结束！\n");
    scanf("%d", &num);
    printf("请输入需要转换的进制：");
    scanf("%d", &base);
    do{
        left[len] = num % base;
        num = num / base;
        len ++;
    }while (num != 0);
    printf("结果是：");
    for(int i = len-1; i>=0; i--)
        if(left[i] >= 10){
            printf("%c",('A'+ (left[i] - 10)));
        }else{
                printf("%d",left[i]);
        }

    printf("\n");
}
