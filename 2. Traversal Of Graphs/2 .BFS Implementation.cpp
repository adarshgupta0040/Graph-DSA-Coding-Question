class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        int n =  adj.size();
        queue<int> queue;
        vector<int> visited(n+1, 0);
        queue.push(0);
        visited[0] =1;
        while( !queue.empty() ){
            int front = queue.front();
            queue.pop();
            ans.push_back(front);
            for(int neighbour: adj[front]){
                if( !visited[neighbour]){
                    queue.push(neighbour);
                    visited[neighbour] =1;
                }
            }
        }
        return ans;
    }
};