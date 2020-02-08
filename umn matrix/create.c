#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	FILE *o1;
	int temp, x, y, x1, y1;
	const time_t t = time(NULL);
	printf("%s\n", ctime(&t));
	printf("введите количество столбцов и строк соответствено через пробел:\n");
	scanf("%d %d", &x, &y);
	printf("введите количество стобцов и строк во второй умножаемой матрицы\n");
	scanf("%d %d", &x1, &y1);
	o1 = fopen("m1.txt", "w");
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			printf("x:%2d  y:%2d\n", i, j);
			scanf("%d", &temp);
			fprintf(o1, "%4d", temp);
			}
		fprintf(o1, "\n");
		}
	fclose(o1);
	o1 = fopen("m2.txt", "w");
	for(int i = 0; i < y1; i++){
		for(int j = 0; j < x1; j++){
			printf("x:%2d  y:%2d\n", i, j);
			scanf("%d", &temp);
			fprintf(o1, "%4d", temp);
			}
		fprintf(o1, "\n");
		}
	fclose(o1);
	o1 = fopen("log.txt", "w");
	fprintf(o1, "created: %s\n", ctime(&t));
	}
