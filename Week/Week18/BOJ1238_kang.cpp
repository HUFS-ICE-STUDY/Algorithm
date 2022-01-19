#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<tuple>
using namespace std;
typedef vector<vector<int> > vii;
typedef pair<int, int> pii;
int N, M, X;
vii graph;
vii shortest;
void dijkstra(int startNode){
    bool visited[N+1];
    for(int i = 0 ; i < N+1 ; i++){
        visited[i] = false;
    }
    visited[0] = true;
    shortest[startNode][startNode] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0,startNode});
    while(!pq.empty()){
        pii choosen = pq.top();
        int dist, node;
        tie(dist, node) = choosen;
        pq.pop();
        if(visited[node])
            continue;
        visited[node] = true;
        for(int next = 1 ; next <= N ; next++){
            if(graph[node][next] != 0 && !visited[next]){
                int path = graph[node][next];
                shortest[startNode][next] = shortest[startNode][next] > dist+path ? dist+path : shortest[startNode][next];
                if(!visited[next]){
                    pq.push({shortest[startNode][next], next});
                }
            }
        }
    }
}
int main(){
    scanf(" %d %d %d", &N,&M,&X);
    graph.resize(N+1,vector<int>(N+1,0));
    shortest.resize(N+1, vector<int>(N+1,INT_MAX));
    for(int i = 0 ; i < M ; i++){
        int s, e, t;
        scanf(" %d %d %d", &s, &e, &t);
        graph[s][e] = t;
    }
    int max = -1;
    for(int i = 1 ; i <= N ; i++){
        dijkstra(i);
    }
    for(int i = 1 ; i <= N ; i++){
        int rt = shortest[i][X]+shortest[X][i]; //round trip
        max = rt > max ? rt : max;
    }
    printf("%d",max);
}