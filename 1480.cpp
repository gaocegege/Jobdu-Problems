#include <iostream>

using namespace std;

class DP
{
public:
	DP(int *data, int size);
	~DP();
	void solve();

private:
	int *data;
	int size;
	int *dp;
};

DP::DP(int *data, int size)
	:data(data), size(size)
{
	dp = new int[size + 1];
	for (int i = 0; i <= size; i++)
		dp[i] = 0;
}

DP::~DP()
{
	delete[] dp;
	delete[] data;
}
// dp[i] = max(dp[j]) + data[i], 1 <= j < i, 且data[j] < data[i]
void DP::solve()
{
	dp[1] = data[1];

	for (int i = 1; i <= size; i++)
	{
		// to carry the situation like this-> 5 4 3 2 1;
		dp[i] = data[i];
		for (int j = 1; j < i; j++)
		{
			// first expression ensure that the arr is incre arr;
			// second expression ensure that the current answer < dp[j] + data[i];
			if (data[j] < data[i] && dp[i] < dp[j] + data[i])
			{
				dp[i] = dp[j] + data[i];
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= size; i++)
	{
		if (max <= dp[i])
		{
			max = dp[i];
		}
	}

	cout << max << endl;
}

int main()
{
	int size;
	while (cin >> size)
	{
		int *data = new int[size + 1];
		for (int i = 1; i <= size; i++)
		{
			cin >> data[i];
		}
		DP dpInstance(data, size);
		dpInstance.solve();
	}
}
