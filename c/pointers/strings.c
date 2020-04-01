#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 

* Character Strings

This file will be a colloction of small examples to demonstrate the
various ways in which strings can be declared and initialized. Common
string operations will be also shown, such as comparing,copying and
concatenating.

Strings are regularly passed and returned to functions as pointers to
   /char/ or as a pointer to a constant char.

A string is a sequence of characters terminated with the ASCII NUL
character which is represented as \0. Strings are typically stored in
arrays or in memory allocatedfrom the heap. Along with the byte
strings there are also wide strings which are represented as sequence
of wchar_t characters. Functions for manipulating strings of wchar
elements are found in wchar.h.

** Declaring Strings

Strings can be declared as *** String literal Strings literals are
sequences of charatcers enclosed in double quotes. They are often used
to initialize variables. In memory they are stored in the string
literal pool. Character literals are often allocated to read-only
memory.

Some compilers allow string literal midification which isn't
usuallydesired. A way of avoiding this is to declare the string
literal as const.

*** Array of characters
Arrays of characters can be initialized with string literals, too:  

char str[] = "Media Player";
*** A pointer to a character

** Initializing Strings

The memory used for a strinng will be either an arroy or a memory
pointed to by a pointer. When a stringis initialized, we can use a
string literal or a series of characters or obtain the characters from
a different source.

*** Character arrays

Even though a char array can be initialized with a string literal as
it is being declared, an address of the array name cannot be assigned
a string literal. In other words, the following is a perfectly valid
way of initializing a char array:

char someString[] = "Something wicked this way comes"; 

But

char anotherString[]; = "Something wicked this way comes"; 
anotherString = "Something wicked this way comes"; 

is syntaxt error.

*** Pointers to a char

It is typical to initialize a string represented as a pointer to a
char is to use malloc and then strcpy functions:

char *entry = (char *)malloc(strlen("Balance") + 1);
strcpy(entry, "Balance");

When determining the size of the allocated memory for use with malloc,
it is important to use strlen instead of the sizeof operator as the
latter will return the size of an array or pointer.

Many programs operate on text input by the user. When initializing a
pointer to a char used to represent the text specified by the user,
the memory has to be alocated which the given pointer will be
referencing. It is important to design the program in a way that it
does something reasonable when it is given the input text of arbitrary
size.

** Operations on Strings
*** Comparing Strings

C provides a standard way for comparing strings. It is accomplished
using the strcmp function:

strcmp(const char *s1, const char *s2);

strcmp returns 0 if the strings match. -1 if the first string is
lexicographically preceeding the second string or 1 otherwise.

In is incorrect to compare strings using the equality operator. This
doesn't compare the strings but rather the addressed of the string
literals or character arrays, as both, when they are used by
themselves return their addresses.

*** Copying Strings

The standart way of copying strings is using the function /strcpy/

*/

int main(void){
  char str[3] = {'H', 'i', '\0'};
  puts(str);

  char str1[] = "Sergia";
  char str2[] = "Sergia";
  printf("str1(Sergi) %d str2(Sergia)\n", strcmp(str1, str2));
  /* Testing the usage of an uninitialized pointer to a string */
  char *tmpstr;
  char *tmpstr2 = NULL;
  printf("%s\n", tmpstr);

  /* What is wrong with strcat and strcpy 
   
     Passing the buffer's size provides an additional layer of protection. 
   */

  /* Problems with accessing array elements beyond bounds */
  char ar1[8] = "eightb";
  char ar2[4] = "fou";

  ar1[9] = 'k';

  printf("%s %s", ar1, ar2);

  /* Misuse of the sizeof operator 
     sizeof(buffArray) / sizeof(elemType)
   */

  /* Always match pointer types  Understanding and Using C Pointers, page 167 */

  /* Bounded pointers */
  #DEFINE SIZE 32
  char name[SIZE];

  char *p = name;
  if(name != NULL){
    if(p >= name && p < name+SIZE){
      /* Valid pointer, conitue */
    }else{
      /* Possibly terminate the program */
    }
  }

  /* Anonther interesting aproach can be the use of a pointer validation function */
  /* Bounded Model Checking */
  /* Smart pointers in c++ */
  /* String security issues */
  /* http://hackerproof.org */
  /* In is good to never use a user-supplied format string with the
 standard library funcions */
  

    
  

  return 0;
}
