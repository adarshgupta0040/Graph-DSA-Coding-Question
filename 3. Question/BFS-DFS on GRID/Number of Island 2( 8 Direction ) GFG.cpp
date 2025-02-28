class Solution {
  public:
    int m,n;
    int dx[8]={-1,0,1,0, -1,+1,1,-1};
    int dy[8]={0,1,0,-1, 1,1,-1,-1};

    void bfs(int i, int j, vector<vector<char>>& grid){
        queue<pair<int,int>> queue;
        queue.push({i,j});
        grid[i][j] = '2';
        while(!queue.empty()){
            pair<int,int> front = queue.front(); queue.pop();
            int a= front.first, b= front.second;
            for(int k=0; k<8;k++){
                int ii = a + dx[k];
                int jj = b + dy[k];
                if(ii<0 or jj<0 or ii>=m or jj>= n or grid[ii][jj] != '1'){
                    continue;
                }
                queue.push({ii,jj});
                grid[ii][jj] = '2';
            }
        }
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        m= grid.size(), n= grid[0].size();
        int island =0;
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]=='1'){
                    bfs(i,j, grid);
                    island +=1;
                }
            }
        }
        return island;
    }
};