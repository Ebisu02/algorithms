#include <iostream>
#include <ctime>
using namespace std;


void fillinc(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		a[i] = i + 1;
	}
	return;
}

void filldec(int a[], int n) {
	for (int j = n, i = 0; i < n; --j, ++i) {
		a[i] = j;
	}
	return;
}

void fillrand(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 10;
	}
	return;
}

void printmas(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return;
}

int checksum(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
	}
	return sum;
}

int runNumber(int a[], int n) {
	int run = 0;
	for (int i = 0; i < n; ++i) {
		if (i == n - 1) {
			if (a[i] <= a[i - 1]) {
				run++;
			}
		}
		else if (a[i] <= a[i + 1] && i != n - 1) {
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

void SelectSort(int array[], int size) {
	int M = 0, C = 0;
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			++C;
			if (array[j] < array[min]) {
				min = j;
			}
		}
		if (min != i) {
			++M;
			swap(array[i], array[min]);
		}
	}
	printmas(array, size);
	std::cout << "\nPrakti4eskoe kolvo peresilok - " << M << "\n" << "Prakti4eskoe kolvo sravneniy - " << C; 
	return;
}	



int main() {
	const int N = 10;
	int a[N];
	fillinc(a, N);
	printmas(a, N);
	cout << "\nSum - " << checksum(a, N);
	cout << "\nRunTime for inc massiv - " << runNumber(a, N) << "\n";
	cout << "\n\n\n";
	filldec(a, N);
	printmas(a, N);
	cout << "\nSum - " << checksum(a, N);
	cout << "\nRunTime for dec massiv - " << runNumber(a, N) << "\n";
	cout << "\n\n\n";
	fillrand(a, N);
	printmas(a, N);
	cout << "\nSum - " << checksum(a, N);
	cout <<  "\nRunTime for rand massiv - " << runNumber(a, N) << "\n";
	cout << "\n\n\n";
	int Mtr = 3 * (N - 1), Ctr = (N * N - N) / 2;
	SelectSort(a, N);
	cout << "\nTheoreti4eskoe kolvo peresilok M_tr = " << Mtr << "\nTheoriti4eskoe kolvo sravneniy C_tr = " << Ctr;
	cout << "\nSum - " << checksum(a, N);
	cout << "\nRunTime for sorted rand massiv. Sorting Method : Selecting Sort - " << runNumber(a, N) << "\n";
	cout << "\n\n\n";
	return 0;
}