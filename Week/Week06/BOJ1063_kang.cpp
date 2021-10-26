#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> char2num;
map<int, char> num2char;
// pair( numver / character )
map<string, pair<int,int> > commands = {{"R", make_pair(0,1)},
										{"L", make_pair(0,-1)},
										{"B", make_pair(-1,0)},
										{"T", make_pair(1,0)},
										{"RT", make_pair(1,1)},
										{"LT", make_pair(1,-1)},
										{"RB", make_pair(-1,1)},
										{"LB", make_pair(-1,-1)}};

char a = 'A';
pair<int, int> king_dir;
pair<int, int> rock_dir;

bool inRange(int x, int y){
	// if out of range : true
	// else : false
	return 1 <= x && x < 9 && 0 <= y && y < 8;
}

void move(pair<int, int> dir){
	int dx = dir.first;
	int dy = dir.second;
	int nextking_dx = king_dir.first + dx;
	int nextking_dy = king_dir.second + dy;
	if(inRange(nextking_dx, nextking_dy)){
		if( nextking_dx == rock_dir.first && nextking_dy == rock_dir.second ){
			int nextrock_dx = rock_dir.first + dx;
			int nextrock_dy = rock_dir.second + dy;
			if(inRange(nextrock_dx, nextrock_dy)){
				king_dir = make_pair(nextking_dx, nextking_dy);
				rock_dir = make_pair(nextrock_dx, nextrock_dy);
				return ;
			}
			return ;
		}
		king_dir = make_pair(nextking_dx, nextking_dy);
	}
	return ;	
}

int main(){
	for(int i = 0 ; i < 8 ; i++){
		num2char[i] = a;
		char2num[a++] = i;
	}
	string king, rock;
	int N;
	cin >> king >> rock >> N;

	int num = king[1]-'0';

	king_dir = make_pair(num, char2num[king[0]]);
	num = rock[1]-'0';
	rock_dir = make_pair(num, char2num[rock[0]]);
	
	string command;
	for(int i = 0 ; i < N ; i++){
		cin >> command;
		move(commands[command]);
	}
	cout << num2char[king_dir.second]<<king_dir.first<<endl;
	cout << num2char[rock_dir.second]<<rock_dir.first<< endl;	
}
