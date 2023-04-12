#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE* fp1 = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "r");
	int num1, num2;
	int eof1, eof2;
	eof1 = fscanf(fp1, "%d", &num1);
	eof2 = fscanf(fp2, "%d", &num2);
	while (eof1 != EOF || eof2 != EOF) {
		if ((num1 <= num2 && eof1 != EOF) || eof2 == EOF) {
			printf("File 1 num is %d\n", num1);
			eof1 = fscanf(fp1, "%d", &num1);
		} else if ((num2 < num1 && eof2 != EOF) || eof1 == EOF) {
			printf("File 2 num is %d\n", num2);
			eof2 = fscanf(fp2, "%d", &num2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}