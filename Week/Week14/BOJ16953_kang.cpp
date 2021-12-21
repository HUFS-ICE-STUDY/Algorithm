#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll A, B;
int calculate(ll inA, int calcTime){
	int r_val = -1;
	if(inA>B)
		return r_val;
	if(inA==B)
		return calcTime;
	int calc1 = calculate(inA*2, calcTime+1);
	int calc2 = calculate(inA*10+1, calcTime+1);
	if(calc1 != -1 && calc2 != -1)
		r_val = min(calc1,calc2);
	else
		r_val = max(calc1, calc2);
	return r_val;
}
int main(){
	cin >> A >> B;
	printf("%d",calculate(A,1));
}
