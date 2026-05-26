class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);

        int prefix = 1;
        for(int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int noOfZeros = 0;
        long long mult = 1;
        for(int x:nums) {
            if(!x) noOfZeros++;
            if(x) mult *= x;
        }
        vector<int> ans(n, 0);
        if(noOfZeros >= 2) return ans;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                vector<int> temp(n, 0);
                temp[i] = mult;
                return temp;
            }
            ans[i] = mult/nums[i];
        }
        return ans;
    }
};

*/