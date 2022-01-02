#include<iostream>
#include<queue>
using namespace std;
/* n : 트럭의 대수
   w : 다리의 길이
   L : 다리의 최대 하중
*/
int n, w, L;
int bridge[101];
int move(){
    for(int i = w ; i > 0 ; i--){
        bridge[i] = bridge[i-1];
    }
    bridge[0]=0;
    return bridge[w];
}
int main(){
    cin >> n >> w >> L;
    queue<int> trucks;
    for(int i = 0 ; i < n ; i++){
        int truck;
        scanf(" %d",&truck);
        trucks.push(truck);
    }
    int curLoad = 0;
    int minTime = 0;
    while(!trucks.empty()){
        int outOfBridge = move();
        curLoad -= outOfBridge;
        minTime++;
        int poped = trucks.front();
        if(curLoad+poped <= L){
            bridge[0]=poped;
            curLoad += poped;
            trucks.pop();
        }    
    }
    printf("%d",minTime+w);
}