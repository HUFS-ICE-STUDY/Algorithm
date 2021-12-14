#include<iostream>
#include<vector>
using namespace std;
int N, M;
int coins[100][100];
void makeFlip(int x, int y){
	for(int i = 0 ; i <= x ; i++){
		for(int j = 0 ; j <= y ; j++){
			if(coins[i][j] == 0)
				coins[i][j] = 1;
			else
				coins[i][j] = 0;
		}
	}
}
int main(){
	int flip=0;
	
	cin>>N>>M;
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			scanf("%1d",&coins[i][j]);
		}
		getchar();
	}

	for(int x = N-1 ; x >= 0 ; x--){
		for(int y = M-1 ; y >= 0 ; y--){
			if(coins[x][y] == 1){
				makeFlip(x,y);
				flip++;
			}
		}
	}
	cout<<flip;
}
