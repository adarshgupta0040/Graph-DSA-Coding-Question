class Solution {
public:
    // Global
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    int m, n;

    void bfs(int i, int j, int originalValue, int color, vector<vector<int>>& image){
        queue<pair<int,int>> queue;
        queue.push({i,j});
        image[i][j] = color;
        while(!queue.empty()){
            pair<int,int> front = queue.front(); queue.pop();
            int a= front.first, b= front.second;
            for(int k=0; k<4;k++){
                int ii = a + dx[k];
                int jj = b + dy[k];
                if(ii<0 or jj<0 or ii>=m or jj>= n or image[ii][jj] != originalValue){
                    continue;
                }
                queue.push({ii,jj});
                image[ii][jj] = color;
            }
        }
    }

    // void dfs(int i, int j, int originalValue, int color, vector<vector<int>>& image){
    //     if(i<0 or j<0 or i>=m or j>= n or image[i][j]!= originalValue) return;

    //     image[i][j] = color;
    //     for(int k=0; k<4;k++){
    //         int ii = i + dx[k];         //exploring Neighbour
    //         int jj = j + dy[k];
    //         dfs(ii,jj, originalValue, color, image);
    //     }
    // }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m= image.size(), n= image[0].size();
        int originalValue = image[sr][sc];
        if(originalValue == color) return image;

        bfs(sr,sc,originalValue, color, image);
        return image;
    }
};