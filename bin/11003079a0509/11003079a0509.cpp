#include <iostream>

using namespace std;

int main()
{
    const int arrSize = 25;
    int arr[arrSize] = {0};

    int i = 0;
    while (i < arrSize)
    {
        cin >> arr[i++];
    }

    int maxNum = arr[0];
    for (int j = 0; j < arrSize; j++)
    {
        arr[j] > maxNum ? maxNum = arr[j] : maxNum;
    }

    cout << "maxNum:" << maxNum << endl;
    return 0;
}