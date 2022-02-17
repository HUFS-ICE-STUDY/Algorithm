#include<iostream>
#include<vector>
using namespace std;
int N, M;
int map[300][300];
bool visited[300][300];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}
void DFS(int x, int y){
    for(int dir = 0 ; dir < 4 ; dir++){
        int nX = x+dx[dir], nY = y+dy[dir];
        if(inRange(nX,nY) && map[nX][nY] != 0 && !visited[nX][nY]){
            visited[nX][nY] = true;
            DFS(nX, nY);
        }
    }
}
void solution(){
    int year = 1;
    while(year){
        int newMap[300][300];
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                newMap[i][j]=0;
                visited[i][j]=false;
            }
        }
        //먼저 녹이고
        for(int x = 0 ;x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                if(map[x][y] != 0){
                    int melt = 0;
                    //녹이기
                    for(int dir = 0 ; dir < 4 ; dir++){
                        int nX = x+dx[dir], nY = y+dy[dir];
                        if(inRange(nX,nY) && map[nX][nY] == 0)
                            melt++;
                    }
                    int newVal = map[x][y]-melt;
                    newMap[x][y] = newVal > 0 ? newVal : 0;
                }
                if(newMap[x][y] == 0)
                    visited[x][y] = true;
            }
        }
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                map[i][j] = newMap[i][j];
            }
        }
        //빙산 개수 계산
        int iceberg = 0;
        for(int x = 0 ; x < N ; x++){
            for(int y = 0 ; y < M ; y++){
                if(map[x][y]&&!visited[x][y]){
                    visited[x][y]=true;
                    DFS(x, y);
                    iceberg++;
                }
            }
        }
        if(iceberg == 0){
            //빙산이 0개 --> 0 출력
            printf("0");
            return;
        }else if(iceberg == 1){
            //빙산이 1개 --> 다시녹여
            year++;
        }else{
            //빙산이 2개이상 --> 햇수출력
            printf("%d", year);
            return;
        }
        
    }
}
int main(){
    scanf(" %d %d", &N, &M);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf(" %d", &map[i][j]);
        }
    }
    solution();
}