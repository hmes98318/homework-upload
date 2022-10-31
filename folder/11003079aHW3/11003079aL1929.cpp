#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len(nums.size());
        vector<int> res(len*2); // 設置一個大小為 nums.size()*2 的 vector
        
        for(int i = 0; i < len; i++){ // 依序將 nums 放入 res
            res[i] = nums[i];
        }
        for(int i = 0; i < len; i++){ // 再次從 res 的結束點下一位放入 nums
            res[i + len] = nums[i];
        }
        return res;
    }
};
// https://github.com/hmes98318/LeetCode/blob/main/problems/1929.Concatenation_of_Array.md

int main()
{
    Solution solution;
    vector<int> nums = {1,2,1};

    for(auto num : solution.getConcatenation(nums)){
        cout << num << " ";
    }

    return 0;
}