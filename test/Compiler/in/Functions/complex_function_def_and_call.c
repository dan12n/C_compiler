int zz(int a,int b,int c) {
	return a + b  - c;
}

int main() {
	int a = 3;
	int b = 5;
	int c = 13;
	int k = zz(a, b, c);
	int t = a + b + c;
	return k + t;
}