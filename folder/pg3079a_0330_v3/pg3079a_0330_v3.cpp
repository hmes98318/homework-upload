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
    int application;
    int oral;
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

void Sort_math(vector<score> &students, int size, vector<score> &math)
{
    auto vectorCatch = students;

    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (students[j].math > students[min_idx].math)
            {
                min_idx = j;
            }
        }
        // swap
        auto temp = students[min_idx];
        students[min_idx] = students[i];
        students[i] = temp;
    }
    math = students;
    students = vectorCatch;
}

void Sort_english(vector<score> &students, int size, vector<score> &english)
{
    auto vectorCatch = students;

    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (students[j].english > students[min_idx].english)
            {
                min_idx = j;
            }
        }
        // swap
        auto temp = students[min_idx];
        students[min_idx] = students[i];
        students[i] = temp;
    }
    english = students;
    students = vectorCatch;
}

void Sort_application(vector<score> &students, int size, vector<score> &application)
{
    auto vectorCatch = students;

    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (students[j].application > students[min_idx].application)
            {
                min_idx = j;
            }
        }
        // swap
        auto temp = students[min_idx];
        students[min_idx] = students[i];
        students[i] = temp;
    }
    application = students;
    students = vectorCatch;
}

void Sort_oral(vector<score> &students, int size, vector<score> &oral)
{
    auto vectorCatch = students;

    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (students[j].oral > students[min_idx].oral)
            {
                min_idx = j;
            }
        }
        // swap
        auto temp = students[min_idx];
        students[min_idx] = students[i];
        students[i] = temp;
    }
    oral = students;
    students = vectorCatch;
}

void Output(vector<score> &students, int index)
{
    cout << "No.\tname\tmath\tenglish\tnature\tsociety\tchinese\tapplication\tOral" << endl;
    for (int i = 0; i < index; i++)
    {
        cout << "No." << i + 1 << " : " << students[i].name << "\t" << students[i].math << "\t" << students[i].english << "\t" << students[i].nature << "\t" << students[i].society << "\t" << students[i].chinese << "\t" << students[i].application << "\t" << students[i].oral << endl;
    }
}

int main()
{
    score temp;
    vector<score> students;

    int appli[] = {70, 75, 80, 85, 90};
    int ora[] = {65, 70, 75, 80, 85, 90, 95};

    srand((unsigned)time(NULL));

    for (int i = 0; i < 2048; i++)
    {

        temp.name = CreatName();
        temp.math = 4 + (rand() % (8 - 4 + 1));

        if (i < 1024)
            temp.english = 3 + (rand() % (6 - 3 + 1));
        else
            temp.english = 7 + (rand() % (11 - 7 + 1));

        temp.nature = 7 + (rand() % (11 - 7 + 1));
        temp.society = 9 + (rand() % (11 - 9 + 1));
        temp.chinese = 8 + (rand() % (12 - 8 + 1));

        temp.application = appli[rand() % 4 + 0];
        temp.oral = ora[rand() % 6 + 0];

        students.push_back(temp);
    }

    int size(students.size());
    vector<score> math(size);
    vector<score> english(size);
    vector<score> application(size);
    vector<score> oral(size);


    

    Sort_math(students, students.size(), math);
    //Output(math, member_math);
    int member_math = 500;
    int sameMath = math[member_math].math;
    while (math[++member_math].math >= sameMath)
    {
    }
    math.resize(member_math);
    //Output(math,member_math);


    Sort_english(math, math.size(), english);
    int member_english = 350;
    int sameEnglish = english[member_english].english;
    while (english[++member_english].english >= sameEnglish)
    {
    }
    english.resize(member_english);
    //Output(english, member_english);


    Sort_application(english, english.size(), application);
    int member_application = 200;
    int sameApplication = application[member_application].application;
    while (application[++member_application].application >= sameApplication)
    {
    }
    application.resize(member_application);
    //Output(application, member_application);


    Sort_oral(application, application.size(), oral);
    int member_oral = 150;
    int sameOral = oral[member_oral].oral;
    while (oral[++member_oral].oral >= sameOral)
    {
    }
    oral.resize(member_oral);


    Output(oral, member_oral);
    return 0;
}