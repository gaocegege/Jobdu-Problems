#include <iostream>

#define LIMIT 501

using namespace std;

class DP
{
public:
	DP(int n);
	~DP();
	void solve();
private:
	int n;
	int dp[LIMIT][LIMIT];
};

DP::DP(int n)
	:n(n)
{
	for (int i = 0; i < LIMIT; i++)
		for (int j = 0; i < LIMIT; i++)
			dp[i][j] = 0;
}

DP::~DP(){}

void DP::solve()
{
	for (int i = 1; i <= n/2; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n/2; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] =( dp[i - 1][j] + dp[i][j - 1] ) % 1000000007;

	if (n % 2 == 1)
		cout << "0" << endl;
	else
		cout << dp[n/2][n/2] << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		DP dpInstance(n);
		dpInstance.solve();
	}
}
