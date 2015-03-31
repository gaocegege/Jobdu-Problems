#include <iostream>

using namespace std;

class Solver
{
public:
	Solver(string *_arr, int _sz): arr(_arr), sz(_sz){}
	~Solver()
	{
		delete[] arr;
	}
	void solve()
	{
		for (int i = sz / 2 - 1; i >= 0; i--)
		{
			swap(arr[i], arr[sz - 1 - i]);
		}
		printRes();
	}
private:
	string *arr;
	int sz;
	void swap(string &a, string &b)
	{
		string buf = a;
		a = b;
		b = buf;
	}
	void printRes()
	{
		for (int i = 0; i < sz - 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << arr[sz - 1] << endl;
	}
};

int main()
{
	int num;
	while(cin >> num) {
	    /* code */
	    string *arr = new string[num];
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	Solver s(arr, num);
	s.solve();
	}
}