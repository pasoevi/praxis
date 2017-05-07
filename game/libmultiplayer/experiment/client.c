#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int say(int socket, char *s){
  int result = send(socket, s, strlen(s), 0);
  if(result == -1){
    perror("Can't talk to the server");
    exit(2);
  }
  return result;
}

int main(int argc, char *argv[]){
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in si;
  memset(&si, 0, sizeof(si));
  si.sin_family = PF_INET;
  //si.sin_addr.s_addr = inet_addr("192.168.0.108");
  si.sin_addr.s_addr = inet_addr("127.0.0.1");
  si.sin_port = htons(30000);
  connect(listener_d, (struct sockaddr*) &si, sizeof(si));
  
  char buf[255]; 

  char buffer[256];
  printf("Please enter the message: ");
  bzero(buffer,256);
  fgets(buffer,255,stdin);
  int n;
  /* Send message to the server */
  n = write(listener_d,buffer,strlen(buffer));
  if (n < 0) 
    {
      perror("ERROR writing to socket");
      exit(1);
    }else{
    printf("%d\n", n);
  }

  
  int bytesRecvd = recv(listener_d, buf, 255, 0);
  while(bytesRecvd){
    if(bytesRecvd == -1){
      perror("Can't read from the server");
      exit(3);
    }
    buf[bytesRecvd] = '\0';
    puts(buf);
    bytesRecvd = recv(listener_d, buf, 255, 0);
  }

  // say(listener_d, "hello\0");

  return 0;
}

