class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<int>> mpp;
        vector<vector<string>> ans;
        if(!n) return ans;

        for(int i=0; i<n; i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            mpp[str].push_back(i);
        }
        for(auto &it: mpp) {
            vector<string> temp;
            for(int x: it.second) temp.push_back(strs[x]);
            ans.push_back(temp);
        }
        return ans;
    }
};
