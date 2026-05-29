class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp;
    TimeMap() {
        
    }

    int upper(vector<pair<int, string>> nums, int x) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = -1;
        while(low <= high) {
            int mid = (high+low)/2;
            if(nums[mid].first <= x) {
                ans = max(ans, mid);
                low = mid+1;
            } else high = mid-1;
        }
        if(ans == n) return -1;
        return ans;
    }

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> vec = mpp[key];
        int ind = upper(vec, timestamp);
        if(ind == -1) return "";
        return vec[ind].second;
    }
};
