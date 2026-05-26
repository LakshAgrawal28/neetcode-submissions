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
