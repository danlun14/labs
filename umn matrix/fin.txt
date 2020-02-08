#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *r1;
	int  k = 0, tss = 0, ts = 0, l = 0, st = 0, i = 0, j = 0, symb1 = 0, symb2 = 0, line1 = 0, line2 = 0, st1 = 0, st2 = 0;
	char N[20];
	r1 = fopen("m1.txt", "r");
	while (fscanf(r1, "%d", &st) != EOF){
		symb1++;
		}
	fclose(r1);
	r1 = fopen("m1.txt", "r");
	while (fgets(N, 20, r1) != NULL){
		line1++;
		}
	fclose(r1);
	r1 = fopen("m2.txt", "r");
	while (fscanf(r1, "%d", &st) != EOF){
		symb2++;
		}
	fclose(r1);
	r1 = fopen("m2.txt", "r");
	while (fgets(N, 20, r1) != NULL){
		line2++;
		}
	fclose(r1);
	st1 = symb1 / line1;
	st2 = symb2 / line2;
	printf("%dx", st2);
	printf("%d\n", line1);
	st = line1 * st2;
	int a[symb1], b[symb2], c[st];
	r1 = fopen("m1.txt", "r");
	while (fscanf(r1, "%d", &st) != EOF){
		a[i] = st;
		printf("%3d", a[i]);
		i++;
		}
	fclose(r1);
	printf("\n");
	r1 = fopen("m2.txt", "r");
	while (fscanf(r1, "%d", &st) != EOF){
		b[j] = st;
		printf("%3d", b[j]);
		j++;
		}
	l = 0;
	printf("\n");
	fclose(r1);
	for(i = 0; i < line1; i++){
		for(j = 0; j < st2; j++){
			c[l] = 0;
			tss = j;
			ts =  i * st1;
			for (k = 0; k < st1; k++){
				c[l] = c[l] + a[ts] * b[tss];
				ts = ts + 1;
				tss = tss +  st2;
				}
			printf("%5d", c[l]);
			l++;
			}
		printf("\n");
		}
	}
