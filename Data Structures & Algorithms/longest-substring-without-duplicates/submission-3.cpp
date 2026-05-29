class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        vector<int> hash(230, -1);
        int n = s.size();
        int ans = 0;
        while(r<n) {
            if(hash[s[r]] != -1) {
                l = max(l, hash[s[r]] + 1);
            }
            ans = max(ans, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return ans;
    }
};
