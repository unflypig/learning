#include <stdio.h>
#include <pthread.h>
#define STU struct stu 
pthread_t tid[3];
struct stu{
    char *name;
    char *sex;
    float score;
};
struct stu  *stun[3];
void tprocess1(void *data){
    struct stu *stux = (struct stu*)data;
    while(1)
    {
        printf("[%s]-------[%s]------[%f]\n",data.name, data.sex, data.score );
        usleep(100000);    
    }
}
int main(void){
    stun[0].name="Zhangtao0"
    stun[1].name="Zhangtao1"
    stun[2].name="Zhangtao2"

    stun[0].sex="M";
    stun[1].sex="M";
    stun[2].sex="W";

    stun[0].score=88;
    stun[1].score=88.8;
    stun[2].score=88.9;
    STU *pstu = stun;
    for(int i = 0; i < 3 ; i++){
        int ret = pthread_create(&tid[i], NULL, (void *) tprocess1, (void *)pstu++);
        if (ret != 0 ){
            printf("Creat thread error, errorcode[%d]",ret);
            return -1;
        }


    }
    return 0;
}
