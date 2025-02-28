class Solution {
  public:
  
    deque<int>dq;
    void dfs(int startNode, vector<int> &visited, vector<vector<int>>& adjList){
        visited[startNode] = 1;
        for(int neighbour: adjList[startNode]){
            if(!visited[neighbour] ){
                dfs(neighbour, visited, adjList);
            }
        }
        dq.push_front(startNode);
    }
    
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        //DFS
        int n = adj.size();
        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            if(!visited[i])
                dfs(i, visited, adj);
        }
        
        vector<int> ans;
        for(auto &node : dq){
            ans.push_back(node);
        }
        
        return ans;
    }
};