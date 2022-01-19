#include<iostream>
#include<map>
// #include<tuple>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef vector<int> vi;
// typedef tuple<int, int, int> waterInfo;
int A, B ,C;
bool visited[200][200][200];
set<int> answer;
void solve(vi bottle){
    queue<vi> q;
    visited[bottle[0]][bottle[1]][bottle[2]] = true;
    q.push(bottle);
    while(!q.empty()){
        vi cur = q.front();
        q.pop();
        if(cur[0] == 0){
            answer.insert(cur[2]);
        }
        vi tmp(3);
        // pour A to B;
        if(cur[0]+cur[1] <= B){
            tmp[0] = 0;
            tmp[1] = cur[0]+cur[1];
            tmp[2] = cur[2];
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }else{
            tmp[0] = cur[0] - (B - cur[1]);
            tmp[1] = B;
            tmp[2] = cur[2];
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }
        // pour A to C;
        if(cur[0]+cur[2] <= C){
            tmp[0] = 0;
            tmp[1] = cur[1];
            tmp[2] = cur[0]+cur[2];
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }else{
            tmp[0] = cur[0] - (C - cur[2]);
            tmp[1] = cur[1];
            tmp[2] = C;
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }
        // pour B to A;
        if(cur[1]+cur[0] <= A){
            tmp[0] = cur[0]+cur[1];
            tmp[1] = 0;
            tmp[2] = cur[2];
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }else{
            tmp[0] = A;
            tmp[1] = cur[1] - (A - cur[0]);
            tmp[2] = cur[2];
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }
        // pour B to C;
        if(cur[1]+cur[2] <= C){
            tmp[0] = cur[0];
            tmp[1] = 0;
            tmp[2] = cur[1]+cur[2];
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }else{
            tmp[0] = cur[0];
            tmp[1] = cur[1] - (C - cur[2]);
            tmp[2] = C;
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }
        // pour C to A;
        if(cur[2]+cur[0] <= A){
            tmp[0] = cur[0]+cur[2];
            tmp[1] = cur[1];
            tmp[2] = 0;
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }else{
            tmp[0] = A;
            tmp[1] = cur[1];
            tmp[2] = cur[2] - (A - cur[0]);
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }
        // pour C to B;
        if(cur[2]+cur[1] <= B){
            tmp[0] = cur[0];
            tmp[1] = cur[1]+cur[2];
            tmp[2] = 0;
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }else{
            tmp[0] = cur[0];
            tmp[1] = B;
            tmp[2] = cur[2] - (B - cur[1]);
            if(!visited[tmp[0]][tmp[1]][tmp[2]]){
                visited[tmp[0]][tmp[1]][tmp[2]] = true;
                q.push(tmp);
            }
        }
    }
}
int main(){
    scanf(" %d %d %d", &A, &B, &C);
    vi bottle(3);
    bottle[0] = 0;
    bottle[1] = 0;
    bottle[2] = C;
    solve(bottle);
    set<int>::iterator iter;
    for(iter = answer.begin() ; iter != answer.end() ; iter++){
        printf("%d ",*iter);
    }
}
