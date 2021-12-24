#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
vvi board;
int N;
void pushLeft(){
    for(int row = 0 ; row < N ; row++){
        vi newRow(N,0);
        bool selected=false;
        int selectedVal = -1;
        int newRowIdx = 0;
        for(int col = 0 ; col < N ; col++){
            if(board[row][col] != 0){
                if(!selected){
                    selected = true;
                    selectedVal = board[row][col];
                }
                else{
                    if(board[row][col] == selectedVal){
                        selected = false;
                        newRow[newRowIdx++]=2*selectedVal;
                    }
                    else{
                        newRow[newRowIdx++]=selectedVal;
                        selectedVal = board[row][col];
                    }
                }
            }
        }
        if(selected){
            newRow[newRowIdx] = selectedVal;
        }
        board[row] = newRow;
    }
}
void pushRight(){
    for(int row = 0 ; row < N ; row++){
        vi newRow(N,0);
        bool selected=false;
        int selectedVal = -1;
        int newRowIdx = N-1;
        for(int col = N-1 ; col >= 0 ; col--){
            if(board[row][col] != 0){
                if(!selected){
                    selected = true;
                    selectedVal = board[row][col];
                }
                else{
                    if(board[row][col] == selectedVal){
                        selected = false;
                        newRow[newRowIdx--]=2*selectedVal;
                    }
                    else{
                        newRow[newRowIdx--]=selectedVal;
                        selectedVal = board[row][col];
                    }
                }
            }
        }
        if(selected){
            newRow[newRowIdx] = selectedVal;
        }
        board[row] = newRow;
    }
}
void pushUp(){
    for(int col = 0 ; col < N ; col++){
        vi newCol(N,0);
        bool selected=false;
        int selectedVal = -1;
        int newRowIdx = 0;
        for(int row = 0 ; row < N ; row++){
            if(board[row][col] != 0){
                if(!selected){
                    selected = true;
                    selectedVal = board[row][col];
                }
                else{
                    if(board[row][col] == selectedVal){
                        selected = false;
                        newCol[newRowIdx++]=2*selectedVal;
                    }
                    else{
                        newCol[newRowIdx++]=selectedVal;
                        selectedVal = board[row][col];
                    }
                }
            }
        }
        //fill in board with newCol
        if(selected){
            newCol[newRowIdx] = selectedVal;
        }
        for(int row = 0 ; row < N ; row++){
            board[row][col] = newCol[row];
        }
    }
}
void pushDown(){
    for(int col = 0 ; col < N ; col++){
        vi newCol(N,0);
        bool selected=false;
        int selectedVal = -1;
        int newRowIdx = N-1;
        for(int row = N-1 ; row >= 0 ; row--){
            if(board[row][col] != 0){
                if(!selected){
                    selected = true;
                    selectedVal = board[row][col];
                }
                else{
                    if(board[row][col] == selectedVal){
                        selected = false;
                        newCol[newRowIdx--]=2*selectedVal;
                    }
                    else{
                        newCol[newRowIdx--]=selectedVal;
                        selectedVal = board[row][col];
                    }
                }
            }
        }
        //fill in board with newCol
        if(selected){
            newCol[newRowIdx] = selectedVal;
        }
        for(int row = N-1 ; row >= 0 ; row--){
            board[row][col] = newCol[row];
        }
    }
    
}
void (*command[4])() ={ pushUp, pushDown, pushLeft, pushRight };
int largest(){
    int r_val = INT_MIN;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] > r_val)
                r_val = board[i][j];
        }
    }
    return r_val;
}
int playGame(int moveCount){
    if(moveCount > 5){
        return largest();
    }
    int largest = INT_MIN;
    for(int i = 0 ; i < 4 ; i++){
        vvi tmp = board;
        
        command[i]();
        largest = max(playGame(moveCount+1), largest);
        board = tmp;
    }
    return largest;
}
int main(){
    cin >> N;
    board.resize(N, vector<int>(N));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf(" %d", &board[i][j]);
        }
    }
    printf("%d", playGame(1));
}