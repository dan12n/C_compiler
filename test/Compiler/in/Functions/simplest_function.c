int zz() {
	int h = 5;
	int k = 8;
	int z = h + k;
}

int kk() {
	int x = 5;
	int y = 8;
	zz();
}

int main() {
	int a = 3;
	int b = 5;
	int c = 8;
	zz();
	kk();
	int t = 5;
}