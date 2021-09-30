#include <iostream>
#define MAX 50

using namespace std;

int n;
int origin_grid[MAX][MAX];
int next_grid[MAX][MAX];

int explode(int r, int c){
	int grid[MAX][MAX];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			grid[i][j] = origin_grid[i][j];
			next_grid[i][j]=0;
		}
	}
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int bomb_size = grid[r][c];
    
    grid[r][c] = 0;
	
	
    for(int dir = 0 ; dir < 4 ; dir++){
    	int next_r = r;
    	int next_c = c;
        for(int size = 1 ; size < bomb_size ; size++){
            next_r += dx[dir];
            next_c += dy[dir];
            if(0 <= next_r && next_r < n && 0 <= next_c && next_c < n){
                grid[next_r][next_c] = 0;
            }
        }
    }
    
    for(int col = 0 ; col < n ; col++){
        int next_row = n-1;
        for(int row = n-1 ; row >= 0 ; row--){
            if(grid[row][col] != 0){
                next_grid[next_row--][col] = grid[row][col];
            }
        }
    }
    
    int count = 0;
    
	for(int row = 0 ; row < n ; row++){
        int base = next_grid[row][0];
        for(int col = 1 ; col < n ; col++){
            if(base != 0){
            	if(next_grid[row][col] !=  base){
                	base = next_grid[row][col];
	            }
	            else{
	            	count++;
				}
			}
			else{
				base = next_grid[row][col];
			}
        }
    }
    
    for(int col = 0 ; col < n ; col++){
    	
        int base = next_grid[0][col];
        
        for(int row = 1 ; row < n ; row++){
        	
        	if(base != 0){
        		if(next_grid[row][col] != base){
                base = next_grid[row][col];
            	}
            	else {
            		count++;
				}
			}
			else{
				base = next_grid[row][col];
			}
        }
    }
    
    return count;
}

int main(){
    cin >> n;

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            cin >> origin_grid[i][j];
        }
    }

    int max = -1;
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < n ; col++){
            int answer = explode(row,col);
            if(answer > max){
                max = answer;
            }
        }
    }
    cout << max;
}
