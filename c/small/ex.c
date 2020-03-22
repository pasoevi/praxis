#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int end;                                    //return value of scanf
  int length1;                                //length of string exp1
  char temp;                                  //temp char for input
  char exp1[81];                              //string

  printf ("Please enter in a regular expression:\n");
  end = scanf ("%c", &temp);

  while (temp != '\n' || end == 1) {          //check if end of input
    length1 = check(temp, length1, exp1);    //returns length of exp1

    end = scanf ("%c", &temp);               //scan next char for loop
  }
    return 0;
  
}
