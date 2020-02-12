#include <stdio.h>
int main(){
    long int size = 800000000;
    int a = 0, b = -1, n = 20;
    printf("1234567890");
    for (long int i = 0; i <= size; i++){
	a = (int)( i / (size / n));
	if (a != b){
	    for (int j = 0; j < n; j++){
		printf("\b");
		}
	    b = a;
	    for (int j = 0; j < a; j++){
		printf("#");
		}
	    
	    for (int j = a; j < n; j++){
		printf("_");
	    }
	}
    }
}