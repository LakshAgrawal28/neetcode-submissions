class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0); // frequency of chars
        int l = 0, r = 0;
        int maxLen = 0, maxf = 0;
        while(r<n) {
            freq[s[r]-'A']++;
            maxf = max(maxf, freq[s[r]-'A']);
            
            if(r-l+1 - maxf > k) { // we have a problem so l++ ie shrink
                freq[s[l]-'A']--;
                l++;
                maxf = 0;
                for(int i=0;i<26;i++) maxf = max(maxf, freq[i]);
            } 
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};
