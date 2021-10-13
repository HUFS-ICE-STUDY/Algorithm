#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dwarf[9];
vector<int> answer;

int main(){
    for(int i = 0 ; i < 9 ; i++)
        cin >> dwarf[i];
    sort(dwarf,dwarf+9);
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			if(i==j)
				continue;
			int sum = 0;
			for(int k = 0 ; k < 9 ; k++){
				if(k == i || k == j)
					continue;
				sum += dwarf[k];
				answer.push_back(dwarf[k]);
			}
			if(sum == 100){
				for(int i = 0 ; i < 7 ; i++){
					cout << answer[i] << endl;
				}
				return 0;
			}
			answer.clear();
		}
	}
}