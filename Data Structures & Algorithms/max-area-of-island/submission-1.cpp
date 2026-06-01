class Solution {
public:
    int n, m;
    bool valid(int i, int j) {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int& area) {
        area++;
        vis[row][col] = 1;
        vector<int> adjRow = {-1, +1, 0, 0};
        vector<int> adjCol = {0, 0, -1, +1};
        for(int i=0; i<4; i++) {
            int nR = row + adjRow[i];
            int nC = col + adjCol[i];
            if(valid(nR, nC) && (grid[nR][nC]) && !vis[nR][nC]){
                dfs(nR, nC, grid, vis, area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(!vis[row][col] && (grid[row][col])) {
                    int area = 0;
                    dfs(row, col, grid, vis, area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
