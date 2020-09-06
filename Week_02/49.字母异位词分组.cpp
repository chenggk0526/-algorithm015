class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector< vector<string> > ans;
        int sub = 0;
        unordered_map<string, int> work;
        string tmp;
        for (auto str : strs) {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            if(work.count(tmp)) {
                ans[work[tmp]].push_back(str);
            } else {
                vector<string> vc(1, str);
                ans.push_back(vc);
                work[tmp] = sub++;
            }
        }
        return ans;
    }
};