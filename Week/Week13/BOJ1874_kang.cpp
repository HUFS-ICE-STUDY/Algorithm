#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> target(N);
	stack<int> s;
	for(int i = 0 ; i < N ; i++){
		cin>>target[i];
	}
	vector<char> answer;
	vector<int> a_target;
	int num=1;
	int t_idx=0;
	
	int prev_size = s.size();
	while(true){
		if(s.empty()&&num<=N){
			s.push(num++);
			answer.push_back('+');
			
			if(s.top() == target[t_idx]){
				s.pop();
				answer.push_back('-');
				t_idx++;
				prev_size=-1;
			}
		}
		else{
			if(t_idx<N){
				if(s.top()<target[t_idx]){
					while(s.top() != target[t_idx]){
						s.push(num++);
						answer.push_back('+');
					}
				}else if(s.top() == target[t_idx]){
					s.pop();
					answer.push_back('-');
					t_idx++;
				}
				else{
					cout<<"NO";
					return 0;
				}
			}
		}
		if(s.size() == prev_size)
			break;
		prev_size = s.size();
		
	}
	for(int i = 0 ; i < 2*N ; i++){
		printf("%c\n",answer[i]);
	}
	return 0;
}
