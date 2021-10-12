#include <iostream>

using namespace std;

int pieces[6] = {1, 1, 2, 2, 2, 8};

int main(){
    int found;
    for(int i = 0 ; i < 6 ; i++){
        cin >> found;
        cout << pieces[i]-found << " ";
    }
}