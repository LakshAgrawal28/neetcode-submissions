class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1LL+8LL*n) - 1)/2;
    }
};