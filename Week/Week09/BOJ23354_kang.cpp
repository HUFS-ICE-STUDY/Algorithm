#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> armyUnit;
vector<pair<int, int> > deserter;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<vector<int> > > dijkstra; // do dijkstra "# of deserter" times
vector<vector<int> > map;

// loc의 범위 확인
bool inRange(pair<int, int> loc){
	return 0 <= loc.first && loc.first < N && 0 <= loc.second && loc.second < N;
}

void Dijkstra(pair<int, int> loc, int num){
	/*
		기존의 dijkstra를 임의의 그래프에서 진행했다면, 여기서는 NxN matrix에서 진행해야 했기에 조금 헷갈리는 부분이 있었다.
		map[1][2]는 노드 1에서 2까지의 weight를 의미하는것이 아니기 때문이다.
		그것만 주의하여, dijkstra를 진행하면 된다.
	*/
	
	vector<vector<int> > tmp = dijkstra[num];
	vector<vector<bool> > visited;
	visited.resize(N, vector<bool>(N,false));
	visited[loc.first][loc.second] = true;
	tmp[loc.first][loc.second] = 0;
	priority_queue<pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, greater< pair<int, pair<int, int> > > >pq;
	pq.push(make_pair(0, loc));
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		pair<int, int> curLoc = pq.top().second;
		pq.pop();
		if(tmp[curLoc.first][curLoc.second] < dist) continue; 
		for(int i = 0 ; i < 4 ; i++){
			pair<int, int> nextLoc = make_pair(curLoc.first + dx[i], curLoc.second + dy[i]);
			if(inRange(nextLoc)){
				int alt = dist + map[nextLoc.first][nextLoc.second];
				if( alt < tmp[nextLoc.first][nextLoc.second]){
					tmp[nextLoc.first][nextLoc.second] = alt;
					pq.push(make_pair(alt, nextLoc));
				}
			}
		}
	}
}

int main(){
	cin >> N;
	
	map.resize(N, vector<int>(N));
	// map의 크기 조정. N을 입력받아 그냥 2중배열로 선언만 해둔것을 NxN사이즈로 조정.
	for(int x = 0 ; x < N ; x++){
		for(int y = 0 ; y < N ; y++){
			cin >> map[x][y];
			if(map[x][y] == 0){
				// 탈영병 위치 따로 저장.
				deserter.push_back(make_pair(x,y));
			}else if(map[x][y] == -1){
				// -1일 경우 armyUnit에 위치 저장, map에 거리는 0으로 저장 --> dijkstra할때 -1로 나오지 않게 하기 위함.
				armyUnit = make_pair(x,y);
				map[x][y] = 0;
			}
		}
	}
	/*
		탈영병 인원수에 맞춰서 dijkstra를 몇 번 해야할지 결정.
		0은 군부대에서 출발, 1은 탈영병 1부터 출발, 2는 탈영병 2부터 출발...
		3차원 배열로 선언했다.
		dijkstra[0]은 2차원 배열을 가지고 있고, 군부대에서 위치[x][y]까지의 최소거리를 가지고 있다.
		ex ) dijkstra[1][3][3] --> 1번 탈영병 위치에서부터 3,3까지의 최소 거리.
	*/
	dijkstra.resize(deserter.size()+1, vector<vector<int> >(N, vector<int>(N,INT_MAX)));

	// armyUnit( 군부대 ) 와 deserter( 탈영병 ) 을 분리해 두었기 때문에, 인덱스에 맞춰 최대 6번 dijkstra로 최단거리를 탐색한다.
	Dijkstra(armyUnit, 0);
	for(int i = 0 ; i < deserter.size() ; i++){
		Dijkstra(deserter[i], i+1);
	}
	
	// 이후 순열을 사용하기 위해 vector<int> v를 선언한다. 탈영병이 4명일 경우 
	// v = { 1, 2, 3, 4} 이다. 아래부터는 탈영병이 4명이라 가정한다.
	vector<int> v;
	for(int i = 1 ; i < deserter.size()+1 ; i++){
		v.push_back(i);
	}

	// 최후에 출력하기 위하여 globalMin 을 설정한다.
	int globalMin = INT_MAX;
	do{
		int distance = 0;
		int beforeNum = 0;
		/*
			순열이 작동되는 부분이다.
			next_permutaion을 통해서 지속적으로 v의 값들이 변하게 된다.
			그렇게 되면, iter값을 통해서 -- c는 arr[3]={1,2,3} 으로 설정하였을 경우 *arr == 1, *(arr+1) == 2, *(arr+2) == 3 이므로 --
			현재 v가 어떻게 배치되어있는지 얻어낸다.
			얻어온 값은 nowNum으로, 1 2 3 4 의 값을 가진다.
			항상 첫 시작은 군부대에서 시작하여 군부대로 끝난다는것을 명심하자.
			그를위해 beforeNum은 0이다 -- 0은 군부대를 의미한다 -- 
			nowNum은 현재 탈영병 번호이다.
			next는 현재 탈영병 위치인데, deserter[nowNum - 1] 을 하는 이유는 deserter의 index가 0123 이기 때문이다.
			초기 beforeNum은 0이므로, distance 에 dijkstra[0][next.first][next.second] 값이 더해진다.
			즉 distance에 군부대에서 next에 해당하는 위치까지의 최소 거리가 더해지는 것이다.
		*/
		for(auto it = v.begin() ; it != v.end() ; ++it){
			int nowNum = *it;
			pair<int, int> next = deserter[nowNum-1];
			distance += dijkstra[beforeNum][next.first][next.second];
			beforeNum = nowNum;
		}
		/*
			어떤 조합의 순서에 의해 ( 예를 들어 조합이 2 1 3 4 로 끝났다고 해보자 )
			distance에는 3번 탈영병 위치에서 4번 탈영병 위치로의 최소값을 더해주었기 때문에, 부대로 복귀해야 한다.
			따라서 4번 위치에서 armyUnit의 위치까지의 거리를 한번 더 더해준다.
		*/
		distance += dijkstra[beforeNum][armyUnit.first][armyUnit.second];
		// 마지막으로, globalMin을 update해준다.
		globalMin = distance < globalMin ? distance : globalMin;
		
	}while(next_permutation(v.begin(), v.end()));
	cout<<globalMin;
}
