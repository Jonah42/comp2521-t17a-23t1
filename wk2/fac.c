4! = 4*3*2*1
5! = 5*4*3*2*1
5! = 5*4!


10! = 10*9!

n! = n*(n-1)!

int factorial(int n) {
	// Base case
	if (n == 1)
		return 1;
	// recursion
	int f = n*factorial(n-1);
	return f;
}