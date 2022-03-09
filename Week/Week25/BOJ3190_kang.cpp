#include<iostream>
#include<map>
#include<queue>
#include<tuple>
using namespace std;
int board[100][100];
// 0: empty 1:snake 2: apple
int b_size;
int n_of_Apple;
int L;
map<int, int> operation;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
//         → ↓  ← ↑
// D: +1, L: -1
bool gameover=false;
bool inRange(int x, int y){
    return 0 <= x && x < b_size && 0 <= y && y < b_size;
}
int main(){
    scanf(" %d %d", &b_size, &n_of_Apple);
    for(int i = 0 ; i < n_of_Apple ; i++){
        int x, y;
        scanf(" %d %d", &x, &y);
        x--;y--;
        board[x][y]=2;
    }
    scanf(" %d", &L);
    for(int i = 0 ; i < L ; i++){
        int t;
        char op;
        scanf(" %d %c", &t, &op);
        t++;
        if(op=='D')
            operation.insert({t,1});
        else
            operation.insert({t,-1});
    }
    queue<pair<int, int> > snake;
    snake.push({0,0});
    board[0][0]=1;
    pair<int,int> head, tail;
    int curDir=0;
    int timer = 0;
    while(!gameover){
        head = snake.back();
        tail = snake.front();
        // system("cls");
        // printf("Time: %d\n",timer);
        // for(int i = 0 ; i < b_size ; i++){
        //     for(int j = 0 ; j < b_size ; j++){
        //         printf("%d", board[i][j]);
        //     }
        //     printf("\n");
        // }
        // getchar();
        timer++;
        // move
        // if timer == order
        if(operation[timer]){
            curDir = (4+curDir+operation[timer])%4;
            int nX = head.first+dx[curDir], nY = head.second+dy[curDir];
            // snake hit border or itself
            if(!inRange(nX,nY) || board[nX][nY] == 1){
                gameover=true;
            // if snake can move forward
            }else{
                snake.push({nX,nY});
                //if snake not eat apple
                if(board[nX][nY] != 2){
                    int x,y;
                    tie(x,y) = tail;
                    board[x][y] = 0;
                    snake.pop();
                }
                board[nX][nY] = 1;
            }
        }else{
            int nX = head.first+dx[curDir], nY = head.second+dy[curDir];
            // snake hit border or itself
            if(!inRange(nX,nY) || board[nX][nY] == 1){
                gameover=true;
            // if snake can move forward
            }else{
                snake.push({nX,nY});
                //if snake not eat apple
                if(board[nX][nY] != 2){
                    int x,y;
                    tie(x,y) = tail;
                    board[x][y] = 0;
                    snake.pop();
                }
                board[nX][nY] = 1;
            }
        }
    }
    printf("%d",timer);
}