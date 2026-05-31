class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        // Push all gates
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 0) {
                    q.push({r,c});
                }
            }
        }

        int dir[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            for(auto &d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                // valid empty room
                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols &&
                   grid[nr][nc] == INT_MAX) {

                    grid[nr][nc] = grid[r][c] + 1;

                    q.push({nr,nc});
                }
            }
        }
    }
};