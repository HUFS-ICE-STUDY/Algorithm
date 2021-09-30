#include <iostream>

using namespace std;

int grid[101][101];
int n, m, k;

void dropBlock(){
    // 애초에 101범위에 1,1부터 넣었기에, 빈공간이 존재. 빈공간에서부터 아래 블록 유무 확인.
    for(int i = 0 ; i < n ; i++){
        // 떨어지는 블록의 길이 아래에 맞닿는 블록이 있는지 검사
        for(int len = k ; len < k+m ; len++){
            if(grid[i+1][len] == 1){
                for(int j = k ; j < k+m ; j++){
                    grid[i][j] = 1;
                }
                return;
            }
        }
    }
    for(int i = k ; i < k+m ; i++){
    	grid[n-1][i]=1;
	}
    return;
}

int main(){
    cin >> n >> m >> k;
    m;
    n++;
    k;
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < n ; j++){
            cin >> grid[i][j];
        }
    }
    dropBlock();
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < n ; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
