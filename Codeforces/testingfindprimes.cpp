#include <iostream>
using namespace std;

void find(int n)
{
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cout << i << " ";
}

int main()
{
    find(100);
    return 0;
}