#include<iostream>
#include<vector>
#include<string>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int main(){
	vector<int> answer;
	int T;
	cin >> T;
	for(int i = 0 ; i < T ; i++){
		string control;
		cin >> control;
		int lX, lY, rX, rY; // left X, left Y, right X, right Y
		int curX, curY;
		curX = curY = lX = lY = rX = rY = 0;
		int dir = 0; // 0 ↑, 1 →, 2 ↓, 3 ← 
		for(int i = 0 ; i < control.size() ; i++){
			if(control[i] == 'F'){
				curX += dx[dir];
				curY += dy[dir];
			}
			else if(control[i] == 'B'){
				curX -= dx[dir];
				curY -= dy[dir];
			}
			else if(control[i] == 'L'){
				dir--;
				dir = dir < 0 ? 4+dir : dir;
			}
			else{ //ctl == 'R
				dir = (dir+1)%4;
			}
			if(lX > curX)
				lX = curX;
			if(lY > curY)
				lY = curY;
			if(rX < curX)
				rX = curX;
			if(rY < curY)
				rY = curY;
		}
		answer.push_back((rX-lX)*(rY-lY));
	}
	for(int i = 0 ; i < answer.size() ; i++){
		printf("%d\n",answer[i]);
	}
}