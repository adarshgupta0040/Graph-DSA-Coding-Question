class Solution {
  public:
    bool dfs(int startNode, vector<int>& visited, vector<int>& currentPath, vector<int> adjList[]) {
        visited[startNode] = 1;
        currentPath[startNode] = 1;

        for (auto &neighbour : adjList[startNode]) {
            if (!visited[neighbour]) {
                bool ans = dfs(neighbour, visited, currentPath, adjList);
                if (ans == true) {
                    return true;
                }
            } else {
                if (currentPath[neighbour]) {  
                    return true;
                }
            }
        }
        currentPath[startNode] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> currentPath(V,0);
        // vector<vector<int>> adjList(V);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                int ans = dfs(i, visited, currentPath, adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(currentPath[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};