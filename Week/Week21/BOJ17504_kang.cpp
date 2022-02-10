#include<iostream>
using namespace std;
int main(){
    int N;
    long long num[15];
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> num[i];
    }
    long long P=1, Q=num[N-1];
    for(int i = N-2 ; i >= 0 ; i--){
        long long a = num[i];
        P += a*Q;
        long long tmp = P;
        P = Q;
        Q = tmp;
    }
    P=Q-P;
    printf("%lld %lld",P,Q);
}