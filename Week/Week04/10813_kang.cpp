#include <iostream>

using namespace std;

int basket[101];
int n,m;

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        basket[i]=i;
    }
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;
        int tmp = basket[a];
        basket[a] = basket[b];
        basket[b] = tmp;
    }
    for(int i = 1 ; i <= n ; i++){
        cout << basket[i] << " ";
    }
}