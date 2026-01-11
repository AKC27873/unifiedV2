#include "port.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_ports(){
  for (int port = 1; port <= 1024; port++){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if  (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == 0){
      printf("[PORT] Open: %d\n", port);
    }
    close(sock);
  }
}

