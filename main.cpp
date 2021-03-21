#include <iostream>
#include <ctime>
using namespace std;


const int N = 10;
int a[N];

void fillinc(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = i + 1;
	}
	return;
}

void filldec(int arr[], int size) {
	for (int j = size, i = 0; i < size; --j, ++i) {
		arr[i] = j;
	}
	return;
}

void fillrand(int arr[], int size) {
	srand(time(NULL));
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 1000;
	}
	return;
}

void printmas(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	return;
}

int checksum(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}

int runNumber(int arr[], int size) {
	int run = 0;
	for (int i = 0; i < size; ++i) {
		if (i == size - 1) {
			if (arr[i] <= arr[i - 1]) {
				run++;
			}
		}
		else if (arr[i] <= arr[i + 1] && i != size - 1) {
			continue;
		}
		else {
			++run;
			continue;
		}
	}
	if (run == 0) {
		++run;
	}
	return run;
}

void SelectSort(int arr[], int size) {
	int M = 0, C = 0;
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			++C;
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) {
			++M;
			swap(arr[i], arr[min]);
		}
	}
	printmas(arr, size);
	std::cout << "\nPrakti4eskoe kolvo peresilok - " << 3 * M << "\n" << "Prakti4eskoe kolvo sravneniy - " << C;
	return;
}


void BubleSort(int arr[], int size) {
	int M = 0; int C = 0;
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++) {
			++C;
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				++M;
			}
		}
	printmas(arr, size);
	std::cout << "\nPrakti4eskoe kolvo peresilok - " << M << "\n" << "Prakti4eskoe kolvo sravneniy - " << C;
	return;
}


void SelectSortFromLesson(int arr[], int size) {
	int j, zm, num, c = 0, m = 0;
	for (int i = 0; i < size; i++) {
		num = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[num]) {
				num = j;
			}
			c++;
		}
		zm = arr[num];
		arr[num] = arr[i];
		arr[i] = zm;
		++m;
	}
	printf("C - %d\t", c);
	printf("M - %d\n", m);
}

void ShakerSort(int* arr, int size)
{
	int M = 0, C = 0;
	int left = 0, right = size - 1; // ëåâàÿ è ïðàâàÿ ãðàíèöû ñîðòèðóåìîé îáëàñòè ìàññèâà
	int flag = 1;  // ôëàã íàëè÷èÿ ïåðåìåùåíèé
	// Âûïîëíåíèå öèêëà ïîêà ëåâàÿ ãðàíèöà íå ñîìêí¸òñÿ ñ ïðàâîé
	// è ïîêà â ìàññèâå èìåþòñÿ ïåðåìåùåíèÿ
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++) //äâèãàåìñÿ ñëåâà íàïðàâî
		{
			++C;
			if (arr[i] > arr[i + 1]) // åñëè ñëåäóþùèé ýëåìåíò ìåíüøå òåêóùåãî,
			{             // ìåíÿåì èõ ìåñòàìè
				swap(arr[i], arr[i + 1]);
				flag = 1;
				++M;	// ïåðåìåùåíèÿ â ýòîì öèêëå áûëè
			}
		}
		right--; // ñäâèãàåì ïðàâóþ ãðàíèöó íà ïðåäûäóùèé ýëåìåíò
		for (int i = right; i > left; i--)  //äâèãàåìñÿ ñïðàâà íàëåâî
		{
			++C;
			if (arr[i - 1] > arr[i]) // åñëè ïðåäûäóùèé ýëåìåíò áîëüøå òåêóùåãî,
			{            // ìåíÿåì èõ ìåñòàìè
				swap(arr[i], arr[i - 1]);
				flag = 1;
				++M;	// ïåðåìåùåíèÿ â ýòîì öèêëå áûëè
			}
		}
		left++; // ñäâèãàåì ëåâóþ ãðàíèöó íà ñëåäóþùèé ýëåìåíò
	}
}

void insertSort(int arr[], int size, int& c, int& m) {
	for (int i = 1; i < size; i++)
	{
		++c;
		int buf = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > buf)
		{
			++c;
			arr[j + 1] = arr[j];
			j = j - 1;
			++m;
		}
		arr[j + 1] = buf;
		m += 2;
	}
	return;
}

void shellSort(int arr[], int size, int& c, int &moves) {
	int* h;
	h = new int [size];
	int k, t, j;
	int m = log(size) / log(2) - 1;
	h[0] = 1;
	cout << "\nSteps: \n";
	for (int i = 1; i < m; ++i) {
		h[i] = 2 * h[i - 1] + 1;
	}
	for (; m >= 1; --m) {
		k = h[m - 1];
		cout << k << " ";
		for (int i = k; i < size; i++) {
			t = a[i];
			for (j = i - k, c++; j >= 0 and t < a[j]; j = j - k, c++) {
				a[j + k] = a[j];
			}
			a[j + k] = t;
			moves += 3;
		}
	}
	cout << "\n";
	return;
}

void shellSort(int arr[], int size) {
	int* h;
	h = new int[size];
	int k, t, j;
	int m = log(size) / log(2) - 1;
	h[0] = 1;
	for (int i = 1; i < m; ++i) {
		h[i] = 2 * h[i - 1] + 1;
	}
	for (; m >= 1; --m) {
		k = h[m - 1];
		for (int i = k; i < size; i++) {
			t = a[i];
			for (j = i - k; j >= 0 and t < a[j]; j = j - k) {
				a[j + k] = a[j];
			}
			a[j + k] = t;
		}
	}
	cout << "\n";
	return;
}

void shellSort(int arr[], int size, int& c, int& moves, int &count) {
	int* h;
	h = new int[size];
	int k, t, j;
	int m = log(size) / log(2) - 1;
	h[0] = 1;
	for (int i = 1; i < m; ++i) {
		h[i] = 2 * h[i - 1] + 1;
	}
	for (count = 0; m >= 1; --m, ++count) {
		k = h[m - 1];
		for (int i = k; i < size; i++) {
			t = a[i];
			for (j = i - k, c++; j >= 0 and t < a[j]; j = j - k, c++) {
				a[j + k] = a[j];
			}
			a[j + k] = t;
			moves += 3;
		}
	}
	return;
}
void shellSort_adv(int arr[], int size, int& c, int& moves, int& count) {
	count = -1;
	for (int i = size / 2; i > 0; i /= 2, ++count)
	{
		for (int j = i; j < size; j += 1)
		{
			int temp = arr[j];
			int z;
			for (z = j, ++c; z >= i && arr[z - i] > temp; z -= i, ++c) {
				arr[z] = arr[z - i];
			}
			arr[z] = temp;
			moves += 3;
		}
	}
	return;
}

int bin_find(int arr[], int size, int key) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int bin_find(int arr[], int size, int key, int& c) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == key && ++c) {
			return mid;
		}
		if (arr[mid] < key && ++c) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int bin_find_mod(int arr[], int size, int key) {
	int left = 0; 
	int right = size - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
		if (arr[right] == key) {
			return right;
		}
	}
	return -1;
}

int bin_find_mod(int arr[], int size, int key, int& c) {
	int left = 0;
	int right = size - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] < key && ++c) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
		if (arr[right] == key && ++c) {
			return right;
		}
	}
	return -1;
}

int main() {
	// Lab 7
	fillinc(a, N);
	printmas(a, N);
	int key = 10;
	cout << "\nThis key under index = " << bin_find(a, N, key) << "\n";
	filldec(a, N);
	printmas(a, N);
	shellSort(a, N);
	printmas(a, N);
	cout << "\nThis key under index = " << bin_find(a, N, key) << "\n";
	fillrand(a, N);
	printmas(a, N);
	shellSort(a, N);
	printmas(a, N);
	cout << "\nThis key under index = " << bin_find(a, N, key) << "\n";
	cout << "\n\n";
	fillinc(a, N);
	printmas(a, N);
	cout << "\nThis key under index = " << bin_find_mod(a, N, key) << "\n";
	filldec(a, N);
	printmas(a, N);
	shellSort(a, N);
	printmas(a, N);
	cout << "\nThis key under index = " << bin_find_mod(a, N, key) << "\n";
	fillrand(a, N);
	printmas(a, N);
	shellSort(a, N);
	printmas(a, N);
	cout << "\nThis key under index = " << bin_find_mod(a, N, key) << "\n";

	// Table 1 
	cout << "\n\n\tTable #1";
	cout << "\nSize|C_1|C_2";
	key = 67;
	for (int i = 100; i < 1001; i += 100) {
		int* arr;
		arr = new int[i];
		int c_1 = 0,
			c_2 = 0;
		fillrand(arr, i);
		ShakerSort(arr, i);
		bin_find(arr, i, key, c_1);
		bin_find_mod(arr, i, key, c_2);
		cout << "\n" << i << "|" << c_1 << "|" << c_2;
	}
	return 0;
}
