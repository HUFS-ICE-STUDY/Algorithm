#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int R, C;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<vector<char> > board;
vector<vector<bool> > visited;
deque<char> stack;
bool inRange(int x, int y){
	return 0<= x && x < R && 0 <= y && y < C;
}
int DFS(int x, int y, int path){
	int maxV = path;
	for(int dir = 0 ; dir < 4 ; dir++){
		int nextX, nextY;
		nextX = x+dx[dir];
		nextY = y+dy[dir];
		if(inRange(nextX, nextY) && !visited[nextX][nextY]){
			//if character not found in stack
			if(find(stack.begin(), stack.end(), board[nextX][nextY]) == stack.end()){
				visited[nextX][nextY]=true;
				stack.push_back(board[nextX][nextY]);
				maxV = max(DFS(nextX, nextY, path+1),maxV);
				visited[nextX][nextY]=false;
				stack.pop_back();	
			}
		}
	}
	return maxV;
}
int main(){
	cin >> R >> C;
	board.resize(R, vector<char>(C));
	visited.resize(R,vector<bool>(C));
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			scanf(" %1c",&board[i][j]);
		}
	}
	stack.push_back(board[0][0]);
	visited[0][0] = true;
	printf("%d",DFS(0,0,1));
	return 0;
}
