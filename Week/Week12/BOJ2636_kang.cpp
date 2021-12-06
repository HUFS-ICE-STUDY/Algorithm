#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
int dish[100][100];
vector<vector<bool> > visited;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int cheese=0;
queue<pair<int, int> > que;
int X, Y;
bool inRange(int x, int y){
	return 0<=x&&x<X&&0<=y&&y<Y;
}
int bfs(){
	//clean up visited
	for(int i = 0 ; i < X ; i++){
		for(int j = 0 ; j < Y ; j++){
			visited[i][j]=false;
		}
	}
	que.push(make_pair(0,0));
	que.push(make_pair(0,Y-1));
	que.push(make_pair(X-1,Y-1));
	que.push(make_pair(X-1,0));
	int sideCheese=0;
    visited[0][0]=true;
    visited[0][Y-1]=true;
    visited[X-1][Y-1]=true;
    visited[X-1][0]=true;
	while(!que.empty()){
		int curX,curY;
		tie(curX,curY) = que.front();
		que.pop();
		for(int i = 0 ; i < 4 ; i++){
			int nextX,nextY;
			nextX=curX+dx[i];
			nextY=curY+dy[i];
			if(inRange(nextX,nextY)&&!visited[nextX][nextY]){
				/*
				if next location is cheese
				dont push to queue, but mark as visited.
				*/
				visited[nextX][nextY]=true;
				if(dish[nextX][nextY] == 1){
					dish[nextX][nextY]=0;
					sideCheese++;
				}else{
					que.push(make_pair(nextX,nextY));
				}
			}
		}
		
	}
	return sideCheese;
}
int main(){
	cin >> X >> Y;
	visited.resize(X,vector<bool>(Y,false));
	for(int i = 0 ; i < X ; i++){
		for(int j = 0 ; j < Y ; j++){
			cin >> dish[i][j];
			if(dish[i][j] == 1)
				++cheese;
		}
	}
	
	int prevCheese=0;
	int time = 0;
//	cout<<"current Cheese: "<<cheese<<endl;
	while(cheese>0){
		prevCheese = cheese;
		int melt=bfs();
		cheese = cheese-melt;
//		printf("current Cheese: %d, prevCheese: %d\n", cheese, prevCheese);
		time++;
	}
	printf("%d\n%d",time,prevCheese);
	return 0;
}
