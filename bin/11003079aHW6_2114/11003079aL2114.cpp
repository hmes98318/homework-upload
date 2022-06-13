#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int space_max = 0;
        for(string sen : sentences){ // 遍歷 sentences 中每條句子
            int space = 0;
            for(char c : sen){
                if(c == ' ') // 檢測一條句子中有幾個空格, 空格數+1 則表示有幾個單字
                    space++;
            }
            space_max = max(space_max, space + 1); // 比較哪一句的空格數最多, 則單字數最多
        }
        return space_max;
    }
};
// https://github.com/hmes98318/LeetCode/blob/main/problems/2114.Maximum_Number_of_Words_Found_in_Sentences.md

int main()
{
    Solution solution;
    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};

    int res = solution.mostWordsFound(sentences);
    cout << res << endl;

    return 0;
}