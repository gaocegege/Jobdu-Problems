#include <iostream>

using namespace std;

class DP
{
public:
	DP(int size, int *V, int *S, int C);
	~DP();
	void solve();

private:
	void init();
	int myMax(int a, int b);
	int *V;
	int *S;
	int C;
	int size;
	int *max;
};

DP::DP(int size, int *V, int *S, int C)
	:size(size), V(V), S(S), C(C)
{
	init();
}

DP::~DP()
{
	delete[] V;
	delete[] S;
}

void DP::init()
{
	max = new int[C + 1];
	for (int i = 0; i <= C; i++)
		max[i] = 0;
}

int DP::myMax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void DP::solve()
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = C; j >= S[i]; j--)
		{
			max[j] = myMax(max[j], max[j - S[i]] + V[i]);
		}
	}
	cout << max[C] << endl;
}

int main()
{
	int C;
	while (cin >> C)
	{
		int size = 0;
		cin >> size;
		int *V = new int[size + 1];
		int *S = new int[size + 1];
		for (int i = 1; i <= size; i++)
		{
			cin >> S[i] >> V[i];
		}
		DP dpInstance = DP(size, V, S, C);
		dpInstance.solve();
	}
}