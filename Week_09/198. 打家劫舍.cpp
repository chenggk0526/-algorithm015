
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0, curr = 0;
        for (auto i : nums){
            int tmp = curr;
            curr = max(curr, pre + i);
            pre = tmp;
        }
        return curr;
    }
};