#include<iostream>
#include<set>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;
int N, H, M;
vector<vector<bool> > ladder;
int best = 4;
inline bool ladderChecker(int m, int n){
    if(n>0 && ladder[m][n-1])return false;
    if(ladder[m][n])return false;
    if(ladder[m][n+1])return false;
    return true;
}
bool playGame(){
    for(int i = 1 ; i <= N ; i++){
        int n = i;
        for(int m = 1 ; m <= M ; m++){
            if(ladder[m][n]) ++n;
            else if(n>0 && ladder[m][n-1]) --n;
        }
        if(n!=i) return false;
    }
    return true;
}
void simulation(int m, int n, int cnt){
    if(cnt>=4) return;
    if(playGame()) 
        best = min(best, cnt);
    for(int i = m ; i <= M ; i++){
        for(int j = 1 ; j < N ; j++){
            if(ladderChecker(i,j)){
                ladder[i][j] = true;	
                simulation(i,j+1,cnt+1);
                ladder[i][j] = false;
            }
        }
    }
    return;
}
int main(){
    cin >> N >> H >> M;
    ladder.resize(M+1, vector<bool>(N+1,false));
    int h, t;
    for(int i = 0 ; i < H ; i++){
        scanf(" %d %d", &h, &t);
        ladder[h][t]=true;
    }
    simulation(1,1,0);
    if(best == 4){
        printf("-1");
        return 0;
    }
    printf("%d",best);
    return 0;
}
// //Zero
// if(playGame()){
//     printf("0");
//     return 0;
// }
// //Once
// for(int i = 1 ; i <= M ; i++){
//     for(int j = 1 ; j < N ; j++){
//         if(ladder[i][j]||ladder[i][j-1]||ladder[i][j+1])
//             continue;
//         ladder[i][j] = true;
//         if(playGame()){
//             printf("1");
//             return 0;
//         }
//         ladder[i][j]= false;
//     }
// }
// //Twice
// for(int i1 = 1 ; i1 <= M ; i1++){
//     for(int j1 = 1 ; j1 < N ; j1++){
//         if(ladder[i1][j1]||ladder[i1][j1-1]||ladder[i1][j1+1])
//             continue;
//         ladder[i1][j1]=true;
//         for(int i2 = 1 ; i2 <= M ; i2++){
//             for(int j2 = 1 ; j2 < N ; j2++){
//                 if(ladder[i2][j2]||ladder[i2][j2-1]||ladder[i2][j2+1])
//                     continue;
//                 ladder[i2][j2] = true;
//                 if(playGame()){
//                     printf("2");
//                     return 0;
//                 }
//                 ladder[i2][j2] = false;
//             }
//         }
//         ladder[i1][j1]=false;
//     }
// }
// //Thrice
// for(int i1 = 1 ; i1 <= M ; i1++){
//     for(int j1 = 1 ; j1 < N ; j1++){
//         if(ladder[i1][j1]||ladder[i1][j1-1]||ladder[i1][j1+1])
//             continue;
//         ladder[i1][j1] = true;
//         for(int i2 = 1 ; i2 <= M ; i2++){
//             for(int j2 = 1 ; j2 < N ; j2++){
//                 if(ladder[i2][j2]||ladder[i2][j2-1]||ladder[i2][j2+1])
//                     continue;
//                 ladder[i2][j2] = true;
//                 for(int i = 1 ; i <= M ; i++){
//                     for(int j = 1 ; j < N ; j++){
//                         if(ladder[i][j]||ladder[i][j-1]||ladder[i][j+1])
//                             continue;
//                         ladder[i][j] = true;
//                         if(playGame()){
//                             printf("3");
//                             return 0;
//                         }
//                         ladder[i][j] = false;
//                     }
//                 }
//                 ladder[i2][j2] = false;
//             }
//         }
//         ladder[i1][j1] = false;
//     }
// }
