class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(!n) return {newInterval};
        int i=0;

        int low = newInterval[0], high = newInterval[1];
        while(i<n && low > intervals[i][1]) {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && high >= intervals[i][0]) {
            low = min(low, intervals[i][0]);
            high = max(high, intervals[i][1]);
            i++;
        }
        ans.push_back({low, high});
        while(i<n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
