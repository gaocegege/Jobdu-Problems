#include <iostream>
#include <string>

using namespace std;

class StringInt
{
public:
	StringInt(string num1, string num2);
	~StringInt();
	void printResult();
private:
	int num1;
	int num2;
};

StringInt::StringInt(string strnum1, string strnum2)
{
	bool flag1 = false, flag2 = false;
	num1 = 0;
	num2 = 0;
	int begin1 = 0, begin2 = 0;
	if (strnum1[0] == '-')
	{
		flag1 = true;
		begin1 = 1;
	}
	if (strnum2[0] == '-')
	{
		flag2 = true;
		begin2 = 1;
	}

	for (int i = begin1; i < strnum1.size(); i++)
	{
		if (strnum1[i] != ',')
		{
			num1 = num1 * 10 + strnum1[i] - '0';
		}
	}

	for (int i = begin2; i < strnum2.size(); i++)
	{
		if (strnum2[i] != ',')
		{
			num2 = num2 * 10 + strnum2[i] - '0';
		}
	}

	if (flag1 == true)
		num1 = -num1;
	if (flag2 == true)
		num2 = -num2;
}

StringInt::~StringInt(){}

void StringInt::printResult()
{
	cout << num1 + num2 << endl;
}

int main()
{
	int num = 0;
	string strnum1 = "";
	string strnum2 = "";
	while(cin >> strnum1) {
	    cin >> strnum2;
	    StringInt si = StringInt(strnum1, strnum2);
	    si.printResult();
	}
}