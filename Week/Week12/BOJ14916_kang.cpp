#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(n == 1 || n == 3){
		cout<<-1;
		return 0;
	}
	if(n%5%2 == 0){
		cout << n/5 + (n%5)/2;
	}
	else{
		cout<< n/5-1 + (n%5+5)/2;
	}
	return 0;
}
