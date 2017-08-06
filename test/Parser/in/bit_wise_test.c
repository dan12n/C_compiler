int two() {
	b = a & c;
}

int three() {
	b = a & C | d;
}

int nested() {
	d = a & (a | b & (d | e));
}

int xor_test() {
	f = x ^ y;
}

int x() {
	return 10+((a&b)|c);
}