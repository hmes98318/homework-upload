#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

class Mystudent
{
public:
    void constructor(string _myname, int _math, int _eng, float _average)
    {
        cout << "constructor called.." << endl;
        myname = _myname;
        math = _math;
        eng = _eng;
        average = _average;
    }

    string get_name() { return myname; }
    int get_math() { return math; }
    int get_eng() { return eng; }
    float get_average() { return average; }

private:
    string myname;
    int math;
    int eng;
    float average;
};

struct MaxIndex
{
    int math;
    int eng;
    int average;
};

string CreatName()
{
    string name = "";
    for (int i = 0; i < 6; i++)
    {
        name += 'a' + rand() % 25 + 0;
    }
    return name;
}

template <class T>
T findmax(T maxI, T arr) {}

void findmax(MaxIndex &maxI, vector<Mystudent> &arr)
{
    maxI.math = 0;
    maxI.eng = 0;
    maxI.average = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].get_math() > arr[maxI.math].get_math() ? maxI.math = i : maxI.math = maxI.math;
        arr[i].get_eng() > arr[maxI.eng].get_eng() ? maxI.eng = i : maxI.eng = maxI.eng;
        arr[i].get_average() > arr[maxI.average].get_average() ? maxI.average = i : maxI.average = maxI.average;
    }
}

int main()
{
    Mystudent mystudent;
    MaxIndex maxI;
    vector<Mystudent> arr(20);
    srand((unsigned)time(NULL));

    for (int i = 0; i < arr.size(); i++)
    {
        string name = CreatName();
        int math = rand() % 100 + 1;
        int eng = rand() % 100 + 1;
        float average = (math + eng) / 2;
        mystudent.constructor(name, math, eng, average);
        arr[i] = mystudent;
    }

    cout << "name\tmath\tenglist\taverage" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].get_name() << '\t' << arr[i].get_math() << '\t' << arr[i].get_eng() << '\t' << arr[i].get_average() << endl;
    }

    findmax(maxI, arr);
    cout << "----------------------------" << endl;
    cout << "max math:" << arr[maxI.math].get_math() << endl;
    cout << "max eng:" << arr[maxI.eng].get_eng() << endl;
    cout << "max average:" << arr[maxI.average].get_average() << endl;

    return 0;
}