#include<iostream>
using namespace std;
int dp[101][12];
int main(){
	for(int i = 0 ; i < 10 ; i++){
		dp[1][i+1]=1;
	}
	for(int i = 2 ; i < 101 ; i++){
		for(int j = 1 ; j < 11 ; j++){
			dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
		}
	}
	int N;
	cin >> N;
	int answer = 0;
	for(int i = 2 ; i < 11 ; i++){
		answer = (answer+dp[N][i])%1000000000;
	}
	cout<<answer;
}
