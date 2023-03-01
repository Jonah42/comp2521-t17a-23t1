#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void palindrome(char* string) { //O(n)
	int i = 0; // O(1)
	int j = strlen(string) - 1; // O(n)
	bool p = true;
	while (i <= j) { // O(n)
		if (string[i] != string[j]) {
			p = false;
			break;
		}
		i++;
		j--;
	}
	printf(p ? "yes\n" : "no\n"); // O(1)
}

int main(int argc, char **argv) {
	palindrome(argv[1]);
	return 0;
}
