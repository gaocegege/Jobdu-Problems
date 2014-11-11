#include <iostream>
using namespace std;
class InsertSort
{
public:
	InsertSort(int n);
	~InsertSort();
	void set(int i, int num);
	void insert(int num);
	void printResult();
	void printMedian();
private:
	int data[2000000];
	int count;
};

InsertSort::InsertSort(int n)
{
	count = n;
	for (int i = 0; i < 2000000; i++)
		data[i] = 0;
}

InsertSort::~InsertSort(){}

void InsertSort::set(int i, int num)
{
	data[i] = num;
}

void InsertSort::insert(int num)
{
	int i = count - 1;
	for (; i >= 0; i--)
	{
		if (num < data[i])
		{
			data[i + 1] = data[i];
		}
		else
			break;
	}
	data[i + 1] = num;
	count++;
}

void InsertSort::printResult()
{
	for (int i = 0; i < count; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

void InsertSort::printMedian()
{
	int median = 0;
	if (count % 2 == 0)
	{
		median = count / 2 - 1;
	}
	else
	{
		median = count / 2;
	}
	cout << data[median] << endl;
}

int main()
{
	int n,m;
	int numBuf;
	while(cin >> n) 
	{
		InsertSort is = InsertSort(n);
		for (int i = 0; i < n; i++)
		{
			cin >> numBuf;
			is.set(i, numBuf);
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> numBuf;
			is.insert(numBuf);
		}
		// is.printResult();
		is.printMedian();
	}
}