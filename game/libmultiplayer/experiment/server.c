#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int listener_d;
void handle_shutdown(int sig){
  if(listener_d){
    close(listener_d);
  }
  printf("Closing down. \n");
  exit(0);
}

int read_in(int d, char* buf, int buflen) {
  int count = recv(d, buf, buflen, 0);
  if (count > 1)
    buf[count - 2] = '\0';
  else
    buf[0] = '\0';
  return count;
}



/* int read_in(int socket, char *buf, int len){ */
/*   char *s = buf;  */
/*   int slen = len; */
/*   int c = recv(socket, s, slen, 0); */

/*   while((c > 0) && (s[c-1] != '\n')){ */
/*     s+=c; slen-=c; */
/*     c = recv(socket, s, slen, 0); */
/*   } */
/*   if(c < 0){ */
/*     return c; */
/*   }else if(c == 0){ */
/*     buf[0] = '\0'; */
/*   }else { */
/*     s[c - 1] = '\0'; */
/*   } */
/*   return len - slen; */
/* } */

int catch_signal(int sig, void (*handler)(int)){
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  return sigaction(sig, &action, NULL);
}

int main(int argc, char *argv[]){
  if(catch_signal(SIGINT, handle_shutdown) == -1){
    perror("Can't set interrupt handler");
  }
  listener_d = socket(PF_INET, SOCK_STREAM, 0);
  
  if(listener_d == -1){
    perror("Can't open the socket");
    exit(1);
  }
  int reuse;
  if(setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *) &reuse, sizeof(int)) == -1){
    perror("Can't set reuse option to the socket");
  }
  
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  int c = bind(listener_d, (struct sockaddr*) &name, sizeof(name));
  
  if(c == -1){
    perror("Can't bind");
    exit(2);
  }

  if(listen(listener_d, 2) == -1){
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
  
    char *msg = "Server says this\n";
    char buf[20];

    bzero(buf, 20);
    int n = read(connect_d, buf, 20);
    
    printf("Bytes read: %d\n%s\n", n, buf);    

    if(send(connect_d, msg, strlen(msg), 0) == -1){
      perror("Can't send data");
      exit(5);
    }
    // read_in(listener_d, buf, 20);
    
    close(connect_d);

  }

  
  return 0;
}  
