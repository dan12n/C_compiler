int f (int a) {
	int k = 0;

	while (a) {
		a--;
		k+=2;
	}

	return k;
}


int main() {
	int i = f(12);

	if (i == 24) {
		return 0;
	}
	else {
		return 1;
	}
}