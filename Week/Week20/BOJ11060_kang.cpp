#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int maze[1500];
int dp[1500];
int N;
int main(){
    cin >> N;
    for(int i = 1 ; i < N+100 ; i++){
        dp[i] = 1001;
    }
    for(int i = 0 ; i < N ; i++){
        cin>>maze[i];
        for(int j = i+1 ; j < i+maze[i]+1 ; j++){
            dp[j] = min(dp[i]+1,dp[j]);
        }
    }
    if(dp[N-1] == 1001)
        printf("-1");
    else
        printf("%d",dp[N-1]);

}