#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void error(const char *msg){
  fprintf(stderr, "%s\n", msg);
}
int main(int argc, char *argv[]){
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);

  if(listener_d == -1){
    error("Can't open socket!");
  }

  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t) htons(3000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  int c = bind(listener_d, (struct sockaddr *) &name, sizeof(name));

  if(c == -1){
    error("Can't bind to socket!");
  }

  if(listen(listener_d, 10) == -1){
    error("Can't listen");
  }

  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof(client_addr);
  int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
  if(connect_d == -1){
    error("Can't open secondary socket!");
  }

  char *msg = "I'm here\n";
  if(send(connect_d, msg, strlen(msg), 0) == -1){
    error("can't send data");
  }
  return 0;
}
