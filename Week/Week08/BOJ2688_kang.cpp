#include <iostream>

using namespace std;

long dp[1001][10]={{1,1,1,1,1,1,1,1,1,1},};
int T;

int main(){
	cin >> T;
	for(int n = 1 ; n < 1001 ; n++){
		for(int num = 0 ; num < 10 ; num++){
			if(num == 0){
				long sum = 0;
				for(int i = 0 ; i < 10 ; i++){
					sum += dp[n-1][i];
				}
				dp[n][0] = sum;
			}
			else{
				dp[n][num] = dp[n][num-1] - dp[n-1][num-1];
			}
		}
	}
	int num;
	for(int i = 0 ; i < T ; i++){
		cin >> num;
		cout << dp[num][0] <<endl;
	}
}
