class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1;
        while(l<r) {
            int sum = ((nums[l] - target) + nums[r]); // sum<target becomes sum<0
            if(sum == 0) return {l+1, r+1};
            else if(sum < 0) l++;
            else r--;
        }
        return {-1, -1};
    }
};
