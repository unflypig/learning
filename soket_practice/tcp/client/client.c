/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   文件名称：client-3.0.c
*   创 建 者：zt
*   创建日期：2019年07月05日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFF_SIZE 1024

int main(int argc, char* argv[]){
    int client_socket_fd;
    struct sockaddr_in server_addr, client_addr;
    int port;
    int ret;
    char data_buff[BUFF_SIZE] = {0};
    if(argc < 3) {
        printf("Usage:%s ip/hostname port\n");
        return -10000;
    }//endif
    port = atoi(argv[2]);
    client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket_fd < 0) {
        printf("ERROR:creat socket error!\n");
        return -10001;
    }//endif
    //配置将要连接的服务器参数
    memset(&server_addr, 0 , sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    //建立连接
    ret = connect(client_socket_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    if(ret < 0) {
        printf("ERROR:connect to server fail!\n");
        return -10002;
    }//endif
    //输入要发送的数据
    printf("Please input the messenge you want to send:");
    fgets(data_buff, BUFF_SIZE, stdin);
    //发送数据
    ret = write(client_socket_fd, data_buff, strlen(data_buff));
    if(ret < 0) {
        printf("ERROR:write fail!\n");
        return -10003;
    }//endif
    printf("INFO:send messenge [%s] success\n", data_buff);
    //接收数据
    memset(&data_buff, 0, sizeof(data_buff));
    ret = read(client_socket_fd, data_buff, BUFF_SIZE);
    if(ret < 0) {
        printf("ERROR:read fail!\n");
        return -10003;
    }//endif
    printf("INFO:receive messenge success,[%s]", data_buff);
    return 0;
}
