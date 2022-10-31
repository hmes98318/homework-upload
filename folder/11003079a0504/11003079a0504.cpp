#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, max = 0;
    cin >> a >> b >> c >> d;

    max > a ? max : max = a;
    max > b ? max : max = b;
    max > c ? max : max = c;
    max > d ? max : max = d;

    cout << max << endl;
    return 0;
}