/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*   
*   文件名称：server-4.0.c
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
    int server_socket_fd;
    int client_socket_fd;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len;
    int server_port;
    int ret;
    char data_buff[BUFF_SIZE] = {0};
    if(argc < 2) {
        printf("Usage:%s port\n", argv[0]);
        return -10000;
    }//endif
    server_port = atoi(argv[1]);
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket_fd < 0) {
        printf("ERROR:creat socket fail!\n");
        return -10001;
    }//endif
    //配置服务器参数
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    //绑定
    ret = bind(server_socket_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
    if(ret < 0) {
        printf("ERROR:bind fail!\n");
        return -10002;
    }//endif
    //监听
    ret = listen(server_socket_fd, 5);
    if(ret  < 0) {
        printf("ERROR:listen fail!\n");
        return -10003;
    }//endif
    //阻塞
    printf("INFO:waiting client send message......\n");
    client_addr_len = sizeof(client_addr);
    client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_addr, &client_addr_len);
    if(client_socket_fd  < 0) {
        printf("ERROR:accept fail!\n");
        return -10004;
    }//endif
    ret = read(client_socket_fd, data_buff, BUFF_SIZE);
    if(ret  < 0) {
        printf("ERROR:read fail!\n");
        return -10005;
    }//endif
    printf("client message is [%s]\n", data_buff);
    ret = write(client_socket_fd, "I got your message!\n", 32);
    if(ret  < 0) {
        printf("ERROR:write fail!\n");
        return -10006;
    }//endif
    printf("INFO:receive and send message success!\n");
    return 0;
}
