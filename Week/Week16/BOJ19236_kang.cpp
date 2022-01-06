#include<iostream>
#include<map>
#include<climits>
#include<tuple>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int, int> pii;
typedef map<int, pair<int, int> > mapInfo;
                        // ↑,     ↖,      ←,     ↙,    ↓,     ↘,   →,   ↗
pair<int, int> dir[8] = {{-1, 0},{-1, -1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
struct space{
    int fishNo;
    int direction;
    bool iseaten = false;
    bool isShark = false;
};
// bool eaten[17];

int maxEaten=INT_MIN;

bool inRange(int x, int y){
    return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void goForEat(int x, int y, int ate, space fishBowl[4][4], mapInfo fishLocation){
    fishBowl[x][y].iseaten = true;
    fishBowl[x][y].isShark = true;
    ate += fishBowl[x][y].fishNo;
    
    //move fishes.
    for(int fish = 1; fish < 17 ; fish++){
        // choose fish to move
        int curX, curY;
        tie(curX, curY) = fishLocation[fish];
        // printf("current Location: %d, %d\n",curX, curY);
        // if fish is alive
        if(!fishBowl[curX][curY].iseaten){
            //check every direction to go
            for(int i = 0 ; i < 8 ; i++){
                int dX, dY;
                // printf("direction: %d\n",fishBowl[curX][curY].direction);
                tie(dX,dY) = dir[fishBowl[curX][curY].direction];
                int nextX = curX+dX;
                int nextY = curY+dY;
                // in Range  and  not shark
                if(inRange(nextX,nextY) && !fishBowl[nextX][nextY].isShark){
                    //swap
                    
                    int curFishNo = fish;
                    int nextFishNo = fishBowl[nextX][nextY].fishNo;
                    // printf("swap %d with %d\n", i, nextFishNo);
                    space tmp1;
                    tmp1 = fishBowl[curX][curY];
                    fishBowl[curX][curY] = fishBowl[nextX][nextY];
                    fishBowl[nextX][nextY] = tmp1;
                    pii tmp2;
                    tmp2 = fishLocation[curFishNo];
                    fishLocation[curFishNo]= fishLocation[nextFishNo];
                    fishLocation[nextFishNo] = tmp2;
                    break;
                }
                else{
                    fishBowl[curX][curY].direction = (fishBowl[curX][curY].direction + 1) % 8;
                }
            }
        }
    }
    // for(int i = 0 ; i < 4 ; i++){
    //     for(int j = 0 ; j < 4 ; j++){
    //         if(fishBowl[i][j].isShark){
    //             printf("SH,%d\t", fishBowl[i][j].direction+1);
    //         }
    //         else if(!fishBowl[i][j].iseaten){
    //             printf("%d,%d\t",fishBowl[i][j].fishNo, fishBowl[i][j].direction+1);
    //         }
    //         else{
    //             printf("X\t");
    //         }
    //     }
    //     printf("\n");
    // }
        
    // printf("current ate: %d\n\n",ate);
    
    int nextSharkX = x;
    int nextSharkY = y;
    int dx, dy;
    tie(dx, dy) = dir[fishBowl[x][y].direction];
    
    
    for(int i = 0 ; i < 3 ; i++){
        nextSharkX += dx;
        nextSharkY += dy;
        if(inRange(nextSharkX, nextSharkY) && !fishBowl[nextSharkX][nextSharkY].iseaten){
            fishBowl[x][y].isShark = false;
            space newFishBowl[4][4];
            memcpy(newFishBowl,fishBowl,4*4*sizeof(space));
            goForEat(nextSharkX, nextSharkY, ate, newFishBowl, fishLocation);
        }
    }
    maxEaten = max(ate, maxEaten);
}
int main(){
    // eaten[0] = true;
    space fishBowl[4][4];
    mapInfo fishLocation;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cin >> fishBowl[i][j].fishNo >> fishBowl[i][j].direction;
            fishBowl[i][j].direction--;
            fishLocation.insert({fishBowl[i][j].fishNo, {i,j}});
        }
    }
    goForEat(0, 0, 0, fishBowl, fishLocation);
    printf("%d",maxEaten);
}