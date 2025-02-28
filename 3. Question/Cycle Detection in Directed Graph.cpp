//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int startNode, vector<int>& visited, vector<int>& currentPath, vector<vector<int>>& adjList) {
        visited[startNode] = 1;
        currentPath[startNode] = 1;

        for (auto neighbour : adjList[startNode]) {
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

    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> visited(V,0), currentPath(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans = dfs(i, visited, currentPath, adj);
                if(ans == true) return true;
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends