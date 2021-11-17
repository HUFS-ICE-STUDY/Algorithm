#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int N;
int tb;
// key: candidate num, value: # of recommand , added time
map<int, pair<int, int> > recommands;
vector<int> candidates;

void updateCandidates(int key){
	// if key exist in candidates
	if(find(candidates.begin(), candidates.end(),key) != candidates.end()){
		recommands[key].first++;
	}
	// if key not exist in candidates
	else{
		// if candidates not filled yet
		if(candidates.size() < N){
			recommands[key].first++;
			candidates.push_back(key);
		}
		//if candidates are filled
		else{
			int removeIdx = -1;
			int smallestRec = INT_MAX;
			// find smallest Recommandation candidate to remove.
			for(int i = 0 ; i < N ; i++){
				if(recommands[candidates[i]].first < smallestRec){
					smallestRec = recommands[candidates[i]].first;
					removeIdx = i;
				// if # of recommands are same,
				}else if(recommands[candidates[i]].first == smallestRec){
					//delete oldest candidate.
					if(recommands[candidates[i]].second < recommands[candidates[removeIdx]].second){
						removeIdx = i;
					}
				}
			}
			// mark removed candidate's recommand as 0
			recommands[candidates[removeIdx]].first = 0;
			// remove candidate from candidates
			candidates.erase(candidates.begin()+removeIdx,candidates.begin()+removeIdx+1);
			
			recommands[key].first++;
			candidates.push_back(key);
		}
	}
}
int main(){
	cin >> N >> tb;
	
	int recommand;
	for(int time = 0 ; time < tb ; time++){
		cin >> recommand;
		// if candidate updated first time
		if(recommands.find(recommand) == recommands.end()){
			//add recommand
			recommands[recommand] = make_pair(0, time);
			updateCandidates(recommand);
		}else{
			// if recommand is deleted from candidates
			if(recommands[recommand].first == 0)
				//set new time for recommand
				recommands[recommand].second = time;
			updateCandidates(recommand);
		}
	}
	sort(candidates.begin(),candidates.end());
	for(int i = 0 ; i < candidates.size() ; i++){
		cout<< candidates[i]<<" ";
	}
	return 0;
}
