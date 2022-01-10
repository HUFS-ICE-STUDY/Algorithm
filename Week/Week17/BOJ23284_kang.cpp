#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > answers;
int N;
void stackPermu(int num, stack<int> s, vector<int> v){
    if(num==N){
        v.push_back(num);
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        answers.push_back(v);
        return;
    }
    s.push(num);
    stackPermu(num+1, s, v);
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
        stackPermu(num+1,s,v);
    }

}
int main(){
    cin>>N;
    stack<int> s;
    vector<int> v;
    stackPermu(1, s, v);
    sort(answers.begin(), answers.end());
    for(auto answer : answers){
        for(auto num: answer){
            printf("%d ",num);
        }
        printf("\n");
    }
}