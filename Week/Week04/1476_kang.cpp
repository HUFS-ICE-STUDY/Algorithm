#include<iostream>

using namespace std;
int E,S,M;
int main(){
    E=1;S=1;M=1;
    
    int in_E,in_S,in_M;
    cin >> in_E >> in_S >> in_M;
    int year = 1;
    while(true){
    	if(E==in_E && S == in_S && M == in_M)
    		break;
        E++;S++;M++;
        if(E > 15) E = 1;
        if(S > 28) S = 1;
        if(M > 19) M = 1;
        year++;
    }
    cout << year;
    
}