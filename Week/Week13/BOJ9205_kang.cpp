#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstdlib>
using namespace std;
typedef pair<int, int> pii;
vector<pii> convList;
vector<bool> visited; // 0 --> start idx, last --> destination idx
void BFS(int sX, int sY){
	queue<pii> q;
	q.push({sX,sY});
	
	while(!q.empty()){
		int curX, curY;
		tie(curX, curY) = q.front();
		q.pop();
		for(int i = 0 ; i < convList.size() ; i++){
			int cX, cY;
			tie(cX,cY)=convList[i];
			if(!visited[i] && (abs(cX-curX))+abs(cY-curY) <= 1000){
				visited[i]=true;
				q.push({cX,cY});
			}
		}
	}
	if(visited[convList.size()-1]==true){
		printf("happy\n");
	}
	else
		printf("sad\n");
}
int main(){
	int T;
	cin >> T;
	while (T--){
		int conv, sX, sY, dX, dY;
		cin >> conv;
		cin >> sX >> sY;
		while(conv--){
			int cX, cY;
			cin >> cX >> cY;
			convList.push_back(make_pair(cX, cY));
			visited.push_back(false);
		}
		cin >> dX >> dY;
		convList.push_back({dX, dY});
		visited.push_back(false);
		BFS(sX,sY);
		visited.clear();
		convList.clear();
	}
}
