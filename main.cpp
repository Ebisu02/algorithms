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

void shellSort(int arr[], int size, int& c, int& moves) {
	int* h;
	h = new int[size];
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

void shellSort(int arr[], int size, int& c, int& moves, int& count) {
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
class Stack {

public:

	Stack();
	~Stack();

	void pop();
	void push(T data);
	int getSize();
	void clear();
	// TODO: 
	void fillInc(int size);
	void fillDec(int size);
	void fillRand(int size);
	void print();
	int checkSum();
	int runNumber();

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
Stack<T>::Stack() {
	Size = 0;
	head = nullptr;
}


template <typename T>
Stack<T>::~Stack() {
	clear();
}

template<typename T>
void Stack<T>::pop()
{
	Node<T>* Temp;
	Temp = head;
	if (Temp != nullptr && Size > 1) {
		head = Temp->pNext;
		delete Temp;
	}
	else {
		delete Temp;
	}
	--Size;
}

template<typename T>
void Stack<T>::push(T data)
{
	Node<T>* Temp;
	Temp = new Node<T>;
	Temp->data = data;
	if (head == nullptr) {
		head = Temp;
	}
	else {
		Temp->pNext = head;
		head = Temp;
	}
	++Size;
}

template<typename T>
void Stack<T>::clear()
{

	while (Size) {
		pop();
	}

}

template<typename T>
int Stack<T>::getSize()
{
	return Size;
}

template<typename T>
void Stack<T>::fillInc(int size)
{
	int count = 0;
	while (count < size) {
		push(count + 1);
		++count;
	}
}

template<typename T>
void Stack<T>::fillDec(int size)
{
	int count = 0;
	while (count < size) {
		push(size - count);
		++count;
	}
}

template<typename T>
void Stack<T>::fillRand(int size)
{
	int count = 0;
	srand(time(nullptr));
	while (count < size) {
		push(rand() % size);
		++count;
	}
}

template<typename T>
void Stack<T>::print()
{
	Node<T>* Temp = head;
	while (Temp) {
		cout << Temp->data << " ";
		Temp = Temp->pNext;
	}
}

template<typename T>
int Stack<T>::checkSum()
{
	int sum = 0;
	Node<T>* Temp = head;
	while (Temp) {
		sum += Temp->data;
		Temp = Temp->pNext;
	}
	return sum;
}

template<typename T>
int Stack<T>::runNumber()
{
	int run = 1;
	Node<T>* Temp = head;
	while (Temp->pNext) {
		if (Temp->data < Temp->pNext->data) {
			++run;
		}
		Temp = Temp->pNext;
	}
	return run;
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
	T data(int index);
	T& operator[](const int index);


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
	Node<T>* tail;
	Node<T>* head;


	void DestroyList(List<T>& list, Node<T>* a, Node<T>* b, int n)
	{
		a = list.head;
		b = list.head->pNext;
		Node<T>* k = a;
		Node<T>* p = b;
		n = 1;
		while (p)
		{
			++n;
			k->pNext = p->pNext;
			k = p;
			p = p->pNext;
		}
	}

	void MergeList(Node<T>* a, int q, Node<T>* b, int r, List<T>& c)
	{
		c.clear();
		while (q > 0&& r > 0)
		{
			if (a->data <= b->data)
			{
				c.push_back(a->data);
				--q;
				a = a->pNext;
			}
			else
			{
				c.push_back(b->data);
				--r;
				b = b->pNext;
			}
		}
		while (q > 0)
		{
			c.push_back(a->data);
			--q;
			a = a->pNext;
		}
		while (r > 0)
		{
			c.push_back(b->data);
			--r;
			b = b->pNext;
		}
	}

	void MergeSort(List<T>& list)
	{
		int n = list.getSize();
		Node<T>* a = head, * b = head->pNext;
		DestroyList(list, a, b, n);
		List<T> c[2];
		int p, q, r, m, i;
		p = 1;
		while (p < n)
		{
			i = 0; 
			m = n;
			while (m > 0)
			{
				if (m >= p)
				{
					q = p;
				}
				else
				{
					q = m;
				}
				m -= q;
				if (m >= p)
				{
					r = p;
				}
				else
				{
					r = m;
				}
				m -= r;
				MergeList(a, q, b, r, c[i]);
				i = 1 - i;
			}
			a = c[0].head;
			b = c[1].head;
			p = 2 * p;
		}
		list = c[0];
	}
};

template <typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
	tail = nullptr;
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
		tail = head;
	}
	else {
		tail->pNext = new Node<T>(data);
		tail = tail->pNext;
		tail->pNext = nullptr;
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
	if (Size > 0) {
		Node<T>* Temp = head;
		while (Temp) {
			cout << Temp->data << " ";
			Temp = Temp->pNext;
		}
	}
	else {
		return;
	}
}

template<typename T>
int List<T>::checkSum()
{
	int sum = 0;
	Node<T>* Temp = head;
	while (Temp) {
		sum += Temp->data;
		Temp = Temp->pNext;
	}
	return sum;
}

template<typename T>
int List<T>::runNumber()
{
	int run = 1;
	Node<T>* Temp = head;
	while (Temp->pNext) {
		if (Temp->data < Temp->pNext->data) {
			++run;
		}
		Temp = Temp->pNext;
	}
	return run;
}

template<typename T>
T List<T>::data(int index)
{
	if (index >= Size || index < 0) {
		return 0;
	}
	if (index == 0)
	{
		return head->data;
	}
	Node<T>* Temp;
	Temp = head;
	int Current = 0;
	while (Temp)
	{
		if (Current == index) {
			return Temp->data;
		}
		Temp = Temp->pNext;
		++Current;
	}
}

template<typename T>
T& List<T>::operator[](const int index) {

	Node<T>* Current = this->head;
	int counter = 0;
	while (Current != nullptr) {			// Пока это не конец списка
		if (counter == index) {				// Если мы попали в нужный элемент списка
			return Current->data;			// Возвращаем данные
		}
		Current = Current->pNext;			// Если не попали, то переходим к следующему
		++counter;							// Увеличиваем индекс на котором мы сейчас находимся на 1
	}
}

// Представим, что список - серия и очередь C пустая по условия
template<typename T>
void MergeSeriesSort(List<T>& a, List<T>& b, List<T>& c) {
	int q = 0;
	int r = 0;
	c.clear();
	while (q < a.getSize() && r < b.getSize()) {
		if (a.data(q) <= b.data(r)) {
			c.push_back(a.data(q));
			++q;
		}
		else {
			c.push_back(b.data(r));
			++r;
		}
	}
	while (q < a.getSize()) {
		c.push_back(a.data(q));
		++q;
	}
	while (r < b.getSize()) {
		c.push_back(b.data(r));
		++r;
	}
	return;
}

void merge(int arr[], int sizeForArr, int L[], int sizeForL, int R[], int sizeForR, int& Moves, int& Compares)
{
	int i = 0;
	int j = 0;
	while (i < sizeForL || j < sizeForR)
	{
		if (i < sizeForL && j < sizeForR)
		{
			++Compares;
			if (L[i] <= R[j])
			{
				Moves += 3;
				arr[i + j] = L[i];
				++i;
			}
			else
			{
				Moves += 3;
				arr[i + j] = R[j];
				++j;
			}
		}
		else if (i < sizeForL)
		{
			arr[i + j] = L[i];
			++i;
		}
		else if (j < sizeForR)
		{
			arr[i + j] = R[j];
			++j;
		}
	}
}

void MergeSort(int arr[], int size, int& Moves, int& Compares)
{
	if (size > 1)
	{
		int middle = size / 2;
		int rem = size - middle;
		int* L = new int[middle];
		int* R = new int[rem];
		for (int i = 0; i < size; ++i)
		{
			if (i < middle)
			{
				L[i] = arr[i];
				Moves += 3;
			}
			else
			{
				R[i - middle] = arr[i];
				Moves += 3;
			}
		}
		MergeSort(L, middle, Moves, Compares);
		MergeSort(R, rem, Moves, Compares);
		merge(arr, size, L, middle, R, rem, Moves, Compares);
	}
}

int GetMax(int arr[], int n, int& Compares)
{
	int mx = arr[0];
	for (int i = 1; i < n; ++i)
	{
		++Compares;
		if (arr[i] > mx)
		{
			mx = arr[i];
		}
	}
	return mx;
}

void CountSort(int arr[], int n, int exp, int& Moves)
{
	int* output = new int [n];
	int i, count[10] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		count[(arr[i] / exp) % 10]++;
	}

	for (int i = 1; i < 10; ++i)
	{
		count[i] += count[i - 1];
	}

	for (i = n - 1; i >= 0; --i)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		Moves += 3;
		--count[(arr[i] / exp) % 10];
	}

	for (int i = 0; i < n; ++i)
	{
		Moves += 3;
		arr[i] = output[i];
	}
}

void DigitalSort(int arr[], int n, int& Moves, int& Compares)
{
	int m = GetMax(arr, n, Compares);

	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		CountSort(arr, n, exp, Moves);
	}
}

int main() {
	List<int> list;
	list.fillDec(10);
	list.print();
	list.MergeSort(list);
	list.print();
	return 0;
}