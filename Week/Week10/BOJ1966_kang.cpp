#include<iostream>
#include<vector>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	for(int itr = 0 ; itr < tc ; itr++){
		int N, T, tmp; // N: # of files, T: target, tmp: priority
		cin >> N >> T;
		vector<pair<int, int> > pq;
		
		// pq에 우선순위와 입력 인덱스를 입력받는다.
		for(int j = 0 ; j < N ; j++){
			cin >> tmp;
			pq.push_back(make_pair(tmp, j));
		}
		//해당 index가 몇번째로 나왔는지가 궁금하기 때문에 count 변수 추가
		int count = 0;
		bool flag = false;
		
		while(true){
			flag = false;
			pair<int, int> front = pq[0];
			
			/* 
			flag == true : 현재 queue의 가장 앞의 문서는 우선순위가 가장 높음 --> 그대로 pop 가능
			flag == false: 현재 queue의 가장 앞에 문서는 우선순위가 가장 높지 않음 --> pop해서 뒤로 push해야함.
			*/

			// 우선순위 check
			for(int i = 1 ; i < pq.size() ; i++){
				if(pq[i].first > front.first){
					flag = true;
					break;
				}
			}

			if(flag){// 다시 뒤로 push
				pq.erase(pq.begin());
				pq.push_back(front);
			}
			else{// 그대로 pop 할 경우
				pq.erase(pq.begin());
				count++;

				// 내가 알고싶던 index가 맞다면 break
				if(front.second==T)
					break;
			}
			
		}
		cout << count << endl;
	}
	return 0;
}
