/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;
        vector<int> b(2, -1);
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int tmp = target - nums[i];
            if (a.find(tmp) != a.end()) {
                b[0] = a[tmp];
                b[1] = i;
                break;
            } else{
                a[nums[i]] = i;
            }
        }
        return b;
    }
};
// @lc code=end

