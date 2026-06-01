class Solution { //good Q (rotting oranges but thinking process cool)
public:
    int n, m;
    bool valid(int i, int j) {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf = 2147483647;
        n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        int delRow[4] = {-1, +1, 0, 0};
        int delCol[4] = {0, 0, -1, +1};

        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(grid[row][col] == 0) q.push({row, col, 0});
            }
        }

        while(!q.empty()) {
            auto vec = q.front(); q.pop();
            int row = vec[0], col = vec[1], dis = vec[2];
            for(int i=0; i<4; i++) {
                int nR = row + delRow[i];
                int nC = col + delCol[i];

                if(valid(nR, nC) && grid[nR][nC] == inf) {
                    grid[nR][nC] = min(dis+1, grid[nR][nC]);
                    q.push({nR, nC, dis+1});
                }
            }
        }
    }
};
