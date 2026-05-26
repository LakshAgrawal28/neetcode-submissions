class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s: strs) {
            ans += to_string(s.size());
            ans += "#";
            ans += s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> ans;
        if(!n) return ans;
        int i = 0;
        int len;
        while(i < n) {
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            j++;
            string temp = s.substr(j, len);
            ans.push_back(temp);
            i = j + len;
        }
        return ans;
    }
};
