// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;

// int main(void){
//     // string temp;
//     // cin >> temp;
//     // if (temp == "sibal"){
//     //     cout << "Same";
//     // }else cout<<"No"; 
//     vector<int> tmpVec = {1,2,3,4};
//     for(auto& tmp : tmpVec){
//         tmp=0;
//     }
//     for(auto tmp : tmpVec){
//         cout<<tmp<<" "; 
//     }
// } 

// #include <iostream>

// using namespace std;

// int main(void){
    
//     for(int dan=1;dan<=19;dan++){
//         for(int num=1;num<=19;num++){
//             cout<<dan<<" * "<<num<<" = "<<dan*num;
//             if(num%2==0){
//                 cout<<" "<<endl;
//             }else{
//                 if(num == 19){
//                     cout << endl;
//                 }
//                 else{
//                     cout<<" / ";
//                 }
//             }
//         }
//     }
// }
// #include <iostream>
// #include <climits>
// INT_MIN
// using namespace std;

// int main(){
//     int height;
//     cin >> height;
//     int largest = height * 2;
//     int count = 1;
//     for(int i = 0 ; i < height ; i++){
//         for(int blank = 0 ; blank < (height - i + 1); blank++){
//             cout << " ";
//         }
//         for(int star = 0 ; star < (2*i+1);star++){
//             cout << "*";
//         }
//         cout<<endl;
//     }
//     for(int i = 0 ; i < height-1; i++){
//         for(int blank = 0 ; blank < (i + 1); blank++){
//             cout << " ";
//         }
//         for(int star = 0 ; star < (2*height-2*i-3);star++){
//             cout << "*";
//         }
//         cout<<endl;

//     }
// }

// #include <iostream>
// #include <climits>

// using namespace std;

// #include <iostream>
// #include <climits>

// using namespace std;

// int main(){
//     int N ;
//     cin >> N;
//     int min = INT_MAX;
//     int count = 0;
//     int temp;
//     for(int i = 0 ; i < N ; i++){
//         cin >> temp;
//         if(min == temp){
//             count++;
//         }
//         else if(min > temp){
//             count = 1;
//             min = temp;
//         }
//     }
//     cout<<min << " "<<count;
// }
// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// int main(){
//     string input_str;
//     int q;
//     cin >> input_str >> q;
//     int str_size =  input_str.size();
//     int req;
//     cout << input_str;
//     for(int i = 0 ; i < q ; i++){
//         cin >> req;
//         if (req == 1){
//             char swap=input_str[0];
//             for(int j = 1 ; j < str_size ; j++){
//                 input_str[j-1]=input_str[j];
//             }
//             input_str[str_size-1]=swap;
//         }
//         else if(req == 2){
//             char swap=input_str[str_size-1];
//             for(int j = str_size-1 ; j > 0;j--){
//                 input_str[j]=input_str[j-1];
//             }
//             input_str[0]=swap;
//         }
//         else{
//             reverse(input_str.begin(),input_str.end());
//         }
//         cout<<input_str<<endl;
//     }
// }


// #include <iostream>

// using namespace std;

// int main(){
//     int n, m;
//     cin >> n >> m;
//     int grid[n][m];
//     int num = 0;
//     for(int j = 0 ; j < m ; j++){
//         if (j%2 == 0){
//             for(int i = 0 ; i < n ; i++){
//                 grid[i][j]=num++;
//             }
//         }
//         else{
//             for(int i = n-1 ; i >=0  ; i--){
//                 grid[i][j]=num++;
//             }
//         }
//     }
//     for(int i = 0 ; i < n ; i ++){
//         for (int j = 0; j<m;j++){
//             cout <<grid[i][j];
//         }
//         cout << endl;
//     }
// }

// #include <iostream>
// #include <algorithm>

// using namespace std;

// int main(){
//     int N, k;
//     cin >> N >> k;
//     int num_arr[N];
//     for(int i = 0; i < N; i++){
//         cin >> num_arr[i];
//     }
//     sort(num_arr,num_arr+N);
//     cout << num_arr[k-1];
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// class Student{
//     public:
//         int stdnum;
//         int height;
//         int weight;
//         Student(int num, int h, int w){
//             this->stdnum = num;
//             this->height = h;
//             this->weight = w;
//         }
//         void print_std(){
//             cout << height << " " << weight << " " << stdnum<<endl;
//         }
// };
// int main(){
//     int N;
//     cin >> N;
//     vector<Student> students;
//     int w, h;
//     for(int i = 0; i < N; i++){
        
//         cin >> h >> w;
//         students.push_back(Student(i+1,h,w));
//     }
//     sort(students.begin(),students.end(),
//         [](const Student &a, const Student &b){
//             if(a.height != b.height){
//                 return a.height > b.height;
//             }
//             else{
//                 if(a.weight!=b.weight){
//                     return a.weight > b.weight;
//                 }
//                 return a.stdnum < b.stdnum;
//             }
//     });
//     for(auto stud : students){
//         stud.print_std();

//     }
// }

// #include <iostream>

// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int price[n];
//     for(int i = 0 ; i < n ; i++){
//         cin >> price[i];
//     }
//     int profit = 0;
//     int buy = price[0];
//     for(int i = 1 ; i < n ; i++){
//         if(price[i] - buy >= 0){
//             profit = max(profit, (price[i] - buy));
//         }
//         else{
//             buy = price[i];
//         }
//     }
//     cout << profit;
// }


// #include <iostream>
// #include <string>

// using namespace std;

// int main(){
//     string str;
//     string target;
//     cin >> str;
//     cin >> target;
//     int answer = -1, idx = 0;
//     bool first = true;
    
//     for(int i = 0 ; i < str.size() ; i++){
//         if(str[i] == target[idx]){
//             int temp_i = i;
//             answer = temp_i++;
//             for(int j = 1 ; j < target.size() ; j++){
//                 if(str[temp_i++] != target[j]){
//                     answer = -1;
//                     break;
//                 }
//             }
//             if(answer != -1) break;
//         }
//     }
//     cout << answer;
// }

// #include <iostream>
// #include <string>

// using namespace std;

// int main(){
//     string str, target;
//     cin >> str >> target;
//     for(int str_idx = 0 ; str_idx < str.size() ; str_idx++){
//         if (str.substr(str_idx, target.size()).compare(target) == 0){
//             str.replace(str_idx, target.size(), "");
//             str_idx = -1;
//         }
//     }
//     cout << str;
// }

// #include <iostream>
// #include <string>

// using namespace std;

// int main(){
//     string input_str;
//     cin >> input_str;
//     string answer = "";
//     char target = input_str[0];
//     int count = 1;
//     for(int i = 1 ; i < input_str.size() ; i++){
//         if(target != input_str[i]){
//             answer.push_back(target);
//             answer = answer + to_string(count);
//             target = input_str[i];
//             count = 1;
//         }else{
//             count++;
//         }
//     }
//     answer.push_back(target);
//     answer = answer + to_string(count);
//     cout << answer.size() << endl;
//     cout << answer;
// }

// #include <iostream>

// using namespace std;

// int n,m;
// char box[100][100];

// int main(){
//     cin >> n >> m;
//     int dx[4] = {0,1,0,-1};
//     int dy[4] = {1,0,-1,0};
    
//     pair<int, int> cur = make_pair(0,0);
//     char c = 'A';
//     int dir = 0;
//     int count = 0;
//     while(true){
//         if (count == n*m) break;
//         box[cur.first][cur.second] = c++;
//         if (c > 'Z') c='A';
//         int n_x = cur.first + dx[dir];
//         int n_y = cur.second + dy[dir];
//         if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= m || box[n_x][n_y] != '\0'){
//             dir = (dir+1)%4;
//         }
//         cur.first += dx[dir];
//         cur.second += dy[dir];
//         count++;
//     }
    
//     for(int i = 0 ; i < n ; i++){
//         for(int j = 0 ; j < m ; j++){
//             cout << box[i][j] << " "; 
//         }
//         cout << endl;
//     }
// }

#include <iostream>

using namespace std;

int n;
int box[100][100];

int main(){
    cin >> n;
    int dx[4] = {0,-1,0,1};
    int dy[4] = {1,0,-1,0};
    
    pair<int, int> cur = make_pair(n/2,n/2);
    int dir = 0;
    int num = 1;
    int dist = 1;
    while(num <= n*n){
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < dist ; j++){
                if(num > n*n) break;
                box[cur.first][cur.second] = num++;
                cur.first += dx[dir];
                cur.second += dy[dir];
            }
            dir = (dir+1)%4;
        }
        dist++;
        
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << box[i][j] << " "; 
        }
        cout << endl;
    }
}