int main() {
	int n = 10;
	int x = 5;

	if (x < 6) {
		n = 5;
	}

	{ int n = 11;
		{ int n = 30;
			{
				int n = 50;
			}
		}
	}

	return n;
}