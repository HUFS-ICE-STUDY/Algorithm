#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> passengers(N);
	for(int i = 0 ; i < N ; i++)
		cin >> passengers[i];
	vector<int> sums(N);
	sums[0] = passengers[0];
	for(int i = 1 ; i < N ; i++){
		sums[i]=sums[i-1]+passengers[i];
	}
	int maxTrain;
	cin >> maxTrain;
	vector< vector<int> > smallTrain(3, vector<int>(N,0));
	smallTrain[0][maxTrain-1] = sums[maxTrain-1];
	for(int i = maxTrain ; i < N ; i++){
		smallTrain[0][i] = max(smallTrain[0][i-1], sums[i]-sums[i-maxTrain]);
	}
	for(int train = 1 ; train < 3 ; train++){
		for(int i = 0 ; i < N ; i++){
			if(i < train*maxTrain+1)
				continue;
			smallTrain[train][i]=max(smallTrain[train][i-1], smallTrain[train-1][i-maxTrain]+sums[i]-sums[i-maxTrain]);
		}	
	}
	cout<<smallTrain[2][N-1];
}
