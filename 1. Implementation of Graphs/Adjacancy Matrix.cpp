// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

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
	AdjacancyMatrix(graph,n);
	
	return 0;
}
