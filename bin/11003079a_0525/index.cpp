#include <iostream>
#include <array>
#include <vector>
#include <time.h>

#define SIZE_4 4
#define SIZE_3 3

using namespace std;

void fillArray(vector<vector<int>> &);
void fillArray(array<array<int, SIZE_4>, SIZE_3> &);

void showArray(vector<vector<int>> &);
void showArray(array<array<int, SIZE_4>, SIZE_3> &);

void multiplyArray(vector<vector<int>> &, vector<vector<int>> &, array<array<int, SIZE_4>, SIZE_3> &);
void showMultiplyArray(vector<vector<int>> &);

int main()
{
    vector<vector<int>> P(SIZE_4, vector<int>(SIZE_3));
    array<array<int, SIZE_4>, SIZE_3> Q = {0};
    vector<vector<int>> R(SIZE_4, vector<int>(SIZE_4));

    srand((unsigned)time(NULL));


    cout << "vector P:" << endl;
    fillArray(P);
    showArray(P);
    cout << endl;

    cout << "array Q:" << endl;
    fillArray(Q);
    showArray(Q);
    cout << endl;

    cout << "array R:" << endl;
    multiplyArray(R, P, Q);
    showMultiplyArray(R);
    cout << endl;
    
    return 0;
}

void fillArray(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            arr[i][j] = rand() % 90 + 10;
        }
    }
}

void fillArray(array<array<int, SIZE_4>, SIZE_3> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            arr[i][j] = rand() % 90 + 10;
        }
    }
}

void showArray(vector<vector<int>> &arr)
{
    for (auto col : arr)
    {
        for (auto row : col)
        {
            cout << row << " ";
        }
        cout << endl;
    }
}

void showArray(array<array<int, SIZE_4>, SIZE_3> &arr)
{
    for (auto col : arr)
    {
        for (auto row : col)
        {
            cout << row << " ";
        }
        cout << endl;
    }
}

void multiplyArray(vector<vector<int>> &R, vector<vector<int>> &arr1, array<array<int, SIZE_4>, SIZE_3> &arr2)
{
    int col = arr1.size() < arr2.size() ? arr1.size() : arr2.size(); // find the smallest size
    int row = arr1[0].size() < arr2[0].size() ? arr1[0].size() : arr2[0].size();


    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            R[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
    
// vector default fill with 0, so there is no need to add 0
/* 
    for (int i = col; i < R.size(); i++)
    {
        for (int j = row; j < R[0].size(); j++)
        {
            R[i][j] = 0;
        }
    }
*/
}

void showMultiplyArray(vector<vector<int>> &arr)
{
    for (auto col : arr)
    {
        for (auto row : col)
        {
            cout << row << " ";
        }
        cout << endl;
    }
}