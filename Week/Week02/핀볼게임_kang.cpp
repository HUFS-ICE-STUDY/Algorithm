#include <iostream>
#include <map>

using namespace std;

int grid[100][100];
int n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
map<int, int> one;
map<int, int> two;
int total_count = 1;
bool in_range(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int moveMarble(int x, int y, int dir){
//	cout << total_count <<"ball rolling"<<endl;
    int count = 0;
    int next_x = x ;
    int next_y = y ;
    while(in_range(next_x, next_y)){
		
        if(grid[next_x][next_y] == 0){
            next_x += dx[dir];
            next_y += dy[dir];
            count++;
        }else if(grid[next_x][next_y] == 1){
            dir = one[dir];
            next_x += dx[dir];
            next_y += dy[dir];
            count++;
        }else if(grid[next_x][next_y] == 2){
            dir = two[dir];
            next_x += dx[dir];
            next_y += dy[dir];
            count++;
        }
//        cout << "next_x: "<< next_x << " next_y: " << next_y << " dir: "<<dir<<endl;
    }

    return ++count;
}
int main (){
    one.insert(make_pair(0,3));
    one.insert(make_pair(3,0));
    one.insert(make_pair(1,2));
    one.insert(make_pair(2,1));
    two.insert(make_pair(0,1));
    two.insert(make_pair(1,0));
    two.insert(make_pair(2,3));
    two.insert(make_pair(3,2));

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> grid[i][j];
        }
    }
    //아래방향으로 이동 grid[0][0~n-1]
    int answer = 0;
    for(int i = 0 ; i < n ; i++){
        int temp = moveMarble(0,i,0);
        if (answer < temp){
            answer = temp;
        }
        total_count++;
    }
    //오른방향으로 이동 grid[0~n-1][0]
    for(int i = 0 ; i < n ; i++){
        int temp = moveMarble(i,0,1);
        if (answer < temp){
            answer = temp;
        }
        total_count++;
    }
    //위 방향으로 이동  grid[n-1][0~n-1]
    for(int i = 0 ; i < n ; i++){
        int temp = moveMarble(n-1,i,2);
        if (answer < temp){
            answer = temp;
        }
        total_count++;
    }
    //왼 방향으로 이동  grid[0~n-1][n-1]
    for(int i = 0 ; i < n ; i++){
        int temp = moveMarble(i,n-1,3);
        if (answer < temp){
            answer = temp;
        }
        total_count++;
    }
	cout << answer;
}