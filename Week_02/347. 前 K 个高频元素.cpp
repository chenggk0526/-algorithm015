class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        unordered_map<int, int> cnt;

        for (auto num : nums) cnt[num]++;
        for (auto key : cnt) {
            q.push({key.second, key.first});
            while (q.size() > k) q.pop();
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};