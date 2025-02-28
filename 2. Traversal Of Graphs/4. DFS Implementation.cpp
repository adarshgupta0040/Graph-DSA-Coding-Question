class Solution {
  public:
    vector<int > ans;
    vector<int> dfs(int startNode, int n, vector<vector<int>>& adjList, vector<int> & visited){
        ans.push_back(startNode);
        visited[startNode] = 1;
        for(int neighbour: adjList[startNode]){
            if(! visited[neighbour]){
                dfs(neighbour, n, adjList, visited);
                
            }
        }
        return ans;
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<int> visited(n+1,0);
        return dfs(0,  n, adj,visited);
        
    }
};