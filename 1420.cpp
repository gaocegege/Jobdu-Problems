#include <iostream>
#include <memory.h>

#define MAX 5000000

using namespace std;

class Solver
{
public:
	Solver(int size, int* data);
	~Solver();
	// void addData(int fruit);
	void solve();
private:
	int* data;
	int dp[MAX];
	int size;
	/*assistant func*/
	void init();
	int max(int a, int b);
};

Solver::Solver(int size, int* data)
	:size(size), data(data)
{
	init();
}

void Solver::init()
{
	memset(dp, 0, sizeof(int) * MAX);
}

Solver::~Solver()
{
	delete[] data;
}

void Solver::solve()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += data[i];
	}
	int target = sum / 2;

	for (int i = 0; i < size; i++)
	{
        for (int j = target; j >= data[i]; j--)
        {
            dp[j] = max(dp[j], dp[j-data[i]] + data[i]);
        }
    }
    cout << sum - 2 * dp[target] << endl;
}

int Solver::max(int a, int b)
{
	return a > b? a: b;
}

int main()
{
	int size = 0;
	while (cin >> size)
	{
		int* data = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> data[i];
		}
		Solver solver(size, data);
		solver.solve();
	}
}