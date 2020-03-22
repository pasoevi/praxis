#include <stdio.h>
#include "list.h"

int filter(List *lst1, List *lst2,  int (*predicate)(void *)){
  int count = 0;
  
  if(lst1 != NULL && lst2 != NULL){
    if(list_size(lst1) == 0){
      count = 0;
    }
  }else{
    ListElmt el;
    
    for(el = list_head(lst1); list_has_next(lst1); el = list_next(el)){
      if(*predicate(lst1->data)){
	list_ins_next(lst2, list_tail(lst2), list_data(el));
      }
    }
  }
  return 
}
	
      
	  

int main(void){
  /* test here */
  int nums[] = {1, 2, 3};
  filter(nums, isOdd); // {1, 3}
  return 0;
}
  
