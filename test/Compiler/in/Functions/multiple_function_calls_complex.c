int mul (int a, int  b) {
	return a * b;
}

int add (int a, int b) {
	return a + b;
}

int sub (int a, int b) {
	int k = a - b;
	return add(k, a);
}

int main  () {
	int a = 5;
	int b = 11;

	int t = mul (a, b) + add (a, b) + sub (a, b) - 2*add (a, b) + 5;

	return t;
}