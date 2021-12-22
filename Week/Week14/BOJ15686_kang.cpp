#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	vector<pair<int, int> > houseLoc;
	vector<pair<int, int> > chickenLoc;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			int tmp;
			scanf(" %d", &tmp);
			if(tmp == 1){
				houseLoc.push_back(make_pair(i,j));
			}
			else if(tmp == 2){
				chickenLoc.push_back(make_pair(i,j));
			}
		}
	}

	int chickenDist[houseLoc.size()][chickenLoc.size()];
    for(int house = 0 ; house < houseLoc.size() ; house++){
        for(int chicken = 0 ; chicken < chickenLoc.size() ; chicken++){
            int curHX, curHY, curCX, curCY;
            tie(curHX, curHY) = houseLoc[house];
            tie(curCX, curCY) = chickenLoc[chicken];
            chickenDist[house][chicken]=abs(curHX-curCX)+abs(curHY-curCY);
        }
    }
    vector<int> arr;
    vector<bool> temp;
	for(int i = 0 ; i < chickenLoc.size() ; i++){
    	arr.push_back(i);
    	if(i<M)
    		temp.push_back(true);
    	else
    		temp.push_back(false);	}
    int smallest = INT_MAX;
    do{
    	int dist[houseLoc.size()];
    	int tmp=0;
    	for(int i = 0 ; i < houseLoc.size() ; i++){
    		dist[i]=INT_MAX;
		}
		for(int chickenNo = 0 ; chickenNo < arr.size() ; chickenNo++){
			if(temp[chickenNo]){
				for(int houseNo = 0 ; houseNo < houseLoc.size() ; houseNo++){
					dist[houseNo]=min(dist[houseNo],chickenDist[houseNo][chickenNo]);
				}
			}
		}
		for(int i = 0 ; i < houseLoc.size();i++){
			tmp+=dist[i];
		}
		smallest = min(smallest, tmp);
	}while(prev_permutation(temp.begin(),temp.end()));
	printf("%d",smallest);
	return 0;
}