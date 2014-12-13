#include <iostream>

using namespace std;

class DP
{
public:
	DP(int size, int *data);
	void solve();
	~DP();

private:
	int size;
	int *data;
	int *dp;
};

DP::DP(int size, int *data)
	:size(size), data(data)
{
	dp = new int[size + 1];
	for (int i = 0; i <= size; i++)
		dp[i] = 0;
}

DP::~DP()
{
	delete[] data;
}

void DP::solve()
{
	int max = 0x80000000;
	int start = 0, end = 0;
	bool flag = true;
	for (int i = 1; i <= size; i++)
		if (data[i] >= 0)
			flag = false;
	if (flag == true)
	{
		cout << "0 " << data[1] << " " << data[size] << endl;
		return;
	}
	
	int tmp = 0, buf = 1;
	for (int i = 1;i <= size; i++)
	{
		tmp += data[i];
		if (tmp < 0)
		{
			tmp = 0;
			buf = i + 1;
		}
		else if (tmp > max)
		{
			max = tmp;
			start = buf;
			end = i;
		}
		
	}
	//cout << "Debug: " << start << " " << end << endl;
	cout << max << " " << data[start] << " " << data[end] << endl;
}

int main()
{
	int size;
	while (cin >> size && size != 0)
	{
		int *data = new int[size + 1];
		for (int i = 1; i <= size; i++)
			cin >> data[i];
		DP dpInstance(size, data);
		dpInstance.solve();
	}
}
