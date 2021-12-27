#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;
typedef pair<int, int> pii;
stack<int> pole[3];
vector<pii> answer;

int findNum(int N){
    for(int idx = 0 ; idx < 3 ; idx++){
        stack<int> copy = pole[idx];
        while(!copy.empty()){
            if(copy.top() == N){
                return idx;
            }
            copy.pop();
        }
    }
    return 0;
}
int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int tmp;
        scanf(" %d", &tmp);
        pole[0].push(tmp);
    }
    while(N>0){
        int poped;
        int targetIdx = findNum(N);
        int moveIdx = targetIdx==0 ? 1 : 0;
        while(pole[targetIdx].top() != N){
            poped = pole[targetIdx].top();
            pole[targetIdx].pop();
            pole[moveIdx].push(poped);
            answer.push_back({targetIdx+1, moveIdx+1});
        }
        pole[targetIdx].pop();
        pole[2].push(N--);
        answer.push_back({targetIdx+1, 3});
    }
    printf("%d\n",answer.size());
    for(int i = 0 ; i < answer.size() ; i++){
        printf("%d %d\n",answer[i].first, answer[i].second);
    }
}