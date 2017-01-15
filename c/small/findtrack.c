#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char hammerheart[][80] = {
    "Shores in Flames",
    "Valhalla",
    "Baptized in Fire and Ice",
    "Father to Son",
    "Home of Once Brave",
    "One Rode to Asa Bay"};

  char buffer[80];

  puts("Enter track name to search: ");
  fgets(buffer, 5, stdin);

  char *search_for = malloc(sizeof(char) * strlen(buffer));
  sscanf(buffer, "%s", search_for);

  int i;
  for(i = 0; i < (sizeof(hammerheart)/80); i++)
    {
      if(strstr(hammerheart[i], search_for))
	 puts(hammerheart[i]); 
    
    }

  
  return 0;

}
