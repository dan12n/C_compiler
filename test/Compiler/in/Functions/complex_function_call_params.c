int sub(int a, int b) {
	return a -b;
}

int add(int a, int b, int c) {
	return a + b + c;
}

int main () {
	int x = 5;
	int y = 2;

	return add(sub(x, y), x, y);
}