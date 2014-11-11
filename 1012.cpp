#include <iostream>
using namespace std;
class UF
{
public:
	UF(int n);
	~UF();
	int findRoot(int p);
	bool connected(int p, int q);
	void quickFindUnion(int p, int q);
	int calculate();
	void printResult();
private:
	int* id;
	int* sz;
	int* isIn;
	int count;
};

UF::UF(int n)
{
	id = new int[n+1];
	sz = new int[n+1];
	isIn = new int[n + 1];
	count = n + 1;
	for (int i = 0; i < count; i++)
	{
		id[i] = i;
		sz[i] = 1;
		isIn[i] = 1;
	}
}

UF::~UF()
{
}

int UF::findRoot(int p)
{
	while (id[p] != p)
	{
		p = id[p];
	}
	return p;
}

bool UF::connected(int p, int q)
{
	//cout << findRoot(p) << findRoot(q) << endl;
	if (findRoot(p) == findRoot(q))
		return true;
	else
		return false;
}

void UF::quickFindUnion(int p, int q)
{
	int rootp = findRoot(p);
	int rootq = findRoot(q);
	//cout << rootp << rootq << endl;
	/*id[rootq] = id[rootp];
	sz[rootp] = sz[rootp] + sz[rootq];*/
	if (sz[rootp] > sz[rootq])
	{
		id[rootq] = id[rootp];
		sz[rootp] = sz[rootp] + sz[rootq];
		//sz[rootq] = 0;
		isIn[rootp] = 0;
		isIn[rootq] = 0;
	}
	else
	{
		id[rootp] = id[rootq];
		sz[rootq] = sz[rootq] + sz[rootp];
		//sz[rootp] = 0;
		isIn[rootp] = 0;
		isIn[rootq] = 0;
	}
}

void UF::printResult()
{
	cout << "The result of the union:\n";
	for (int i = 1; i < count; i++)
	{
		cout << id[i] << " ";
	}
	cout << "\n";
	cout << "The size of the union\n";
	for (int i = 1; i < count; i++)
	{
		cout << sz[i] << " ";
	}
	cout << "\n";
	cout << "The  of the union\n";
	for (int i = 1; i < count; i++)
	{
		cout << isIn[i] << " ";
	}
	cout << "\n";
}

int UF::calculate()
{
	int num = 0;
	for (int i = 1; i < count; i++)
	{
		if (isIn[i] == 0)
			num++;
	}
}

int main()
{
	int n = 0, m = 0;
	int p = 0, q = 0;
	while (cin>>n)
	{
		if (n == 0)
			break;
		cin >> m;
		int buf = 0;
		UF qfind(n);
		for (int i = 0; i < m; i++)
		{
			cin >> p >> q;
			if (qfind.connected(p, q) == false)
			{
				qfind.quickFindUnion(p, q);
				buf++;
			}
			//qfind.printResult();
		}
		cout << n - buf - 1 << endl;

	}
	//system("pause");
	return 0;
}