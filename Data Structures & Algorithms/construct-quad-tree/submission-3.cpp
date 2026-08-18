/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    int check(int i1, int j1, int i2, int j2, vector<vector<int>>& grid) {
        int ones = 0, zeros = 0;
        for(int i = i1; i <= i2; i++) {
            for(int j = j1; j <= j2; j++) {
                if(grid[i][j]) ones++;
                else zeros++;
            }
        }
        if(zeros && ones) return -1;
        return zeros ? 0 : 1;
    }
    Node* f(int i1, int j1, int i2, int j2, vector<vector<int>>& grid) {
        int val = check(i1, j1, i2, j2, grid);
        if(val != -1) return new Node(val, true);
        
        int xi = (i1+i2)/2;
        int xj = (j1+j2)/2;

        return new Node(false, false,
            f(i1, j1, xi, xj, grid),
            f(i1, xj+1, xi, j2, grid),
            f(xi+1, j1, i2, xj, grid),
            f(xi+1, xj+1, i2, j2, grid)
        );
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        int i1 = 0, j1 = 0, i2 = n-1, j2 = n-1;
        return f(0, 0, n-1, n-1, grid);
    }
};