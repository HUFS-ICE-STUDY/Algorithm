#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> houses(N);
	for(int i = 0 ; i < N ; i++){
		cin>>houses[i];
	}
	vector<int> dist(N);
	dist[0] = 0;

	sort(houses.begin(),houses.end());
	long lastDistSum=0;
	int lastIdx = N-1;
	int maxVal=houses[N-1];
	for(int i = 0 ; i < N ; i++){
		lastDistSum += maxVal - houses[i];
	}
//	printf("%d\n",lastDistSum);
	long minDistSum = lastDistSum;
	int minIdx = N-1;
	
	for(int i = N-2 ; i >= 0 ; i--){
		long distSum = lastDistSum - (houses[lastIdx]-houses[i])*(2*lastIdx-N);
//		printf("distSum = lastDistSum - (houses[lastIdx]-houses[i])*(2*lastIdx-N)\n");
//		printf("%d = %d - (%d - %d)*(2*%d + 2 - %d)\n",distSum,lastDistSum,houses[lastIdx],houses[i],lastIdx,N);
		if(distSum<=minDistSum){
			minDistSum=distSum;
			minIdx=i;
		}
		lastDistSum=distSum;
		lastIdx=i;
	}
	printf("%d",houses[minIdx]);
}
