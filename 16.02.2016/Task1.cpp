#include <iostream>
using namespace std;

void RandomArray(int [], int);
void DisplayArray(int[], int);
void Swap(int[], int[]);
void BubbleSort(int [], int);
void SelectionSort(int [], int);
int EnterDimention(int);

int main()
{
	while (true)
	{

		const int N = 100;
		int a[N] = { 0 }, b[N] = { 0 };
		cout << endl << "For the array a: " << endl;
		int n = EnterDimention(N);
		cout << endl << "For the array b: " << endl;
		int m = EnterDimention(N);

		RandomArray(a, n);
		RandomArray(b, m);
		cout << "Source arrays: " << endl;
		DisplayArray(a, n);
		cout << endl;
		DisplayArray(b, m);

		BubbleSort(a, n);
		SelectionSort(b, m);
		
		cout << endl << "Sorted arrays: " << endl;
		DisplayArray(a, n);
		cout << endl;
		DisplayArray(b, m);

		/*for (int *p = a; p <= a + (n+m); p++)
		{
			if (*p > *(p - 1))
			{
				int t = *p;
				*p = *(p-1);
				*(p-1) = t;
			}
		}*/
		cout << endl << "Array C is ";
		for (int *p = a; p < a + (n + m); p++)
			cout << *p << ", ";

		system("pause");
		system("cls");

		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}


void RandomArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 200 - 100;
}
void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ", ";
}
void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void BubbleSort(int a[], int n)
{
	for (int i = 1; i <= n-1; i++)
	for (int j = n - 1; j >= 1; j--)
	if (a[j] < a[j - 1]) Swap(a[j], a[j - 1]);
}
void SelectionSort(int a[], int n)
{
	for (int i = 1; i <= n - 1; i++)
	{
		int min= n - 1;
		for (int j = i - 1; j <= n - 1; j++)
		if (a[j] < a[min])
			min = j;
		Swap(a[i - 1], a[min]);
	}
}

int EnterDimention(int n)
{
	int k;
	while (true)
	{
		cout << "Enter the amount of elements (n <= 100): ";
		cin >> k;
		if (k > 0 && k <= n) return k; //n=N, n=k
		cout << "Error! Try again...";
	}

}
