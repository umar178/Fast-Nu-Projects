#include<stdio.h>
#include<math.h>

int checkPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    if (num % 2 == 0) {
        return 0;
    }

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int** goldBatch(int* numbers, int n, int* totalPairs){
	int** pairs = NULL;
	int* primes;
	int c_index = 0;
	
	pairs = (int**)malloc(sizeof(int*) * n);
	
	for(int i = 0; i < n; i++){
		int l = 0;
        int* primes = (int*)malloc(sizeof(int) * numbers[i]);

        for (int j = 2; j <= numbers[i]; j++) {
            if (checkPrime(j)) {
                primes[l++] = j;
            }
        }
		
		for(int j = 0; j < l; j++){
			for(int k = j; k < l; k++){
				if(primes[j] + primes[k] == numbers[i]){
					pairs = (int**)realloc(pairs, sizeof(int*) * (c_index + 1));
					pairs[c_index] = (int*)malloc(sizeof(int) * 2);
					pairs[c_index][0] = primes[j]; 
					pairs[c_index][1] = primes[k];
					c_index++;
				}
			}
		}
		free(primes);
	}
	
	*totalPairs = c_index;
	return pairs;
}

main(){
	int *arr = NULL;
	int n = 0;
	int i;
	
	while (1) {
        printf("Enter element %d: ", n + 1);
        scanf("%d", &i);

        if (i == -1) {
            break;
        }
        
        arr = (int*)realloc(arr, sizeof(int) * (n + 1));
        arr[n] = i;
        n++;
    }
	
	printf("\n");
	
	for(int i = 0; i < n; i++){
		printf("Element %d: %d\n ", i, arr[i]);
	}
	
	printf("\n");
	
	int totalPairs;

    int** pairs = goldBatch(arr, n, &totalPairs);
	
	for (int i = 0; i < totalPairs; i++) {
        printf("(%d, %d), ", pairs[i][0], pairs[i][1]);
        free(pairs[i]);
    }
    
    free(pairs);
}