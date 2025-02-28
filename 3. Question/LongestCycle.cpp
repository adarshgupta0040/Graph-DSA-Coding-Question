class Solution {
public:
    int longestCycleLen =-1;
    void dfs(int cycleLen, int startNode, vector<int> & visited, vector<int> &currentPath, vector<int>& edges ){
        cycleLen++;
        currentPath[startNode] = cycleLen;
        visited[startNode] = 1;
        
        int neighbour = edges[startNode];
        if(neighbour != -1){
            if(!visited[neighbour]){
                dfs(cycleLen, neighbour, visited, currentPath, edges);
            }
            else{
                if(currentPath[neighbour] != 0){
                    int currentCycleLen = currentPath[startNode] - currentPath[neighbour]+1;
                    longestCycleLen = max(longestCycleLen,currentCycleLen);
                }
            }
        }
        currentPath[startNode] =0;
    }
    int longestCycle(vector<int>& edges) {
        int V= edges.size();
        vector<int> visited(V,0), currentPath(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(0, i, visited, currentPath, edges);
            }
        }
        return longestCycleLen;
    }
};