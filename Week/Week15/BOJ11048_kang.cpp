#include<iostream>
#include<algorithm>
using namespace std;
int map[1000][1000];
int N, M;
bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}
int main(){
    scanf("%d %d",&N, &M);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf(" %d", &map[i][j]);
        }
    }
    for(int x = 0 ; x < N ; x++){
        for(int y = 0 ; y < M ; y++){
            // upper, left, diagnoal
            int uX, uY, lX, lY, dX, dY;
            uX = x-1; uY = y;
            lX = x;   lY = y-1;
            dX = x-1; dY = y-1;
            int uV=0, lV=0, dV=0;
            if(inRange(uX, uY))
                uV = map[uX][uY];
            if(inRange(lX, lY))
                lV = map[lX][lY];
            if(inRange(dX, dY))
                dV = map[dX][dY];
            map[x][y] += max({uV, lV, dV});
        }
    }
    printf("%d", map[N-1][M-1]);
}