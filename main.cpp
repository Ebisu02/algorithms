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
		arr[i] = rand() % size;
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
 
void make_heap(int arr[], int n, int i, int& move, int& compare)
{
	// Функция чтобы скопировать поддерево с корневым узлом i,
	// которая является индексом в массиве arr[].
	// n - размер дерева
	int largest = i; // Задаем наибольший как корень дерева
	int left = 2 * i + 1; // Левый = 2 * i + 1
	int right = 2 * i + 2; // Правый = 2 * i + 2

	// Если левый ребенок больше, чем корень
	if (left < n && arr[left] > arr[largest]) {
		++compare;
		largest = left;
	}

	// Если правый ребенок на данный момент больше самого большого
	if (right < n && arr[right] > arr[largest]) {
		++compare;
		largest = right;
	}

	// Если наибольший не корень
	if (largest != i) {
		++compare;
		swap(arr[i], arr[largest]);
		++move;
		// Рекурсивно скопируем поддерево
		make_heap(arr, n, largest, move, compare);
	}
}

void heapSort(int arr[], int n, int& move, int& compare)
{
	// Строим дерево
	for (int i = n / 2 - 1; i >= 0; i--) {
		make_heap(arr, n, i, move, compare);
	}

	// Один за другим извлекаем элемент из дерева
	for (int i = n - 1; i > 0; i--) {
		// Перемещаем текущий элемент корень в конец
		swap(arr[0], arr[i]);
		++move;
		// Вызываем построение новой кучи 
		make_heap(arr, i, 0, move, compare);
	}
}

void Heap(int arr[], int size, int left, int right, int& move, int& compare) {
	int x = arr[left];
	int i = left;
	while (1) {
		int j = 2 * i;
		if (++compare && j > right) {
			break;
		}
		if (++compare && (j < right) && (arr[j + 1] <= arr[j])) {
			++j;
		}
		if (++compare && x <= arr[j]) {
			break;
		}
		arr[i] = arr[j];
		++move;
		i = j;
	}
	arr[i] = x;
}

void HeapSort(int arr[], int size, int& move, int& compare) {
	int left = (size / 2);
	while (left >= 0) {
		Heap(arr, size, left, size, move, compare);
		--left;
	}
	int right = size;
	while (right >= 1) {
		swap(arr[0], arr[right]);
		move += 3;
		--right;
		Heap(arr, size, 0, right, move, compare);
	}
	return;
}

void QuickSortOne(int arr[], int size, int left, int& move, int& compare) {
	int right = size;
	int x = arr[left];
	int i = left;
	int j = right;
	while (++compare && i <= j) {
		while (++compare && arr[i] < x) {
			++i;
		}
		while (++compare && arr[j] > x) {
			--j;
		}
		if (++compare && i <= j) {
			swap(arr[i], arr[j]);
			move += 3;
			++i;
			--j;
		}
	}
	if (++compare && left < j) {
		QuickSortOne(arr, j, left, move, compare);
	}
	if (++compare && i < right) {
		QuickSortOne(arr, right, i, move, compare);
	}
	return;
}

template <typename T>
class List {

public:

	List();
	~List();

	void pop_front();
	void push_back(T data);
	int getSize();
	void clear();
	// TODO: 
	void fillInc(int size);
	void fillDec(int size);
	void fillRand(int size);
	void print();
	int checkSum();
	int runNumber();

	T& operator[](const int index);

private:

	template <typename T>
	class Node {

	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = NULL) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};

template <typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}


template <typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* Temp = head;
	head = head->pNext;
	delete Temp;
	--Size;
}

template<typename T>
void List<T>::push_back(T data)
{

	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* Current = this->head;

		while (Current->pNext != nullptr) {
			Current = Current->pNext;
		}

		Current->pNext = new Node<T>(data);

	}

	++Size;
}

template<typename T>
void List<T>::clear()
{

	while (Size) { // ���� Size > 0
		pop_front();
	}

}

template<typename T>
int List<T>::getSize()
{
	return Size;
}

template<typename T>
void List<T>::fillInc(int size) 
{
	int count = 0;
	while (count < size) {
		push_back(count + 1);
		++count;
	}
}

template<typename T>
void List<T>::fillDec(int size)
{
	int count = 0;
	while (count < size) {
		push_back(size - count);
		++count;
	}
}

template<typename T>
void List<T>::fillRand(int size)
{
	int count = 0; 
	srand(time(nullptr));
	while (count < size) {
		push_back(rand() % size);
		++count;
	}
}

template<typename T>
void List<T>::print()
{
	Node<T>* Current;
	Current = this->head;
	int count = 0;
	while (count < size && Current->pNext != nullptr) {
		cout << Current->data;
		Current = Current->pNext;
		++count;
	}
}

int main() {

	return 0;
}
