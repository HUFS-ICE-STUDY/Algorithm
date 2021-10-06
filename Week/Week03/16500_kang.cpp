#include<iostream>
#include<string>
#include <map>
#include <vector>

using namespace std;

map<char, vector<string> > dict;
string s;
int m;
bool* dp;
int main(){
    cin >> s >> m;
	dp = new bool[s.length()+1];

	for(int i = 0 ; i < s.length()+1 ;i++){
		dp[i] = false;
	}
    dp[s.length()] = true;
    char alpha = 'a';
    for(int i = 0; i < 26 ; i++){
    	vector<string> value;
        dict[alpha+i] = value;
    }
    
    for(int i = 0 ; i < m ; i++){
    	string tmp;
    	cin >> tmp;
    	dict[tmp[0]].push_back(tmp);
	}
		
	for(int i = s.length()-1; i >= 0 ; i--){
//		cout<<i<<endl;
		char s_alpha = s[i];
		for(int j = 0 ; j < dict[s_alpha].size() ; j++){
//			cout << "word: "<<dict[s_alpha][j] << endl;
//			cout << "substring: "<<s.substr(i,dict[s_alpha][j].size())<<endl;
			if(s.substr(i, dict[s_alpha][j].size()) == dict[s_alpha][j]){
//				cout << "HOLYWAK"<<endl;
				dp[i] = dp[i]||dp[i+dict[s_alpha][j].size()];
			}
			for(int k = 0 ; k < s.length(); k++){
				cout << dp[k] << " ";
			}
			cout << endl;
		}
	}
	cout << dp[0];
    
    
    
}
