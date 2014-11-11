#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stdio.h>

using namespace std;

#define SIZE 100010

struct less_cmp
{
	bool operator()(const int &a, const int &b)
	{
		return a > b;
	}
};

class TSort
{
public:
	TSort(int size);
	~TSort();
	void addEdge(int head, int tail);
	void solve();
private:
	int size;
	vector<int> vec[SIZE];
	priority_queue <int, vector<int>, less_cmp> que;
	int degree[SIZE];
};

TSort::TSort(int size)
	:size(size)
{

}

TSort::~TSort()
{

}

void TSort::addEdge(int head, int tail)
{
	degree[tail]++;
	vec[head].push_back(tail);
}

void TSort::solve()
{
	bool first = true;
	for (int i = 1; i <= size; i++)
	{
		/*push the nodes which degree is 0 into queue*/
		if (degree[i] == 0)
			que.push(i);
	}

	while (!que.empty())
	{
		int node = que.top();
		que.pop();
		if (first == true)
		{
			printf("%d", node);
			first = false;
		}
		else
			printf(" %d", node);
		/*decrease the adj nodes, and if now the degree is 0, push it into the queue*/
		for (vector<int>::iterator itr = vec[node].begin(); itr != vec[node].end(); itr++)
		{
			degree[*itr]--;
			if (degree[*itr] == 0)
				que.push(*itr);
		}
		/*the node's edges have been removed*/
		vec[node].clear();
	}
	printf("\n");
}

int main()
{
	int size;
	int edgeSize;

	while (cin >> size)
	{
		cin >> edgeSize;
		TSort tsort(size);
		for (int i = 0; i < edgeSize; i++)
		{
			int head, tail;
			cin >> head >> tail;
			tsort.addEdge(head, tail);
		}
		tsort.solve();
	}
}