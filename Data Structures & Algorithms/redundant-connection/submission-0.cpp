class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int findUlPar(int i) {
        if(i == parent[i]) return i;
        return parent[i] = findUlPar(parent[i]);
    }
    void unionBySize(int i, int j) {
        int pi = findUlPar(i);
        int pj = findUlPar(j);
        if(pi == pj) return;

        if(size[pi] > size[pj]) {
            parent[pj] = pi;
            size[pi] += size[pj];
        } else {
            parent[pi] = pj;
            size[pj] += size[pi];
        }
    }
    bool isConnected(int i, int j) {
        return (findUlPar(i) == findUlPar(j));
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU ds(n+1);
        pair<int, int> ans;
        for(auto& it: edges) {
            int u = it[0], v = it[1];
            if(ds.isConnected(u, v)) ans = {u, v};
            else ds.unionBySize(u, v);
        }
        return {ans.first, ans.second};
    }
};
