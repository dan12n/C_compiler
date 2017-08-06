int main () {
	int i, size = 10, sum, pos, neg;
	
	int arr[10] = {12, -1, 8, 0, 6, 85, -74, 23, 99, -30};

	sum = 0; pos = 0; neg = 0;
	for (i = 0; i < size; i++) {
		sum += arr[i];
		if (arr[i] > 0)
			pos += arr[i];
		if (arr[i] < 0)
			neg += arr[i];
	}
	return 0;
}