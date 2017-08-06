int main() {
	int t = 10;
	int y = 100;

	int z = y >= t;

	t = 100;
	y = 100;

	int p = t <= y;

	return p >= z;
}