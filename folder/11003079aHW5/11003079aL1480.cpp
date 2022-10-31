#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 1; i < n; i++){ // 遍歷 nums
            nums[i] += nums[i - 1]; // 因為每次都是把前面的值加起來, 所以只要調用 nums[i-1] 的值加起來即可
        }
        return nums;
    }
};
// https://github.com/hmes98318/LeetCode/blob/main/problems/1480.Running_Sum_of_1d_Array.md

int main()
{
    Solution solution;
    vector<int> nums = {1,2,3,4};

    for(auto num : solution.runningSum(nums)){
        cout << num << " ";
    }

    return 0;
}