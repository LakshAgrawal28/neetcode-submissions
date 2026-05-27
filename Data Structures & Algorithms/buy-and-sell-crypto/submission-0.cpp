class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int ans = 0;
        for(int x: prices) {
            minPrice = min(minPrice, x);
            ans = max(ans, x - minPrice);
        }
        return ans;
    }
};
