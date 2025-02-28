class Solution {
public:
    bool topologicalSort(int n, vector<int> &indegree, vector<vector<int>>& prerequisites){
        vector<vector<int>> adjList(n);
        vector<int> ans;
        for(auto &edges: prerequisites){
            adjList[edges[1]].push_back(edges[0]);
        }

        for(int i=0; i<n; i++){
            for(int x: adjList[i]){
                indegree[x]+=1;
            }
        }

        queue<int> queue;
        for(int i=0; i<n;i++){
            if(indegree[i]==0)
                queue.push(i);
        }
        while(!queue.empty()){
            int front = queue.front();
            queue.pop();
            ans.push_back(front);
            for(int neighbour: adjList[front]){
                indegree[neighbour] --;
                if(indegree[neighbour] == 0){
                    queue.push(neighbour);
                }
            }
        }
        if(ans.size()!=n){
            return false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        return topologicalSort(numCourses, indegree, prerequisites);
    }
    
};