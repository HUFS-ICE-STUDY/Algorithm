#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, K;
int dp[100001][101];
int main(){
    scanf(" %d %d", &N,&K);
    pii items[101];
    for(int i = 1 ; i <= N ; i++){
        int W, V;
        scanf(" %d %d",&W ,&V);
        items[i] = {W,V};
    }
    for(int item = 1 ; item <= N ; item++){
        for(int weight = 1 ; weight <= K ; weight++){
            if(items[item].first <= weight){
                dp[weight][item] = max(items[item].second + dp[weight-items[item].first][item-1], dp[weight][item-1]);
            }
            else{
                dp[weight][item] = dp[weight][item-1];
            }
        }
    }
    printf("%d",dp[K][N]);

}