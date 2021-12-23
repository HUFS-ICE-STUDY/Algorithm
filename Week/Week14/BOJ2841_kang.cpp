#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int N, P;
int main(){
	cin >> N >> P;
	vector<stack<int> > onFret(7);
	int movement = 0;
	while(N--){
		int melody, fret;
		scanf(" %d %d", &melody, &fret);
		if(onFret[melody].empty()){
			onFret[melody].push(fret);
			movement++;
		}
		else{
			if (onFret[melody].top() < fret){
				onFret[melody].push(fret);
				movement++;
			}
			else if (onFret[melody].top() > fret){
				while(!onFret[melody].empty() && onFret[melody].top() > fret){
					onFret[melody].pop();
					movement++;
				}
				if(onFret[melody].empty() || onFret[melody].top() != fret){
					onFret[melody].push(fret);
					movement++;
				}
			}
		}
	}
	printf("%d",movement);
}
