#include<iostream>
#include<tuple>
#include<stack>
using namespace std;
typedef pair<int, int> pii;
int N;
int answer[500000];
int main(){
    stack<pii> s;
    cin >> N;
    int tmp, tower, idx;
    scanf(" %d",&tmp);
    s.push({tmp,1});
    for(int i = 1 ; i < N ; i++){
        scanf(" %d",&tmp);
        tie(tower,idx) = s.top();
        if(tower > tmp){
            answer[i] = idx;
        }else{
            while(tower<tmp){
                s.pop();
                if(s.empty())
                    break;
                tie(tower,idx) = s.top();
            }
            if(!s.empty())
                answer[i]=idx;
        }
        s.push({tmp,i+1});
    }
    for(int i = 0 ; i < N ; i++){
        printf("%d ",answer[i]);
    }
}