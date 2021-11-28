#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	s1 = ' '+s1;
	s2 = ' '+s2;
	s3 = ' '+s3;
	vector< vector< vector< int > > > LCS;
	LCS.resize(s1.size(), vector< vector<int> >(s2.size(), vector<int>(s3.size(),0)));
	for(int i = 1 ; i < s1.size() ; i++){
		for(int j = 1 ; j < s2.size() ; j++){
			for(int k = 1 ; k < s3.size(); k++){
				if(s1[i]==s2[j] && s2[j]==s3[k])
					LCS[i][j][k] = LCS[i-1][j-1][k-1]+1;
				else{
					LCS[i][j][k] = max({LCS[i-1][j][k],LCS[i][j-1][k],LCS[i][j][k-1]});
				}
			}
		}
	}
	cout<<LCS[s1.size()-1][s2.size()-1][s3.size()-1];
}
