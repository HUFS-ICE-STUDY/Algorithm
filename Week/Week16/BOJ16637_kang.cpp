#include<iostream>
#include<map>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;
int N;
char math[19];
int addition(int a, int b){
    return a+b;
}
int subtraction(int a, int b){
    return a-b;
}
int mult(int a, int b){
    return a*b;
}
typedef int(*func)(int, int);
typedef char command;
map<command, func> commandMap = {{'+', addition}, {'-', subtraction},{'*',mult}};
int maxVal = INT_MIN;
void calculate(int idx, queue<char> expression){
    // printf("idx: %d\n",idx);
    if(idx==N-1){
        expression.push(math[idx]);
        int a = expression.front();
        expression.pop();
        // printf("calc: ");
        // printf("%d",a);
        char com ;
        if(!expression.empty()){
            com = expression.front();
            // printf("%c",com);
            expression.pop();
        }
        while(!expression.empty()){
            int b = expression.front();
            // printf("%d",b);
            expression.pop();
            a = commandMap[com](a,b);
            if(!expression.empty()){
                com = expression.front();
                // printf("%c",com);
                expression.pop();
            }
        }
        // printf(" = %d\n", a);
        maxVal = max(maxVal,a);
        
        return;
    }
    
    queue<char> exp1 = expression;
    int a = math[idx];
    char com = math[idx+1];
    int b = math[idx+2];
    
    expression.push(a);
    expression.push(com);
    calculate(idx+2, expression);
    int sum = commandMap[com](a,b);

    // printf("sum: %d\n",sum);
    if(idx+3<N){
        exp1.push(sum);
        exp1.push(math[idx+3]);
        calculate(idx+4, exp1);
    }
    else{
        exp1.push(sum);
        int a = exp1.front();
        exp1.pop();
        // printf("calc: ");
        // printf("%d",a);
        char com ;
        if(!exp1.empty()){
            com = exp1.front();
            // printf("%c",com);
            exp1.pop();
        }
        while(!exp1.empty()){
            int b = exp1.front();
            // printf("%d",b);
            exp1.pop();
            a = commandMap[com](a,b);
            if(!exp1.empty()){
                com = exp1.front();
                // printf("%c",com);
                exp1.pop();
            }
        }
        // printf(" = %d\n",a);
        maxVal = max(maxVal,a);
        
    }
    

}
int main(){
    cin>>N;
    scanf("%s",math);
    for(int i = 0 ; i < N ; i=i+2)
        math[i]-=48;
    queue<char> q;
    calculate(0,q);
    printf("%d",maxVal);
}