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
	int *opt;
	void init();
};

DP::DP(int *data, int size)
	:data(data), size(size)
{
	init();
}

void DP::init()
{
	opt = new int[size];

	for (int i = 0; i < size; i++)
	{
		opt[i] = 0;
	}
}

DP::~DP()
{
	delete[] data;
	delete[] opt;
}

void DP::solve()
{
	// notice that if calculate the opt by reverse order, it will be better
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		// record the max num
		int max = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (data[j] >= data[i] && max < opt[j])
			{
				max = opt[j];
			}
		}
		opt[i] = max + 1;
		if (result < opt[i])
		{
			result = opt[i];
		}
	}
	cout << result << endl;
}

int main()
{
	int size;
	while (cin >> size)
	{
		int *data = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> data[i];
		}
		DP dpInstance = DP(data, size);
		dpInstance.solve();
	}
}