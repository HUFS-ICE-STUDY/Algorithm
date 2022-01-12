#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
vector<pii> toFill;
int sudoku[9][9];
bool isSatisfy(int x, int y, int num){
    // check in row
    for(int i = 0 ; i < 9 ; i++){
        if(num == sudoku[x][i] || num ==sudoku[i][y])
            return false;
    }
    int xStart = (x/3)*3;
    int yStart = (y/3)*3;
    for(int cx = xStart ; cx < xStart+3 ; cx++){
        for(int cy = yStart ; cy < yStart+3; cy++){
            if(num == sudoku[cx][cy])
                return false;
        }
    }
    return true;
}

void printSudoku(){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void solve(int idx){
    if(idx == toFill.size()){
        printSudoku();
        exit(0);
    }
    for(int num = 1 ; num < 10 ; num++){
        int x, y;
        tie(x,y) = toFill[idx];
        if(isSatisfy(x,y,num)){
            sudoku[x][y]=num;
            solve(idx+1);
            sudoku[x][y]=0;
        }
    }
    /*
    이거를 거꾸로 생각하는데 애 많이 먹었다...
    각 단계(재귀) 가 애초에 각 빈칸을 의미하게 했어야했는데
    재귀때마다 모든 빈칸좌표들을 체크했다 --> 시간초과
    대충 루프 돌아가는 시간이 최대 81^81번 정도 돌아간다....
    풀이의 경우에는 최대 9^81번정도이다.(Satisfy 함수 미포함)(선행 종료조건때문에 9^81보다는 훨씬 작을것.)
    또한 전체 경우의 수가 아닌 만족한 첫번째만 출력하므로, 9^81번보다는 훨씬 적은 숫자로 동작할 것이다.
    for(int i = 0 ; i < toFill.size() ; i++){
        // if not visited
        if(!visitedToFill[i]){
            //check numbers to fill in
            for(int num = 1 ; num < 10 ; num++){
                int x,y;
                tie(x,y) = toFill[i];
                    if(isSatisfy(x,y,num)){
                    visitedToFill[i]=true;
                    sudoku[x][y] = num;
                    if(solve(visitCount+1)){
                        return true;
                    }
                    visitedToFill[i]=false;
                    sudoku[x][y] = 0;
                }
            } 
        }
    }
    */
    return ;
}
int main(){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cin >> sudoku[i][j];
            // if sudoku[i][j] is Zero
            if(!sudoku[i][j]){
                toFill.push_back({i,j});
            }
        }
    }
    solve(0);
    // printSudoku();
}