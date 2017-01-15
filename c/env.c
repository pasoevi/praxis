#include <stdio.h>
#include <stdlib.h>

#define MSG_VAR_NM "msg"
#define REP_VAR_NM "reps"

#define DEFAULT_REPS 10
#define DEFAULT_MSG "Hello"

int main(){
  char *reptext = getenv(REP_VAR_NM);
  int reps = reptext ? atoi(reptext) : 10;

  char *msg = getenv(MSG_VAR_NM);
  if(!msg){
    msg = DEFAULT_MSG;
  }
  int i;
  for(i = 0; i < reps; i++){
    printf("%s\n", msg);
  }
  return 0;
}
