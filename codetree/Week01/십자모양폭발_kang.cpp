#include <iostream>

using namespace std;

int n;
int grid[200][200];
int next_grid[200][200];

int main(){
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    cin >> n ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            cin >> grid[i][j];
        }
    }
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    int bomb_size = grid[r][c];
    bomb_size--;
    grid[r][c] = 0;

    for(int dir = 0 ; dir < 4 ; dir++){
        int next_r = r;
        int next_c = c;
        for(int size = 0 ; size < bomb_size ; size++){
            next_r += dx[dir];
            next_c += dy[dir];
            if(0 <= next_r && next_r < n && 0 <= next_c && next_c < n){
                grid[next_r][next_c] = 0;
            }
        }
    }
    
    for(int j = 0 ; j < n ; j++){
        int next_i = n-1;
        for(int i = n-1 ; i >= 0 ; i--){
            if(grid[i][j]){
                next_grid[next_i--][j] = grid[i][j];
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << next_grid[i][j] << " ";
        }
        cout << endl;
    }
}
