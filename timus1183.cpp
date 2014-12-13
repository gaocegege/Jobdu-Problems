#include <iostream>
#include <string>

#define MAX		0x7fffffff

using namespace std;

class Solver
{
public:
	Solver(string str);
	~Solver();
	void solve();

private:
	string str;
	int size;
	int **dp;
	int **path;

	string recursive(int x, int y);
};

Solver::Solver(string str)
	:str(str)
{
	size = str.size();
	dp = new int*[size + 1];
	path = new int*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		dp[i] = new int[size + 1];
		path[i] = new int[size + 1];
	}
}

Solver::~Solver(){}

string Solver::recursive(int x, int y)
{
	if(x > y || y < 1 || x > size) 
		return "";  
	if((x == y) && (str[x - 1] == '(' || str[x-1] == ')' )) 
		return "()";  
	if((x == y) && (str[x - 1] == '[' || str[x - 1] == ']'))
		return "[]";  
	if(path[x][y]==0) 
		return str[x - 1] + recursive(x + 1,y - 1)+str[y - 1];  
	else 
		return recursive(x, path[x][y]) + recursive(path[x][y] + 1, y);
}

void Solver::solve()
{
	for (int i = 1; i <= size; i++)
	{
		dp[i][i] = 1;

		for (int j = i + 1; j <= size; j++)
		{
			dp[i][j] = MAX;
		}
	}

	for (int dev = 1; dev <= size; dev++)
	{
		for (int i = 1; i + dev <= size; i++)
		{
			int j = i + dev;
			if ((str[i - 1] == '(' && str[j - 1] == ')') || (str[i - 1] == '[' && str[j - 1] == ']'))
			{
				if (dp[i + 1][j - 1] < dp[i][j])
				{
					//cout << i << "\t" << j << endl;
					//cout << "dp[i + 1][j - 1]:" << dp[i + 1][j - 1] << endl;
					dp[i][j] = dp[i + 1][j - 1];
				}
			}

			for (int k = i; k < j; k++)
			{
				if(dp[i][k] + dp[k+1][j] < dp[i][j])
				{
					dp[i][j] = dp[i][k] + dp[k+1][j];  
					path[i][j] = k;
				}
			}
		}
	}

	cout << recursive(1, size)<< endl;
}

int main()
{
	string str;
	cin >> str;
	Solver solver = Solver(str);
	solver.solve();
}
