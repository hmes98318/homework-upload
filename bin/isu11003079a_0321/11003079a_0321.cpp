#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

struct score
{

    string name;
    int math;
    int english;
    int nature;
    int society;
    int chinese;
    int total;
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

void InsertionSort(vector<score> &students, int size)
{

    for (int i = 1; i < size; i++)
    {
        auto key = students[i];
        int j = i - 1;
        while (key.total < students[j].total && j >= 0)
        {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

void Output(vector<score> &students)
{
    cout << "name\tmath\tenglish\tnature\tsociety\tchinese\ttotal" << endl;
    for (auto stu : students)
    {
        cout << stu.name << "\t" << stu.math << "\t" << stu.english << "\t" << stu.nature << "\t" << stu.society << "\t" << stu.chinese << "\t" << stu.total << endl;
    }
    cout << "-----------------------" << endl;
}


int main()
{
    score temp;
    vector<score> students;

    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++)
    {

        temp.name = CreatName();
        temp.math = rand() % 15 + 0;
        temp.english = rand() % 15 + 0;
        temp.nature = rand() % 15 + 0;
        temp.society = rand() % 15 + 0;
        temp.chinese = rand() % 15 + 0;
        temp.total = temp.math + temp.english + temp.nature + temp.society + temp.chinese;
        students.push_back(temp);
    }

    //Output(students);

    InsertionSort(students, students.size());

    //Output(students);


    for (int i = 0; i < 100; i += 10)
    {
        cout << "No." << i << " : " << students[i].name << "\t" << students[i].math << "\t" << students[i].english << "\t" << students[i].nature << "\t" << students[i].society << "\t" << students[i].chinese << "\t" << students[i].total << endl;
    }
}