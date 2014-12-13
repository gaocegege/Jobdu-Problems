#include <iostream>

using namespace std;

class Solver
{
public:
	Solver(int num, int x, int y, int z);
	void solve();
private:
	int num;
	int x;
	int y;
	int z;
	int getThePrice(int i, int j);
};

Solver::Solver(int num, int x, int y, int z)
	:num(num), x(x), y(y), z(z)
{}

void Solver::solve()
{
	for (int i = 9; i >= 1; i--)
	{
		for (int j = 9; j >= 0; j--)
		{
			int price = getThePrice(i, j);
			if (price % num == 0)
			{
				cout << i << " " << j << " " << price / num << endl;
				return;
			}
		}
	}
	cout << "0" << endl;
	return;

}

int Solver::getThePrice(int i, int j)
{
	return j + z * 10 + y * 100 + x * 1000 + i * 10000;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		int x,y,z;
		cin >> x >> y >> z;
		Solver solverInstance(num, x, y, z);
		solverInstance.solve();
	}
}

