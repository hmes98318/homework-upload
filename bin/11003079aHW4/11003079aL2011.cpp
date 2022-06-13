#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        
        for(int i = 0; i < operations.size(); i++){
            operations[i][1] == '+' ? res++ : res--; // 因為 ++X 或 X++ 在 [1] 的位置都是 +, 所以可以用這個位置來判斷
        }
        return res;
    }
};
// https://github.com/hmes98318/LeetCode/blob/main/problems/2011.Final_Value_of_Variable_After_Performing_Operations.md

int main()
{
    Solution solution;
    vector<string> operations = {"--X", "X++", "X++"};

    cout << solution.finalValueAfterOperations(operations) << endl;

    return 0;
}