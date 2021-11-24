#include<iostream> 
#include<vector>
using namespace std;
int main(){
	
	vector<long> dp(1000001);
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	/*
	dp[n]은 dp[n-1]의 가지수에 + 1 씩 더해주는것과
			dp[n-2]의 가지수에 + 2 씩 더해주는것과
			dp[n-3]의 가지수에 + 3 씩 더해주는것의 합으로 이뤄진다. 
	*/
	for(int n = 4 ; n <1000001 ; n++){
		dp[n] = (dp[n-1] + dp[n-2] + dp[n-3])%1000000009;
	}
	int N;
	cin >> N;
	int dpN;
	for(int i = 0 ; i < N ; i++){
		cin>>dpN;
		cout<<dp[dpN]<<endl;
	}
}
