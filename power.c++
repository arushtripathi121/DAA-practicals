#include <iostream>
using namespace std;

double power(double x, int n)
{
    if (n == 0)
        return 1;
    double half = power(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else if (n > 0)
        return half * half * x;
    else
        return half * half / x;
}

int main()
{
    double x = 2.0;
    int n = 10;
    cout << power(x, n) << endl;
    return 0;
}
