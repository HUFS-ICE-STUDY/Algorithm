#include <iostream>
using namespace std;
int N;
int main(){
    cin >> N;
    int n;
    int count = 0;
    for(int i = 0 ; i < N ; i++){
        scanf("%1d", &n);
        if(n == 1)
            count++;
    }
    cout << count;
    return 0;
}
