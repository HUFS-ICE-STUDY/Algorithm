#include <iostream>
#include <map>

using namespace std;

int n, l;
map<int, pair<int, int> > trafficLight;

// figure out the truck can pass right away or not
int canPass(int time, pair<int, int> light){
	int cycle = light.first+light.second;
	int curLight = time%cycle;
	//returns waiting time. if can pass right away cuz of green light, then return value is minus.
	return light.first - curLight;
}

int main(){
	cin >> n >> l;
	for(int i = 0 ; i < n ; i++){
		int loc, red, green;
		cin >> loc >> red >> green;
		trafficLight[loc] = make_pair(red, green);
	}
	int timer = 0;
	int location = 0;
	while(location <= l){
		//time increase every loop
		timer ++;
		//if there is a traffic light in location
		if(trafficLight.find(location) != trafficLight.end()){
			//get waiting time
			int iter = canPass(timer, trafficLight[location]);
			//if waiting time is under zero, no adding.
			//if waiting time is over zero, add waiting time to timer.
			timer = iter < 0 ? timer : timer+iter;
		}
		//if out of checking traffic light, move location + 1.
		location++;
	}
	cout << timer;
}
