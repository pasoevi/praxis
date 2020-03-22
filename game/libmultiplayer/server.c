#include "multiplayer.h"

#define DEFAULT_PORT 30001

int listener_d;
void handle_shutdown(int sig){
  if(listener_d){
    close(listener_d);
  }
  printf("Closing down. \n");
  exit(0);
}

int read_in(int d, char *buf, int buflen) {
  bzero(buf, buflen);
  int n = read(d, buf, buflen);
  return n;
}

int say(int socket, char *s){
  int result = send(socket, s, strlen(s), 0);
  return result;
}

int catch_signal(int sig, void (*handler)(int)){
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  return sigaction(sig, &action, NULL);
}

int open_listener_socket(){
  return socket(PF_INET, SOCK_STREAM, 0);
}  

int bind_to_port(int listener, int port){
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30001);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  
  int reuse;
  if(setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *) &reuse, sizeof(int)) == -1){
    perror("Can't set reuse option to the socket");
  }

  int c = bind(listener_d, (struct sockaddr*) &name, sizeof(name));
  return c;
}

int main(int argc, char *argv[]){
  if(catch_signal(SIGINT, handle_shutdown) == -1){
    perror("Can't set interrupt handler");
  }

  int port = argc == 2 ? strtol(argv[1], NULL, 10) : DEFAULT_PORT;
  
  listener_d = open_listener_socket();
  
  if(listener_d == -1){
    perror("Can't open the socket");
    exit(1);
  }
  
  
  
  if(bind_to_port(listener_d, port) == -1){
    perror("Can't bind");
    exit(2);
  }

  if(listen(listener_d, 1) == -1){
    perror("Can't listen");
    exit(3);
  }

  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof(client_addr);
  while(1){
    int connect_d = accept(listener_d, (struct sockaddr*) &client_addr, &address_size);
    if(connect_d == -1){
      perror("Can't open secondary socked");
      exit(4);
    }
    
    while(1){
      char buf[255];
      read_in(connect_d, buf, 255);
      say(connect_d, "sandro");
      puts(buf);
    }
    // read_in(listener_d, buf, 20);
    close(connect_d);
  }

  return 0;
}  
