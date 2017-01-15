#include <stdio.h>

int main(){
	int n = 0;
	scanf("%d", &n);

	int numPos = 0, numNeg = 0, numZero = 0;

	int tmp, i;
	for(i = 0; i < n; i++){
		scanf("%d", &tmp);
		if(tmp > 0){
			numPos++;
		}else if(tmp < 0){
			numNeg++;
		}else{
			numZero++;
		}
	}

	if(numPos > 0){
		printf("%.3f\n", (float)numPos / (float)n);
	}

	if(numNeg > 0){
		printf("%.3f\n", (float)numNeg / (float)n);
	}

	if(numZero > 0){
		printf("%.3f\n",(float)numZero / (float)n);
	}

	return 0;
}
