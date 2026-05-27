class Solution {
public:
    bool isAlphaNum(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'));
    }
    char toLower(char c) {
        if(c >= 'A' && c <= 'Z') 
            return (c - 'A' + 'a');
        else return c;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i<j) {
            while(i<j && !isAlphaNum(s[i])) i++;
            while(i<j && !isAlphaNum(s[j])) j--;
            if(toLower(s[i]) != toLower(s[j])) return false;
            i++, j--;
        }
        return true;
    }
};

/*
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
*/
