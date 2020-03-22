/* Gule sample */

#include <stdio.h>
#include <guile/gh.h>
#include "builtins.h"

#define INPUT_SIZE 200

void main_prog(int argc, char *argv[]);

int main(int argc, char *argv[])
{
  gh_enter(argc, argv, main_prog);
  
  return 0; 
}

void main_prog(int argc, char *argv[])
{
  int done;
  char input_str[INPUT_SIZE];
  gh_new_procedure1_0("factorial", factorial);
  
  fputs("> ", stdout);

  done = 0;

  while(fgets(input_str, INPUT_SIZE - 1, stdin) != NULL)
    {
      gh_eval_str(input_str);
      fputs("\n> ", stdout);
    }

  exit(0);

}
