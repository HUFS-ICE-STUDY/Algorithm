#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string testcase;
    int testcaseNum = 1;
    while(true){
        cin >> testcase;
        if(testcase.empty()){
            printf("%d. 0\n", testcaseNum++);
        }
        else if(testcase[0]=='-')
            break;
        else{
            stack<char> s;
            int changeCount=0;
            for(int i = 0 ; i < testcase.size() ; i++){
                if(s.empty()){
                    if(testcase[i]=='}'){
                        changeCount++;
                    }
                    s.push('{');
                }else{
                    if(s.top() != testcase[i])
                        s.pop();
                    else   
                        s.push('{');
                }
            }
            if(!s.empty()){
                changeCount += s.size()/2;
            }
            printf("%d. %d\n",testcaseNum++, changeCount);
        }
    }
}