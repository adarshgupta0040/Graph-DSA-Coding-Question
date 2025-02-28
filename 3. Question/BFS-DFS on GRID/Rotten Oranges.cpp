class Solution {
public:
    int dx[4] ={1,0, -1, 0}; //to get adjacent
    int dy[4] ={0,-1, 0, 1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        int ans=0;
        queue<pair<int, int>> queue;
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    queue.push({i,j});
                }
            }
        }
        while( !queue.empty()){
            int qsize= queue.size();
            int temp=0;
            while(qsize){
                auto front = queue.front(); queue.pop();
                int i= front.first, j = front.second;
                for(int k=0; k<4; k++){
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if(ii >= 0 and jj >= 0 and ii < m and jj < n and grid[ii][jj] == 1){
                        grid[ii][jj] = 2;
                        queue.push({ii,jj});
                        temp = 1;
                    }
                }
                qsize --;
            }
            ans += temp;
        }

        for(auto i: grid){
            for(int j: i){
                if(j==1) return -1;
            }
        }
        return ans;

    }
};