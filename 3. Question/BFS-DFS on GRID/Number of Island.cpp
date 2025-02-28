class Solution {
public:
    int m,n;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    void bfs(int i, int j, vector<vector<char>>& grid){
        queue<pair<int,int>> queue;
        queue.push({i,j});
        grid[i][j] = '2';
        while(!queue.empty()){
            pair<int,int> front = queue.front(); queue.pop();
            int a= front.first, b= front.second;
            for(int k=0; k<4;k++){
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
    
    // void dfs(int i,int j, vector<vector<char>>& grid){
    //     if(i<0 or j<0 or i>=m or j>=n or grid[i][j]!='1'){
    //         return;
    //     }
    //     grid[i][j] = '2';
    //     for(int k=0; k<4; k++){
    //         int ii = i + dx[k];
    //         int jj = j + dy[k];
    //         dfs(ii,jj, grid);
    //     }
    // }

    int numIslands(vector<vector<char>>& grid) {
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