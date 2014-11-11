#include <iostream>

#define SIZE 100
#define INFINITY 2147483647

using namespace std;

class SpanningTreeSolver
{
public:
	SpanningTreeSolver(int size);
	~SpanningTreeSolver();
	void solve();
	void addEdge(int head, int tail, int dis);
private:
	/*var define*/
	int size;
	int dis[SIZE][SIZE];
	int key[SIZE];
	int pi[SIZE];
	/*false: white, true: black*/
	bool flag[SIZE];
	/*assistant func*/
	void init();
	int findMinKey();
};

SpanningTreeSolver::SpanningTreeSolver(int size)
	:size(size)
{
	init();
}

SpanningTreeSolver::~SpanningTreeSolver()
{

}

void SpanningTreeSolver::init()
{
	for (int i = 0; i < size; i++)
	{
		flag[i] = false;
		dis[i][i] = INFINITY;
		key[i] = INFINITY;
		pi[i] = INFINITY;
	}
}

void SpanningTreeSolver::addEdge(int head, int tail, int dis)
{
	this->dis[head - 1][tail - 1] = dis;
	this->dis[tail - 1][head - 1] = dis;
}

int SpanningTreeSolver::findMinKey()
{
	int min = INFINITY;
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (flag[i] == false && key[i] < min)
		{
			min = key[i];
			result = i;
		}
	}
	return result;
}

void SpanningTreeSolver::solve()
{
	key[0] = 0;
	int minDis = 0;
	int count = 1;
	flag[0] = false;
	while (count != size - 1)
	{
		int selected = findMinKey();
		for (int i = 0; i < size; i++)
		{
			if (dis[selected][i] < key[i] && flag[i] == false)
			{
				key[i] = dis[selected][i];
				pi[i] = selected;
			}
		}
		flag[selected] = true;
		count++;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		if (pi[i] != INFINITY)
			minDis += dis[i][pi[i]];
	}
	cout << minDis << endl;
}

int main()
{
	int size;
	while (cin >> size)
	{
		if (size == 0)
			return 0;
		int edgeSize = (size - 1) * size / 2;
		// cout << "size of edges is " << edgeSize << endl;
		SpanningTreeSolver sts(size);
		for (int i = 0; i < edgeSize; i++)
		{
			int head, tail, dis;
			cin >> head >> tail >> dis;
			sts.addEdge(head, tail, dis);
			// cout << "YES" << endl;
		}
		// cout << "end\n";
		sts.solve();
	}
}