#include<iostream>
#include<algorithm>
#define INT_MAX 16000000
int N;
int W[16][16];
int dp[1<<16][16];
int TSP(int curNode, int visited){
    // printf("%d\n",curNode);
    int &ret = dp[visited][curNode];
    if(ret!=INT_MAX)
        return ret;
    if(visited == (1<<N)-1){
        if(W[curNode][0] != 0)
            return W[curNode][0];
        return INT_MAX;
    }
    for(int nextNode = 0 ; nextNode < N ; nextNode++){
        // 다음 노드를 방문했거나 또는 길이 없는 경우 continue
        if(visited & 1<<nextNode || W[curNode][nextNode] == 0)
            continue;
        ret = std::min(ret, TSP(nextNode, visited|(1<<nextNode)) + W[curNode][nextNode]);
    }
    return ret;
}
int main(){
    scanf(" %d", &N);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf(" %d",&W[i][j]);
        }
    }
    for(int i = 0 ; i < 1<<N ; i++){
        for(int j = 0 ; j < N ; j++){
            dp[i][j]=INT_MAX;
        }
    }
    printf("%d", TSP(0,1));
}