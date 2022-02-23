#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
struct shark{
    int speed;
    int direction;
    int size;
};
int R, C, M;
int fisherman=0;
vector<vector<queue<shark> > > pond(100,vector<queue<shark> >(100));
vector<vector<queue<shark> > > toMove(100, vector<queue<shark> >(100));
void move(int x, int y){
    
    shark choosen = pond[x][y].front();
    int dir = choosen.direction;
    int speed = choosen.speed;
    int udmax = R-1;
    int lrmax = C-1;
    // printf("\nmove: x: %d, y: %d to..\n",x+1,y+1);
    // if(dir<2){
    //     printf("x: %d",x+1);
    // }
    // else
    //     printf("y: %d",y+1);
    while(speed>0){
        // if move up n down
        if(dir<2){
            int nX = x+speed*dx[dir];
            if(nX < 0){
                dir = (dir+1)%2;
                speed -= x;
                x=0;
            }
            else if(nX >= R){
                dir = (dir+1)%2;
                speed -= (udmax-x);
                x=udmax;
            }
            else{
                speed = 0;
                x=nX;
            }
            // printf("-> %d ",x+1);
        }
        // if move left n right
        else{
            int nY = y+speed*dy[dir];
            // printf("(nY: %d)", nY);
            if(nY < 0){
                dir = 2+(dir+1)%2;
                speed -= y;
                y=0;
            }
            else if(nY >= C){
                dir = 2+(dir+1)%2;
                speed -= (lrmax-y);
                y=lrmax;
            }
            else{
                speed=0;
                y=nY;
            }
            // printf("-> %d ",y+1);
        }
    }
    choosen.direction=dir;
    toMove[x][y].push(choosen);
    // printf("moved to x: %d, y: %d\n",x+1,y+1);
}
void leaveBig(int x, int y){
    shark bigOne = toMove[x][y].front();
    toMove[x][y].pop();
    while(!toMove[x][y].empty()){
        shark compare = toMove[x][y].front();
        toMove[x][y].pop();
        if(bigOne.size < compare.size)
            bigOne = compare;
    }
    toMove[x][y].push(bigOne);
}
int catchThemAll(){
    int amount=0;
    while(fisherman < C){
        //fish shark
        for(int depth = 0 ; depth < R ; depth++){
            // printf("depth: %d, fisherman: %d\n",depth, fisherman);
            if(!pond[depth][fisherman].empty()){
                //if there is a fish, then
                shark gotIt = pond[depth][fisherman].front();
                pond[depth][fisherman].pop();
                amount += gotIt.size;
                break;
            }
        }
        // printf("\nfisherman: %d, amount of fished: %d\n",fisherman, amount);
        //move all shark 
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                // printf("x: %d, y: %d\n", i+1,j+1);
                if(!pond[i][j].empty()){
                    move(i, j);
                }
            }
        }
        //leave one shark
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                if(toMove[i][j].size()>1){
                    leaveBig(i,j);
                }
            }
        }
        pond = toMove;
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                if(!toMove[i][j].empty()){
                    while(!toMove[i][j].empty()){
                        toMove[i][j].pop();
                    }
                }
            }
        }
        // printf("====shark location====\n");
        // for(int i = 0 ; i < R ; i++){
        //     for(int j = 0 ; j < C ; j++){
        //         if(pond[i][j].empty())
        //             printf("0 ");
        //         else{
        //             printf("%d ",pond[i][j].front().size);
        //         }
        //     }
        //     printf("\n");
        // }
        // printf("eat shark\n");
        fisherman++;
    }
    return amount;;
}
int main(){
    scanf(" %d %d %d", &R, &C, &M);
    int r,c,s,d,z;
    for(int i = 0 ; i < M ; i++){
        scanf(" %d %d %d %d %d", &r, &c, &s, &d, &z);
        r--;c--;d--;
        shark newShark;
        newShark.speed=s;
        newShark.direction=d;
        newShark.size=z;
        pond[r][c].push(newShark);
    }
    
    if(M == 0){
        printf("0");
        return 0;
    }
    
    printf("%d",catchThemAll());
}