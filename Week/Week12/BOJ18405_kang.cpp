#include<iostream>
#include<map>
#include<queue>
#include<tuple>
using namespace std;
int tube[201][201];
map<int, queue<pair<int, int> > > viruses;
int N, K;
int S, X, Y;
bool inRange(int x, int y){
	return 0 < x && x <= N && 0 < y && y <= N;
}
void spread(int virus){
	int dx[4] = {-1,0,1,0};
	int dy[4] = {0,-1,0,1};
	if(viruses[virus].empty()){
		return;
	}
	queue<pair<int, int> > new_list;
	
	while(!viruses[virus].empty()){
		int x, y;
		tie(x,y) = viruses[virus].front();
		viruses[virus].pop();
		int n_x,n_y;
		for(int i = 0 ; i < 4 ; i++){
			n_x = x+dx[i];
			n_y = y+dy[i];
			if(inRange(n_x, n_y)){
				if(tube[n_x][n_y]==0){
					new_list.push(make_pair(n_x, n_y));
					tube[n_x][n_y] = virus;
				}
			}
		}
	}
	viruses[virus] = new_list;
}
int main(){
	cin >> N >> K;
	for(int i = 1 ; i <= K ; i++){
		queue<pair<int, int> > tmp;
		viruses[i] = tmp;
	}
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> tube[i][j];
			int virus = tube[i][j];
			// if input is virus
			if(virus != 0){
				viruses[virus].push(make_pair(i,j));
			}
		}
	}
	cin >> S >> X >> Y;
	while(S>0){
		for(int virus = 1 ; virus <= K ; virus++){
			spread(virus);
		}
		if(tube[X][Y]!=0){
			cout<<tube[X][Y];
			return 0;
		}
		S--;
	}
	cout<<tube[X][Y];
	return 0;
}
