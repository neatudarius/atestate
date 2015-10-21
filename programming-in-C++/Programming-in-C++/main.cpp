#define DATA_LEN 100

int testFunction(int* input, int length)
{
	int sum = 0;

	for (int i = 0; i < length; ++i) {
		sum += input[i];
	}

	return sum;
}

int main()
{
	int random_data[DATA_LEN];

	testFunction(random_data, DATA_LEN);

	return 0;
}