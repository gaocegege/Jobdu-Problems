#include <iostream>
#include <queue>

using namespace std;

enum Color
{
	white,
	gray,
	black
};

class PathSolver
{
public:
	PathSolver(int size, int* data);
	~PathSolver();
	void solve();
	void printResult();
private:
	/*var define*/
	int size;
	int* data;
	int* dis;
	/*0: white, 1: gray, 2: black*/
	Color* flag;
	int result;
	queue<int> q;

	/*assistant func*/
	void init();
	void getAdj(int i, int &a, int &b, int &c, int &d);
};

PathSolver::PathSolver(int size, int* data)
	:size(size), data(data), result(0)
{
	init();
}

PathSolver::~PathSolver()
{
	delete[] data;
	delete[] flag;
}

void PathSolver::init()
{
	flag = new Color[size * size];
	dis = new int[size * size];
	for (int i = 0;i < size * size; i++)
	{
		flag[i] = white;
		dis[i] = 0;
	}
}

void PathSolver::getAdj(int i, int &a, int &b, int &c, int &d)
{
	a = b = c = d = -1;
	if (i - size >= 0)
		a = i - size;
	if (i + size < size * size)
		b = i + size;
	if (i % size != 0)
		c = i - 1;
	if (i % size != size - 1)
		d = i + 1;
	return;
}

void PathSolver::solve()
{
	if (data[0] == 1 || data[size * size - 1] == 1)
	{
		result = -1;
		return;
	}

	q.push(0);
	flag[0] = gray;
	while(q.empty() != true)
	{
		int up, down, left, right;
		int now = q.front();
		q.pop();
		if (now == size * size - 1)
		{
			result = dis[now];
			return;
		}

		getAdj(now, up, down, left, right);
		if (up != -1 && flag[up] == white && data[up] != 1)
		{
			q.push(up);
			flag[up] = gray;
			dis[up] = dis[now] + 1;
		}
		if (down != -1 && flag[down] == white && data[down] != 1)
		{
			q.push(down);
			flag[down] = gray;
			dis[down] = dis[now] + 1;
		}
		if (left != -1 && flag[left] == white && data[left] != 1)
		{
			q.push(left);
			flag[left] = gray;
			dis[left] = dis[now] + 1;
		}
		if (right != -1 && flag[right] == white && data[right] != 1)
		{
			q.push(right);
			flag[right] = gray;
			dis[right] = dis[now] + 1;
		}
		flag[now] = black;
	}
	result = -1;
}

void PathSolver::printResult()
{
	cout << result << endl;
}

int main()
{
	int size = 0;
	while (cin >> size)
	{
		int* data = new int[size * size];
		for (int i = 0; i < size*size; i++)
		{
			cin >> data[i];
		}
		PathSolver pathSolver(size, data);
		pathSolver.solve();
		pathSolver.printResult();
	}
	return 0;
}