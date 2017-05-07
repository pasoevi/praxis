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

int read_in(int d, char *buf, int buflen);
int say(int socket, char *s);
int catch_signal(int sig, void (*handler)(int));
int open_listener_socket();
int bind_to_port(int listener, int port);
