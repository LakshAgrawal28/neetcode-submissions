class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = "";
        for(char c: s) {
            if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) s2 += c; 
            else if(c >= 'A' && c <= 'Z') s2 += (c - 'A' + 'a');
        }
        int i = 0, j = s2.size() - 1;
        while(i<=j) {
            if(s2[i] != s2[j]) return false;
            i++, j--;
        }
        return true;
    }
};
