void myFree(void **pp){
  if(pp != NULL && *pp != NULL){
    free(*pp);
    *pp = NULL;
  }

  return;
}
  
