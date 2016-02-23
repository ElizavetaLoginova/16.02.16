#include <iostream>
using namespace std;

int* RandomArray(int);
void DisplayArray(int[], int);
void Swap(int&, int&);
void BubbleSort(int *, int);
void SelectionSort(int *, int);
int* MergeArrays(int*, int, int*, int, int&);

int main()
{
	while (true)
	{
		int n, m;
		while (true)
		{
			cout << endl << "For the array A n= " << endl;
			cin >> n;
			cout << endl << "For the array B m= " << endl;
			cin >> m;
			if (n > 0 && m > 0) break;
			cout << "Error! Try again ";
		}
		int*a = RandomArray(n);
		int*b = RandomArray(m);
		cout << "Source arrays: " << endl;
		DisplayArray(a, n);
		cout << endl;
		DisplayArray(b, m);
		system("cls");

		BubbleSort(a, n);
		SelectionSort(b, m);
		cout << endl << "Sorted arrays: " << endl;
		DisplayArray(a, n);
		cout << endl;
		DisplayArray(b, m);

		cout << endl << "Array C is ";

		int l = 0;
		int *c = MergeArrays(a, n, b, m, l);
		DisplayArray(c, l);
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


int* RandomArray(int n)
{
	int  *a = new int[n];
	for (int* p = a; p < a + n; p++)
		*p = rand() % 200 - 100;
	return a;
}
void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ", ";
}
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void BubbleSort(int *a, int n)
{
	for (int i = 1; i <= n - 1; i++)
	for (int j = n - 1; j >= 1; j--)
	if (*(a + j) < *(a + j - 1)) Swap(a + j, a + j - 1);
}
void SelectionSort(int *a, int n)
{
	for (int i = 1; i <= n - 1; i++)
	{
		int min = n - 1;
		for (int j = i - 1; j <= n - 1; j++)
		if (a[j] < a[min])
			min = j;
		Swap((a+i - 1), (a+min));
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
int *MergeArrays(int *a, int n, int *b, int m, int& l)
{
	l = n + m;
	int *c = new int[l];
	int i = 0, j = 0, k = 0;
	for (; i < n && j < m; k++)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
	}
	if (i == n)
	for (; j < m; j++, k++)
		c[k] = b[j];
	else
	for (; i < n; i++, k++)
		c[k] = a[i];
	return c;
}