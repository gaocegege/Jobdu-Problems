#include <iostream>
#define MIN 0x8000000000000000
using namespace std;
 
class DP
{
public:
    DP(long long *data, int size);
    ~DP();
    void solve();
private:
    long long *data;
    long long result;
    int size;
};
 
DP::DP(long long *data, int size)
    :data(data), size(size), result(MIN)
{
 
}
 
DP::~DP()
{
    delete[] data;
}
 
void DP::solve()
{
    long long buf = 0;
    for (int i = 0; i < size; i++)
    {
        if (buf > 0)
        {
            buf += data[i];
        }
        else
        {
            buf = data[i];
        }
        if (buf > result)
            result = buf;
    }
    cout << result << endl;
}
 
int main ()
{
    int size = 0;
    while (cin >> size)
    {
        long long *data = new long long[size];
        for (int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
        DP dpInstance = DP(data, size);
        dpInstance.solve();
    }
}