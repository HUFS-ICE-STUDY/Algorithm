#include<iostream>
#include<vector>
using namespace std;
int main(){
	int N, ji, han;
	cin >> N >> ji >> han;
	ji--; han--;
	vector<int> tournament(N);
	for(int i = 0 ; i < N ; i++){
		tournament[i]=i;
	}
	int round = 1;
	while(tournament.size() != 1){
		vector<int> newT;
		int newNum = 0;
		for(int i = 0 ; i < tournament.size() ; i+=2){
			if(tournament[i]==ji){
				if(i+1<tournament.size() && tournament[i+1]==han){
					cout<<round;
					return 0;
				}
				ji=newNum;
				newT.push_back(ji);
			}
			else if(tournament[i]==han){
				if(i+1<tournament.size() &&tournament[i+1]==ji){
					cout<<round;
					return 0;
				}
				han = newNum;
				newT.push_back(han);
			}
			else if(i+1<tournament.size() &&tournament[i+1]==ji){
				if(tournament[i]==han){
					cout<<round;
					return 0;
				}
				ji=newNum;
				newT.push_back(ji);
			}
			else if(i+1<tournament.size() &&tournament[i+1]==han){
				if(tournament[i]==ji){
					cout<<round;
					return 0;
				}
				han = newNum;
				newT.push_back(han);
			}
			else{
				newT.push_back(newNum);
			}
			newNum++;
		}
		round++;
		tournament = newT;
		
	}
	cout<<-1;
	return 0;
}
