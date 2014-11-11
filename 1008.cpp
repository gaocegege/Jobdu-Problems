#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>

#define SIZE 1000
#define INFINITY 2147483647

using namespace std;

struct Edge
{
	int weight;
	int cost;
};

// struct Vertex
// {
// 	int index;
// 	int dis;
// };

// /*return the lowest element*/
// struct less_cmp
// {
// 	bool operator()(const Vertex &a, const Vertex &b)
// 	{
// 		return a.dis > b.dis;
// 	}
// };

class ShortestPathSolver
{
public:
	ShortestPathSolver(int size);
	~ShortestPathSolver();
	void addEdge(int head, int tail, int weight, int cost);
	void solve();
	void setSandT(int s, int t);
private:
	/*var define*/
	Edge data[SIZE][SIZE];
	int disTo[SIZE];
	int cost[SIZE];
	int flag[SIZE];
	int size;
	int s;
	int t;
	/*assistant func*/
	void init();
	int findMin();
	void relax(int u, int v);
};

ShortestPathSolver::ShortestPathSolver(int size)
	:size(size)
{
	init();
}

ShortestPathSolver::~ShortestPathSolver()
{

}

void ShortestPathSolver::addEdge(int head, int tail, int weight, int cost)
{
	Edge buf;
	buf.weight = weight;
	buf.cost = cost;
	data[head - 1][tail - 1] = buf;
	data[tail - 1][head - 1] = buf;
}

void ShortestPathSolver::setSandT(int s, int t)
{
	this->s = s - 1;
	this->t = t - 1;
	for (int i = 0; i < size; i++)
	{
		if (i == this->s)
		{
			disTo[i] = 0;
			cost[i] = 0;
		}
		else
		{
			disTo[i] = INFINITY;
			cost[i] = INFINITY;
		}
		flag[i] = 0;
	}
}

void ShortestPathSolver::init()
{
	memset(&data, 0, sizeof(Edge) * size * size);
}

int ShortestPathSolver::findMin()
{
	int min = INFINITY;
	int index;
	for (int i = 0; i < size; i++)
	{
		if (flag[i] == 0 && disTo[i] <= min)
		{
			min = disTo[i];
			index = i;
		}
	}
	return index;
}

void ShortestPathSolver::solve()
{
	int count = 1;
	while (count != size)
	{
		int u = findMin();
		flag[u] = 1;
		count++;
		for (int i = 0; i < size; i++)
		{
			if (data[u][i].weight != 0)
			{
				relax(u, i);
			}
		}
	}
	cout << disTo[t] << " " << cost[t] << endl;
}

void ShortestPathSolver::relax(int u, int v)
{
	if (disTo[v] > disTo[u] + data[u][v].weight)
	{
		disTo[v] = disTo[u] + data[u][v].weight;
		cost[v] = cost[u] + data[u][v].cost;
	}
	else if (disTo[v] == disTo[u] + data[u][v].weight)
	{
		if (cost[v] > cost[u] + data[u][v].cost)
			cost[v] = cost[u] + data[u][v].cost;
	}
}

int main()
{
	int size, edgeSize;
	while (cin >> size)
	{
		cin >> edgeSize;
		if (size == 0 && edgeSize == 0)
			return 0;
		ShortestPathSolver sps(size);
		int head, tail, weight, cost;
		for (int i = 0; i < edgeSize; i++)
		{
			cin >> head >> tail >> weight >> cost;
			sps.addEdge(head, tail, weight, cost);
		}

		int s, t;
		cin >> s >> t;
		sps.setSandT(s, t);
		sps.solve();
	}
}