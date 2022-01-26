#include<iostream>
using namespace std;
int n,m;
int board[500][500];
bool visited[500][500];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int maxVal=0;
bool inRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}
void DFS(int x, int y, int val){
    visited[x][y]=true;
    board[x][y] = val;
    maxVal++;
    for(int dir = 0 ; dir < 4 ; dir++){
        int nX,nY;
        nX=x+dx[dir];
        nY=y+dy[dir];
        if(inRange(nX,nY)&&!visited[nX][nY]){
            DFS(nX,nY,val+1); 
        }
    }
}
int main(){
    cin >> n >> m;
    int returnVal=0;
    int picNum=0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> board[i][j];
            if(!board[i][j])
                visited[i][j]=true;
        }
    }
    for(int col = 0 ; col < n ; col++){
        for(int row = 0 ; row < m ; row++){
            if(!visited[col][row]){
                DFS(col, row, 1);
                returnVal = returnVal < maxVal ? maxVal : returnVal;
                maxVal = 0;
                picNum++;
            }
        }
    }
    printf("%d\n%d",picNum,returnVal);
}