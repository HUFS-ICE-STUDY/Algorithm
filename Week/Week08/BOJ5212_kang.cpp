#include <iostream>

using namespace std;

char map[10][10];
				
char nextMap[10][10];
				
int R, C;

bool inRange(int x, int y){
	return 0 <= x and x < R and 0 <= y and y < C;
}

// function to figureout the land is drown or not
// run function only when location is land.

bool isDrown(int x, int y){
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	//drown count
	int d_count = 0;
	for(int dir = 0 ; dir < 4 ; dir++){
		int near_x = x + dx[dir];
		int near_y = y + dy[dir];
		if(!inRange(near_x, near_y))
			d_count++;
		else if(map[near_x][near_y] == '.')
			d_count++;
	}
	return d_count >= 3;
}

int main(){
	
	cin >> R >> C;
	
	//input about original map
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			cin >> map[i][j];
		}
	}
	
	// location for print
	int x_top = 10;
	int y_top = 10;
	int x_bot = 0;
	int y_bot = 0;
	
	//update nextMap every step by step
	for(int x = 0 ; x < R ; x++){
		for(int y = 0 ; y < C ; y++){
			if(map[x][y] == '.'){
				nextMap[x][y] = '.';
				continue;
			}
			if(!isDrown(x,y)){
				nextMap[x][y] = 'X';
				
				// find corner location of map.
				if(x_top > x)
					x_top = x;
				if(y_top > y)
					y_top = y;
				if(x_bot < x)
					x_bot = x;
				if(y_bot < y)
					y_bot = y;
			}
			else
				nextMap[x][y] = '.';
		}
	}

	for(int i = x_top ; i <= x_bot ; i++){
		for(int j = y_top ; j <= y_bot ; j++){
			cout << nextMap[i][j];
		}
		cout << endl;
	}
	
}
