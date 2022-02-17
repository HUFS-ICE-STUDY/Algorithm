#include<iostream>
using namespace std;
int dp[100001][3];
int main(){
    int N;
    cin >> N;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 1;
    for(int i = 1 ; i <= N ; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2])%9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%9901;
    }
    printf("%d",(dp[N][0]+dp[N][1]+dp[N][2])%9901);
}