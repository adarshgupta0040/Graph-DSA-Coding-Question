void dfs(vector<vector<int>> &adjList, vector<int> &visited, int startNode){
        visited[startNode] = 1;
        for(auto neighbour: adjList[startNode]){
            if(!visited[neighbour]){
                dfs(adjList, visited, neighbour);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int> visited(n,0);
        vector<vector<int>> adjList(n);
        for(auto &v: connections){
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
        }
        int components =0;
        for(int i=0; i<n;i++){
            if(!visited[i]){
                cout<< i;
                dfs(adjList, visited, i);
                components++;
            }
        }
        return components-1;

    }