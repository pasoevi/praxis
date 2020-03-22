#include "multiplayer.h"
#include <time.h>
#include <math.h>

int say(int socket, char *s){
  int result = send(socket, s, strlen(s), 0);
  return result;
}

int read_in(int d, char *buf, int buflen) {
  bzero(buf, buflen);
  int n = read(d, buf, buflen);
  return n;
}

int main(int argc, char *argv[]){
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in si;
  memset(&si, 0, sizeof(si));
  si.sin_family = PF_INET;
  // si.sin_addr.s_addr = inet_addr("192.168.0.108");
  si.sin_addr.s_addr = inet_addr(argv[1]);
  si.sin_port = htons(30001);
  connect(listener_d, (struct sockaddr*) &si, sizeof(si));
  
  srandom(time(NULL));
  while(1){
    char inBuf[255];
    int x = random() % 300;
    sprintf(inBuf, "%d", x);
    // fgets(inBuf, 255, stdin);
    say(listener_d, inBuf);
    
    char buf[255];
    read_in(listener_d, buf, 255);
    puts(buf);
    
  }
  // say(listener_d, "hello\0");
  return 0;
}

