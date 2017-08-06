int x = 5;
int y = 8;

int r() {
	int y = x + 6;
	x = 6;
}

int main() {
	int z = x + 1;
	x = 4;
	r();
	int t = y * 13;

	return x + t;
}