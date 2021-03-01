#include <iostream>
#include <ctime>
using namespace std;


const int N = 500;
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
	int left = 0, right = size - 1; // лева€ и права€ границы сортируемой области массива
	int flag = 1;  // флаг наличи€ перемещений
	// ¬ыполнение цикла пока лева€ граница не сомкнЄтс€ с правой
	// и пока в массиве имеютс€ перемещени€
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++) //двигаемс€ слева направо
		{
			++C;
			if (arr[i] > arr[i + 1]) // если следующий элемент меньше текущего,
			{             // мен€ем их местами
				swap(arr[i], arr[i + 1]);
				flag = 1;
				++M;	// перемещени€ в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемс€ справа налево
		{
			++C;
			if (arr[i - 1] > arr[i]) // если предыдущий элемент больше текущего,
			{            // мен€ем их местами
				swap(arr[i], arr[i - 1]);
				flag = 1;
				++M;	// перемещени€ в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
	cout << "\n";
	std::cout << "\nPrakti4eskoe kolvo peresilok - " << M << "\n" << "Prakti4eskoe kolvo sravneniy - " << C << "\n";
	printmas(arr, size);
}


int main() {
	// Lab # 1
/*	
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
*/
	

	// Lab # 2
/*
	int Mtr = 3 * (N - 1), Ctr = (N * N - N) / 2;
	SelectSort(a, N);
	cout << "\nTheoreti4eskoe kolvo peresilok M_tr = " << Mtr << "\nTheoriti4eskoe kolvo sravneniy C_tr = " << Ctr;
	cout << "\nSum - " << checksum(a, N);
	cout << "\nRunTime for sorted rand massiv. Sorting Method : Selecting Sort - " << runNumber(a, N) << "\n";
	cout << "\n\n\n";
	fillinc(a, N);
	printmas(a, N);
	cout << "\n";
	SelectSort(a, N);
	cout << "\n\n\n";
	filldec(a, N);
	printmas(a, N);
	cout << "\n";
	SelectSort(a, N);
	cout << "\n\n\n";
*/


	// Lab # 3
/*
	fillrand(a, N);
	printmas(a, N);
	cout << "\n";
	BubleSort(a, N);
	cout << "\n\n\n";
	filldec(a, N);
	printmas(a, N);
	cout << "\n";
	BubleSort(a, N);
	cout << "\n\n\n";
	fillinc(a, N);
	printmas(a, N);
	cout << "\n";
	BubleSort(a, N);
	cout << "\n\n\n";
*/
	cout << "\t\t\tLab #4\n";
	fillinc(a, N);
	printmas(a, N);
	ShakerSort(a, N);
	cout << "\n\n";
	filldec(a, N);
	printmas(a, N);
	ShakerSort(a, N);
	cout << "\n\n";
	fillrand(a, N);
	printmas(a, N);
	ShakerSort(a, N);
	return 0;
}