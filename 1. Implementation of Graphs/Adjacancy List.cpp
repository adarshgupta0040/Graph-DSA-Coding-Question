#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adjacancyListmp; //GlobalDeclare

void bfs(int sourceNode, int n){
    queue<int> queue;
    queue.push(sourceNode);
    vector<int>visited(n+1, 0);
    visited[sourceNode] = 1;
    while(!queue.empty()){
        int front = q.front(); 
        q.pop();
        cout<< front << " ";
        for(int neighbour: adjacancyListmp[front]){
            if(!visited[neighbour]){
                queue.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
}
void adjacancyList(vector<vector<int> >graph, int n){
    
// 	unordered_map<int, vector<int>> adjacancyListmp;
	for(int i=0;i< n; i++){
			int a = graph[i][0], b= graph[i][1];
			adjacancyListmp[a].push_back(b);
			adjacancyListmp[b].push_back(a);
		}
	
	// Printing Adjacancy List
	for(auto x:adjacancyListmp){
		cout<< x.first << " --> ";
		for(int nodeValue : x.second){
			
				cout<< nodeValue <<" ";
		}
		cout<<endl;
	}
	
}
void AdjacancyMatrix(vector<vector<int> >graph, int n){
	vector<vector<int> > AdjMatrix(5, vector<int>(5,0));
	for(int i=0;i< n; i++){
			int a = graph[i][0], b= graph[i][1];
		    AdjMatrix[a][b]=1;
			cout<<a<<" "<< b<<endl;
			AdjMatrix[b][a]=1;
		}

	//Printing Adjacancy Matrix
	for(int i=0;i< n; i++){
		for(int j=0; j<n; j++){
		    cout<< AdjMatrix[i][j];
		}
		cout<<endl;
	}
	
	// Visualise Adjacancy Matrix
	for(int i=1;i< n; i++){
		cout<< i << " --> ";
		for(int j=1; j<n; j++){
			if(AdjMatrix[i][j]==1)
				cout<< j<<" ";
		}
		cout<<endl;
	}
	
}
int main(){
	vector<vector<int> >graph = {{1,2},{2,3},{3,4},{4,2},{1,3}};

	int n = graph.size();
	adjacancyList(graph,n);
	bfs(1, n);
	
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//
//void adjacancyList(vector<vector<int> >graph, int n){
//    
//	unordered_map<int, vector<int>> adjacancyListmp;
//	for(int i=0;i< n; i++){
//			int a = graph[i][0], b= graph[i][1];
//			adjacancyListmp[a].push_back(b);
//			adjacancyListmp[b].push_back(a);
//		}
//	
//	// Printing Adjacancy List
//	for(auto x:adjacancyListmp){
//		cout<< x.first << " --> ";
//		for(int nodeValue : x.second){
//			
//				cout<< nodeValue <<" ";
//		}
//		cout<<endl;
//	}
//	
//}
//void AdjacancyMatrix(vector<vector<int> >graph, int n){
//	vector<vector<int> > AdjMatrix(5, vector<int>(5,0));
//	for(int i=0;i< n; i++){
//			int a = graph[i][0], b= graph[i][1];
//		    AdjMatrix[a][b]=1;
//			cout<<a<<" "<< b<<endl;
//			AdjMatrix[b][a]=1;
//		}
//
//	//Printing Adjacancy Matrix
//	for(int i=0;i< n; i++){
//		for(int j=0; j<n; j++){
//		    cout<< AdjMatrix[i][j];
//		}
//		cout<<endl;
//	}
//	
//	// Visualise Adjacancy Matrix
//	for(int i=1;i< n; i++){
//		cout<< i << " --> ";
//		for(int j=1; j<n; j++){
//			if(AdjMatrix[i][j]==1)
//				cout<< j<<" ";
//		}
//		cout<<endl;
//	}
//	
//}
//int main(){
//	vector<vector<int> >graph = {{1,2},{2,3},{3,4},{4,2},{1,3}};
//
//	int n = graph.size();
//	adjacancyList(graph,n);
//	
//	return 0;
//}
