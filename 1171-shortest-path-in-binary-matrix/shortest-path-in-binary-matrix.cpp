class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // अगर start या end blocked है
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        // 8 directions
        vector<pair<int,int>> dir = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        grid[0][0] = 1; // mark visited
        int pathLength = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                
                if (x == n-1 && y == n-1) return pathLength;
                
                for (auto &d : dir) {
                    int nx = x + d.first;
                    int ny = y + d.second;
                    
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                        q.push({nx, ny});
                        grid[nx][ny] = 1; // visited mark
                    }
                }
            }
            
            pathLength++;
        }
        
        return -1;
    }
};