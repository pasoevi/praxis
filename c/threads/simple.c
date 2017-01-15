#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 4

typedef struct {
  double *vectorA;
  double *vectorB;
  double sum;
  int length;
} VectorInfo;

typedef struct {
  VectorInfo *info;
  int beginningIndex;
} Product;

pthread_mutex_t mutexSum;

void dotProduct(void *prod){
  Product *product = (Product*)prod;
  VectorInfo *vectorInfo = product->info;
  int beginningIndex = product->beginningIndex;
  int endingIndex = beginningIndex + vectorInfo->length;
  double total = 0;

  int i;
  for(i = beginningIndex; i < endingIndex; i++){
    total += (vectorInfo->vectorA[i] * vectorInfo->vectorB[i]);
  }

  pthread_mutex_lock(&mutexSum);
  vectorInfo->sum+=total;
  pthread_mutex_unlock(&mutexSum);

  pthread_exit((void*)0);
}



void threadExample(){
  VectorInfo vectorInfo;
  double vectorA[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
		      9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
  double vectorB[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
		      9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};

  double sum;
  vectorInfo.vectorA = vectorA;
  vectorInfo.vectorB = vectorB;

  vectorInfo.length = 4;

  pthread_t threads[NUM_THREADS];

  void *status;
  pthread_attr_t attr;

  pthread_mutex_init(&mutexSum, NULL);
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  int returnValue;
  int threadNumber;

  for(threadNumber = 0; threadNumber < NUM_THREADS; threadNumber++){
    Product *product = (Product*)malloc(sizeof(Product));
    product->beginningIndex = threadNumber * 4;
    product->info = &vectorInfo;
    returnValue = pthread_create(&threads[threadNumber], &attr,
				 (void *) dotProduct, (void *)(product));
    if(returnValue){
      printf("ERROR: unable to create thread: %d\n", returnValue);
      exit(-1);
    }
  }

  pthread_attr_destroy(&attr);

  int i;
  for(i = 0; i < NUM_THREADS; i++){
    pthread_join(threads[i], &status);
  }

  pthread_mutex_destroy(&mutexSum);
  printf("Dot Product sum: %lf\n", vectorInfo.sum);
  pthread_exit(NULL);
}
	     
  
int main(void){
  threadExample();
  return 0;
}
