{ // O(2) -> O(1)
	int a = 0; // O(1)

	if (a == 2) { // O(1)
		a = 1;
	}
}

for (int i = 0; i < n; i++) { //O(n)
	a[i] = 0;
}

for (int i = 0; i < n; i++) { // O(n^2)
	for (int j = 0; j < n; j++) { //O(n)
		a[i][j] = 0;
	}
}

void f() {
	for (int i = 0; i < n; i++) { // O(n^2) 
		strlen(a[i]); //O(n)
	}
}

f(); //O(n^2)


