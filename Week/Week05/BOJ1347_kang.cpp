#include<iostream>
#include<memory.h>

using namespace std;

bool map[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
	int n;
	char c;
	int startx=500, starty=500;
	int x = startx, y=starty;
	int mapstartx,mapstarty,mapendx,mapendy;
	mapstartx=mapstarty=mapendx=mapendy=500;
	map[x][y]=1;
	int dir = 1;
	cin >> n;
	while(n--){
		cin>>c;
		if(c=='R')dir=(dir+1)%4;
		else if(c=='L')dir = (dir+3)%4;
		else{
			x += dx[dir];
			y += dy[dir];
			if(!map[x][y]){
				map[x][y]=1;
				if(dir==0){
					if(y>mapendy)
						mapendy++;
				}
				else if(dir ==1){
					if(x>mapendx)
						mapendx++;
				}
				else if(dir==2){
					if(y<mapstarty)
						mapstarty--;
				}
				else if(dir==3){
					if(x<mapstartx)
						mapstartx--;
				}
			}
		}
//		cout<<"map start x: "<<mapstartx<<" map start y: "<<mapstarty<<endl;
//		cout<<"map end x: "<<mapendx<<" map end y: "<<mapendy<<endl;
//		cout<<"curX: " << x << " curY: " << y<<endl;
//		cout<<"dir: "<<dir<<endl;
//		for(int i = mapstartx;i<=mapendx;i++){
//			for(int j = mapstarty ; j <=mapendy ; j++){
//				if(map[i][j]){
//					cout<<'.';
//				}else{
//					cout<<'#';
//				}
//			}
//			cout<<endl;
//		}
//		cout<<endl<<endl;
	}
	for(int i = mapstartx;i<=mapendx;i++){
		for(int j = mapstarty ; j <=mapendy ; j++){
			if(map[i][j]){
				cout<<'.';
			}else{
				cout<<'#';
			}
		}
		cout<<endl;
	}
}

