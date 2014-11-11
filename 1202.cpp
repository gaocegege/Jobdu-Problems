#include <iostream>
using namespace std;
/*QuickSort
Coder:Gao Ce
*/
class QuickSort
{
public:
	QuickSort(int n);
	~QuickSort();
	void set(int i, int num);
	int partition(int begin, int end);
	void quickSort(int begin, int end);
	void printResult();
private:
	int count;
	int* data;
};

QuickSort::QuickSort(int n)
{
	data = new int[n];
	count = n;
	for (int i = 0; i < n; i++)
		data[i] = 0;
}

QuickSort::~QuickSort()
{
}

void QuickSort::set(int i,int num)
{
	data[i] = num;
}

int QuickSort::partition(int begin, int end)
{
	int i = begin;
	int j = end;
	int buf = data[begin];
	while (i < j)
	{
		/*find the position where data < buf*/
		while (i < j && data[j] >= buf)
			j--;
		if (i < j)
		{
			/*save the data[j] at pos i*/
			data[i] = data[j];
			i++;
		}
		/*now J is a hole*/
		while (i < j && data[i] < buf)
			i++;
		if (i < j)
		{
			data[j] = data[i];
			j--;
		}
		/*now I is a hole*/
	}

	//cout << "HEHE " + i << endl;
	/*now i == j*/
	data[i] = buf;

	return i;
}

void QuickSort::quickSort(int begin, int end)
{
	int k = partition(begin, end);
	//cout << "k = " + k << endl;
	if (k - 1 >= begin)
		quickSort(begin, k - 1);
	if (k + 1 <= end)
		quickSort(k + 1, end);
}

void QuickSort::printResult()
{
	cout << data[0] << " ";
	for (int i = 1; i < count; i++)
	{
		//if (data[i] != data[i - 1])
			cout << data[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int n = 0;
	int buf = 0;
	while (cin >> n)
	{
		QuickSort quickSort(n);
		for (int i = 0; i < n; i++)
		{
			cin >> buf;
			//cout << i << buf << endl;
			quickSort.set(i, buf);
		}
		quickSort.quickSort(0, n - 1);
		quickSort.printResult();
	}
	return 0;
}