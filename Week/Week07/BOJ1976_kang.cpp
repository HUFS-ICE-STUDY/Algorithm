#include <iostream>
#include <vector>

using namespace std;

int graph[201][201] = {0,};
int visited[201] = {false,};

int N,M;

void DFS(int node){
	visited[node]=true;
	for(int i = 1 ; i <= N ; i++){
		if(graph[node][i]==1)
			if(!visited[i])
				DFS(i);
	}
}
int main(){
	
	cin >> N >> M;
	int edge;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> edge;
			graph[i][j]=edge;
			graph[j][i]=edge;
		}
	}
	vector<int> route;
	int visit;
	for(int i = 0 ; i < M ; i++){
		cin >> visit;
		route.push_back(visit);
	}
	DFS(route[0]);
	for(int i = 0 ; i < route.size() ; i++){
		if(!visited[route[i]]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
