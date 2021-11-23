#include<iostream>
using namespace std;
int main(){
	int N, K;
	cin >> N >> K;
	int god[N];
	
	bool visited[N] = {false,};
	
	for(int i = 0 ; i < N ; i++){
		cin >> god[i];
	}
	
	int count = 0;
	int cur = 0;
	bool found = true;
	
	while(true){
		visited[cur]=true;
		int next = god[cur];
		if(visited[next]){
			found = false;
			break;
		}
		cur = next;
		count++;
		if(next == K)
			break;
	}

	if(found)
		cout << count;
	else{
		cout<< -1 ;
	}
	return 0;
}
