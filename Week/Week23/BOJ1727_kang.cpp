#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 1000001
using namespace std;

int match[1001][1001];
int dp[1001][1001];
int n,m;
int main(){
    scanf(" %d %d", &n, &m);
    vector<int> male(n);
    vector<int> female(m);
    for(int i = 0 ; i < n ; i++){
        scanf(" %d",&male[i]);
    }
    for(int i = 0 ; i < m ; i++){
        scanf(" %d",&female[i]);
    }
    sort(male.begin(), male.end());
    sort(female.begin(),female.end());
    if(n > m){
        int tmpN;
        vector<int> tmp;
        tmpN = n;
        tmp = male;
        n=m;
        male = female;
        m=tmpN;
        female = tmp;
    }
    // 항상 m을 더 크게 세팅.
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int diff = male[i]-female[j];
            diff = diff > 0 ? diff : diff*-1;
            match[i+1][j+1]=diff;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j ++){
            dp[i][j] = dp[i-1][j-1]+match[i][j];
            if(i>j)
                dp[i][j] = min(dp[i][j],dp[i-1][j]);

            if(i<j)
                dp[i][j] = min(dp[i][j],dp[i][j-1]);
        }
    }
    
    printf("%d",dp[n][m]);
}