// } Driver Code Ends
class Solution 
{
    public:
    
    vector<vector<int>> possibleCoordinates = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
    
    int BFS(int srcX, int srcY, int tarX, int tarY, int n){
        vector<vector<int>> visited(n, vector<int>(n,0));
        queue<pair<int,int>> queue;
        queue.push({srcX,srcY});
        visited[srcX][srcY] = 1;
        int steps =0;
        while(!queue.empty()){
            int qSize = queue.size();
            while(qSize>0){
                pair<int,int> front=queue.front();  queue.pop();
                int x= front.first, y = front.second;
                if(x==tarX and y==tarY) 
                    return steps;
                
                for(int i=0; i<possibleCoordinates.size();i++){
                    int newX= x + possibleCoordinates[i][0];
                    int newY = y+ possibleCoordinates[i][1];
                    if(newX>=0 and newY>=0 and newX<n and newY<n and !visited[newX][newY] ){
                        queue.push({newX,newY});
                        visited[newX][newY] = 1;
                    }
                }
                qSize--;
            }
            
            steps++;
            
        }
        
    }
    
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Covert to matrix form
	    int srcX = N- KnightPos[1], srcY=KnightPos[0]-1;
	    int tarX= N- TargetPos[1], tarY= TargetPos[0]-1;
	    
	    return BFS(srcX, srcY, tarX, tarY, N);
	}
};