#include <iostream>
#include <stack>

using namespace std;

int k;

int main(){
	cin >> k;
	stack<int> nums;
	int num;
	for(int i = 0 ; i < k ; i++){
		cin >> num;
		if(num == 0){
			if(nums.empty()){
				nums.push(num);
			}else{
				nums.pop();
			}
		}else{
			nums.push(num);
		}
	}
	int answer = 0;
	while(!nums.empty()){
		answer += nums.top();
		nums.pop();
	}
	cout << answer;
}
