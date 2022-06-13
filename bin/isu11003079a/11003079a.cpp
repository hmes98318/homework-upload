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

void SelectionSort(vector<score> &students, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (students[j].total < students[min_idx].total)
            {
                min_idx = j;
            }
        }
        // swap
        auto temp = students[min_idx];
        students[min_idx] = students[i];
        students[i] = temp;
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

    for (int i = 0; i < 1000; i++)
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

    // Output(students);

    SelectionSort(students, students.size());

    // Output(students);

    cout << "name\tmath\tenglish\tnature\tsociety\tchinese\ttotal" << endl;
    for (int i = 0; i <= 200; i += 100)
    {
        cout << "No." << i << " : " << students[i].name << "\t" << students[i].math << "\t" << students[i].english << "\t" << students[i].nature << "\t" << students[i].society << "\t" << students[i].chinese << "\t" << students[i].total << endl;
    }
}