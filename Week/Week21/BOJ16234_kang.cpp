#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
struct country{
    int people = 0;
    bool border[4]={false,false,false,false};
};
typedef pair<int, int> pii;
country land[50][50];
int N, L, R;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}
bool canOpen(int p1, int p2){
    int diff;
    if(p1<p2)
        diff = p2-p1;
    else
        diff=p1-p2;
    return L <= diff && diff <= R;
}
bool searchBorder(int x, int y){
    bool moved = false;
    for(int dir = 0 ; dir < 4 ; dir++){
        int nX,nY;
        nX = x+dx[dir];
        nY = y+dy[dir];
        if(inRange(nX,nY) && canOpen(land[x][y].people,land[nX][nY].people)){
            moved=true;
            land[x][y].border[dir]=true;
        }
    }
    return moved;
}
void BFS(int x, int y){
    bool end=true;
    for(int i = 0 ; i < 4 ; i++){
        if(land[x][y].border[i]){
            end=false;
            break;
        }
    }
    if(end){
        return;
    }
    queue<pii> q;
    int groupNum = 0;
    int peopleNum = 0;
    bool visited[50][50];
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            visited[i][j]=false;
        }
    }
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()){
        groupNum++;
        tie(x,y) = q.front();
        country curr = land[x][y];
        peopleNum += curr.people;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nX, nY;
            nX = x+dx[i];
            nY = y+dy[i];
            if(curr.border[i] && !visited[nX][nY]){
                visited[nX][nY] = true;
                q.push({nX, nY});
            }
            land[x][y].border[i]=false;
        }
    }
    int div = peopleNum/groupNum;
    // printf("# of total people: %d, # of total groupNum: %d\n",peopleNum, groupNum);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(visited[i][j]){
                land[i][j].people = div;
            }
        }
    }
}
int main(){
    cin >> N >> L >> R;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> land[i][j].people;
        }
    }
    bool moved=true;
    int movingDay=0;
    while(moved){
        moved=false;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                // printf("%d ",land[i][j].people);
                if(searchBorder(i,j)){
                    moved=true;
                }
            }
            // printf("\n");
        }
        // printf("\n");
        if(moved){
            movingDay++;
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N ; j++){
                    BFS(i,j);
                }
            }
        }
    }
    printf("%d",movingDay);
}


