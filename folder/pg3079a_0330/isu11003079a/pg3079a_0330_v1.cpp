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

        // temp.total = temp.math + temp.english + temp.nature + temp.society + temp.chinese;

        temp.application = appli[rand() % 4 + 0];
        temp.oral = ora[rand() % 6 + 0];

        students.push_back(temp);
    }

    cout << "No.\tname\tmath\tenglish\tnature\tsociety\tchinese\tapplication\tOral" << endl;
    for (int i = 0; i < 2048; i++)
    {
        cout << "No." << i + 1 << " : " << students[i].name << "\t" << students[i].math << "\t" << students[i].english << "\t" << students[i].nature << "\t" << students[i].society << "\t" << students[i].chinese << "\t" << students[i].application << "\t" << students[i].oral << endl;
    }
}