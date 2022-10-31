#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class MyClass
{
private:
    string name;
    int score;

public:
    MyClass(string name_, int score_)
        : name(name_), score(score_)
    {
    }

    void setName(string _name) { name = _name; }
    void setScore(int _score) { score = _score; }

    string getName() { return name; };
    int getScore() { return score; };

    void output_data()
    {
        cout << "name : " << name << "\tscore : " << score << endl;
    }
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

int main()
{
    vector<MyClass> vec;

    srand((unsigned)time(NULL));

    for (int i = 0; i < 3; i++)
    {
        MyClass class1(CreatName(), rand() % 15 + 0);
        vec.push_back(class1);
    }

    for (int i = 0; i < 3; i++)
    {
        vec[i].output_data();
    }
}