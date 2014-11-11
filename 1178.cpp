#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
/*1178
Coder:Gao Ce
*/

int StringToNum(string s){
	int i, len, r;
	len = s.length();
	for (i = 0; i<len; i++){
		if (i == 0)
			r = s[i] - 48;
		else r = r * 10 + s[i] - 48;
	}
	return r;
};

class Complex
{
public:
	Complex(){}
	Complex(int a, int b);
	~Complex();
	double getMo();
	int getb();
	void printResult();
private:
	int a;
	int b;
	double mo;
};

Complex::Complex(int a, int b)
	:a(a), b(b)
{
	mo = a*a + b*b;
}

Complex::~Complex()
{
}

double Complex::getMo()
{
	return mo;
}

int Complex::getb()
{
	return b;
}

void Complex::printResult()
{
	cout << a << "+i" << b << endl;
}

class ComplexSet
{
public:
	ComplexSet();
	~ComplexSet();
	void parse(string str);
	void push(Complex c);
	void pop();
private:
	vector<Complex> complexList;
	void printSize();
	//void sort(Complex c);
};

ComplexSet::ComplexSet()
{
	
}

ComplexSet::~ComplexSet()
{
}

void ComplexSet::parse(string str)
{
	/*can change to if*/
	if (str[0] == 'P')
	{
		pop();
	}
	else
	{
		/*Insert a+ib
		01234567
		*/
		string bufa = "";
		int pos = 0;
		for (int i = 7; i < str.size(); i++)
		{
			if (str[i] != '+')
				bufa += str[i];
			else
			{
				pos = i;
				break;
			}
		}
		/*pos = '+'*/
		pos += 2;
		string bufb = "";
		for (unsigned i = pos; i < str.size(); i++)
		{
			bufb += str[i];
		}

		int aa = StringToNum(bufa);
		int ba = StringToNum(bufb);
		//cout << aa << ba << endl;
		Complex c = Complex(aa, ba);
		push(c);
	}
}

void ComplexSet::push(Complex c)
{
	complexList.push_back(c);
	//cout << complexList[0].getMo() << endl;
	int i = complexList.size() - 2;
	for (; i >= 0; i--)
	{
		if (c.getMo() < complexList[i].getMo())
		{
			complexList[i + 1] = complexList[i];
		}
		else if (c.getMo() == complexList[i].getMo() && c.getb() > complexList[i].getb())
			complexList[i + 1] = complexList[i];
		else
			break;
	}
	/*now i + 1 is a hole~?*/
	complexList[i + 1] = c;
	/*cout << complexList[i + 1].getMo() << endl;
	cout << i + 1 << endl;
	cout << complexList.size() << endl;
	cout << "SIZE = " << complexList.size() << endl;*/
	printSize();
}

void ComplexSet::pop()
{
	if (complexList.size() == 0)
	{
		cout << "empty\n";
		return;
	}
	//cout << complexList.size() - 1 << endl;
	Complex c = complexList[complexList.size() - 1];
	complexList.pop_back();
	c.printResult();
	printSize();
	return;
}

void ComplexSet::printSize()
{
	cout << "SIZE = " << complexList.size() << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		ComplexSet its = ComplexSet();
		for (int i = 0; i < n; i++)
		{

			string ins = "";
			cin >> ins;
			if (ins == "Pop")
			{
				its.pop();
			}
			else
			{
				cin >> ins;
				int a,b;
				for (int i = 0; i < ins.size(); i++)
				{
					if (ins[i] == '+')
					{
						a = StringToNum(ins.substr(0, i));
						b = StringToNum(ins.substr(i + 2));
					}
				}

				Complex c = Complex(a, b);
				its.push(c);
			}
			// its.parse(ins);
		}
	}
}
