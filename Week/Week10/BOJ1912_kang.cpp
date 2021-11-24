#include<iostream>
#include<climits>
#define MAX(x,y) (x > y ? x : y)
using namespace std;
int main(){
	int N;
	cin >> N;
	int dp[N]={INT_MIN,};
	cin >>dp[0];
	for(int n = 1 ; n < N ; n++){
		cin >> dp[n];
		dp[n]=MAX(dp[n],dp[n]+dp[n-1]);
	}
	int max = INT_MIN;
	for(int i = 0 ; i < N ; i++){
		max = MAX(max, dp[i]);
	}
	cout<<max;
}