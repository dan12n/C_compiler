int main() {
	int t = 10;
	int y = 5;

	int z = y < t;

	t = 100;
	y = 50;

	int p = t < y;

	return p == z;
}