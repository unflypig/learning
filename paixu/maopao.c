#include<stdio.h>
int main()
{

    int arr[10] = {9,7,8,5,6,2,4,0,3,1};
    int k = 10;
    int tmp = 0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<k; j++){
            if(arr[j] < arr[j+1])
            {
               tmp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = tmp;
            }
        }
        k--;
    }
    for(int i=0; i<10; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
    return 0;
}
