#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void CheckWord(vector<int> &wordCount, char ch);

int main()
{
    ifstream fs;

    vector<string> lines;
    string buffer;

    vector<int> wordCount(26);
    int maxWord_index = 0, minWord_index = 0;


    fs.open("./oop.txt");
    if (!fs.is_open())
        cout << "Failed to open" << endl;

    while (getline(fs, buffer))
    {
        lines.push_back(buffer);
    }


    for (auto line : lines)
    {
        for (auto ch : line)
        {
            CheckWord(wordCount, ch);
        }
    }

    for(int i = 0; i < wordCount.size(); i++){
        maxWord_index = wordCount[i] > wordCount[maxWord_index] ? maxWord_index = i : maxWord_index = maxWord_index;
    }

    int i2 = 0;
    do{
        minWord_index = wordCount[i2] < wordCount[minWord_index] ? minWord_index = i2 : minWord_index = minWord_index;
    }while (i2++ < wordCount.size());




    for (int i = 0; i < wordCount.size(); i++)
    {
        cout <<char('a'+i) <<": "<< wordCount[i] << endl;
    }
    cout <<"max letter is: "<< char('a'+maxWord_index) <<", total count: "<< wordCount[maxWord_index] << endl;
    cout << "min letter is: "<<char('a'+minWord_index)<<", total count: "<<wordCount[minWord_index] << endl;
    return 0;
}




void CheckWord(vector<int> &wordCount, char ch)
{
    ch = tolower(ch);
    switch (ch)
    {
    case 'a':
        wordCount[ch - 97]++;
        break;
    case 'b':
        wordCount[ch - 97]++;
        break;
    case 'c':
        wordCount[ch - 97]++;
        break;
    case 'd':
        wordCount[ch - 97]++;
        break;
    case 'e':
        wordCount[ch - 97]++;
        break;
    case 'f':
        wordCount[ch - 97]++;
        break;
    case 'g':
        wordCount[ch - 97]++;
        break;
    case 'h':
        wordCount[ch - 97]++;
        break;
    case 'i':
        wordCount[ch - 97]++;
        break;
    case 'j':
        wordCount[ch - 97]++;
        break;
    case 'k':
        wordCount[ch - 97]++;
        break;
    case 'l':
        wordCount[ch - 97]++;
        break;
    case 'm':
        wordCount[ch - 97]++;
        break;
    case 'n':
        wordCount[ch - 97]++;
        break;
    case 'o':
        wordCount[ch - 97]++;
        break;
    case 'p':
        wordCount[ch - 97]++;
        break;
    case 'q':
        wordCount[ch - 97]++;
        break;
    case 'r':
        wordCount[ch - 97]++;
        break;
    case 's':
        wordCount[ch - 97]++;
        break;
    case 't':
        wordCount[ch - 97]++;
        break;
    case 'u':
        wordCount[ch - 97]++;
        break;
    case 'v':
        wordCount[ch - 97]++;
        break;
    case 'w':
        wordCount[ch - 97]++;
        break;
    case 'x':
        wordCount[ch - 97]++;
        break;
    case 'y':
        wordCount[ch - 97]++;
        break;
    case 'z':
        wordCount[ch - 97]++;
        break;
    default:
        break;
    }
}