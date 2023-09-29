class Solution {
    
  public:
  void solve(vector<vector<int>>&grid,int x,int y){
        int m=grid[0].size();
        int n=grid.size();
        grid[x][y]=2;
        if(x+1<n && grid[x+1][y]==1){
            solve(grid,x+1,y);
        }
        if(y-1>=0 && grid[x][y-1]==1){
            solve(grid,x,y-1);
        }
        if(x-1>=0 && grid[x-1][y]==1){
            solve(grid,x-1,y);
        }
        if(y+1<m && grid[x][y+1]==1){
            solve(grid,x,y+1);
        }
        return;
    }
    int check(vector<vector<int>>&grid){
        int count=0;
        for(auto i:grid){
            for(auto j:i){
                if(j==1){
                    count++;
                }
            }
        }
        return count;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m=grid[0].size();
        int n=grid.size();
        int i,j;
        for(i=0;i<n;i++){
            if(grid[i][0]==1){
                solve(grid,i,0);
            }
            if(grid[i][m-1]==1){
                solve(grid,i,m-1);
            }
        }
        for(i=0;i<m;i++){
            if(grid[0][i]==1){
                solve(grid,0,i);
            }
            if(grid[n-1][i]==1){
                solve(grid,n-1,i);
            }
        }
        return check(grid);
    }
};