#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> char2num;
map<int, char> num2char;
// pair( numver / character )
char a = 'A';
pair<int, int> knight_dir;

pair<int, int> moveknight[8] = {make_pair(2,1),
								make_pair(2,-1),
								make_pair(-2,1),
								make_pair(-2,-1),
								make_pair(1,2),
								make_pair(-1,2),
								make_pair(1,-2),
								make_pair(-1,-2)};
bool board[7][6];

int main(){
	for(int i = 0 ; i < 6 ; i++){
		num2char[i] = a;
		char2num[a++] = i;
	}
	string start;
	int N;
	cin >> start;
	int num = start[1]-'0';
	pair<int, int> firstLoc = make_pair(num, char2num[start[0]]);;
	knight_dir =firstLoc;
//	cout << "knight: " << knight_dir.first<<" "<< knight_dir.second<<endl;
	board[knight_dir.first][knight_dir.second] = true;
//	for(int x = 1 ; x < 7 ; x++){
//		for(int y = 0 ; y < 6 ; y++){
//			cout << board[x][y] << " ";
//		}
//		cout << endl;
//	}
	string nextLoc;
	for(int i = 0 ; i < 35 ; i++){
		bool over = true;
		cin >> nextLoc;
		int num = nextLoc[1]-'0';
		pair<int, int> next = make_pair(num, char2num[nextLoc[0]]);
//		cout << "next: "<<next.first <<" "<<next.second<<endl;
		
		for(int j = 0 ; j < 8 ; j++){
			int dx = moveknight[j].first;
			int dy = moveknight[j].second;
			if(!board[next.first][next.second] && knight_dir.first+dx == next.first && knight_dir.second+dy == next.second){
//				cout << "satisfy!"<<endl;
				knight_dir = next;
				board[knight_dir.first][knight_dir.second] = true;
				over = false;
//				for(int x = 1 ; x < 7 ; x++){
//					for(int y = 0 ; y < 6 ; y++){
//						cout << board[x][y] << " ";
//					}
//					cout << endl;
//				}
				break;
			}
			
		}
		if(over){
			cout << "Invalid";
			return 0;
		}	
	}
	
	for(int i = 0 ; i < 8 ; i++){
		int dx = moveknight[i].first;
		int dy = moveknight[i].second;
		if(knight_dir.first+dx == firstLoc.first && knight_dir.second+dy == firstLoc.second){
			cout << "Valid";
			return 0;
		}
	}
	cout << "Invalid"	;
	return 0;
}

