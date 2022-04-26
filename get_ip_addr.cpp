/* 
    利用程序实现，查询并输出本机的名称及IP地址。
 */

#include <iostream>
#include <cstdio>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{   
    std::cout << "start..." << std::endl;
    WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

    char pc_name[50];
    
    
    gethostname(pc_name, 50);
    std::cout << "pc_name:" << pc_name << std::endl;

    struct hostent *host = gethostbyname(pc_name);
    
    for(int i=0; host->h_addr_list[i]; i++){
        printf("IP addr %d: %s\n", i+1, inet_ntoa( *(struct in_addr*)host->h_addr_list[i] ) );
    }




    std::cout << "over!" << std::endl;
    system("pause");
    return 0;
}