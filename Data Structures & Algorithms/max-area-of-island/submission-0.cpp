class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    void bfs(int i,int j,vector<vector<int>> &vis, vector<vector<int>> &grid,int &ans){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int cnt=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+delrow[k];
                int nc=c+delcol[k];
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    cnt++;
                    q.push({nr,nc});
                }
            }
        }
        ans=max(ans,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    bfs(i,j,vis,grid,ans);
                }
            }
        }
        return ans;
    }
};