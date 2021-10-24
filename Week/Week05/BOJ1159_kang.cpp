#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<char, int> list;
    string tmp;
    vector<char> answer;
    
    for(int i = 0 ; i < n ; i ++){
        cin >> tmp;
        auto cnt = list.find(tmp[0]);
        if(cnt == list.end()){
            list.insert(make_pair(tmp[0],1));
            continue;
        }
        
        list[tmp[0]]++;    
        if(cnt->second == 5){
            answer.push_back(tmp[0]);
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.empty()){
    	cout<<"PREDAJA";
    	return 0;
	}
    for(int i = 0 ; i < answer.size() ; i++){
    	cout<<answer[i];
	}
	return 0;    
}
