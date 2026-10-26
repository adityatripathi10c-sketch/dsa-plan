class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if(grid.empty()||grid[0].empty())return 0;
        int m=grid.size(),n=grid[0].size(),ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    long long total=dfs(i,j,m,n,grid);
                        if(total%k==0){
                            ans++;
                        }
                    }
                }
            }
        
        return ans;
    }
    long long dfs(int i,int j,int m,int n,vector<vector<int>>&grid){
        if (i<0||i>=m||j<0||j>=n||grid[i][j]==0){
            return 0;
        }
        long long sum = grid[i][j];
        grid[i][j] = 0; 
        
        sum += dfs(i + 1, j, m, n,grid);
        sum += dfs(i - 1, j, m, n,grid);
        sum += dfs(i, j + 1, m, n,grid);
        sum += dfs(i, j - 1, m, n,grid);
        
        return sum;
    }
};