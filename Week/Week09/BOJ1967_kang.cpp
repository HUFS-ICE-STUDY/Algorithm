#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

//struct Node{
//	int nodeNum;
//	vector<Node*> children;
//	int longest = 0;
//};
class Node{
	private:
		int nodeNum;
		vector<Node*> children;
		int longest = 0;
		int weight = 0;
	public:
		
		Node(int n){
			nodeNum = n;
		}
		
		// add child
		void addChild(Node* child){
			children.push_back(child);
		}
		
		//update weight, which means weight to parent.
		void updateWeight(int w){
			weight = w;
		}
		
		void updateLongest(){
			int newLong = 0;
			for(int i = 0 ; i < children.size(); i++){
				int clong = children[i]->returnLongest();
				int weight = children[i]->returnWeight();
				if( newLong < clong + weight )
					newLong = clong + weight;
			}
			longest = newLong;
		}
		
		vector<Node*> returnChild(){
			return children;
		}
		int returnDiameter(){
			priority_queue<int> pq;
			for(int i = 0 ; i < children.size() ; i++){
				int clong = children[i]->returnLongest();
				int weight = children[i]->returnWeight();
				pq.push(clong+weight);
			}
			pq.push(0);
			int diameter = 0;
			diameter += pq.top();pq.pop();
			diameter += pq.top();
			return diameter;
		}
		int returnNodeNum(){
			return nodeNum;
		}
		
		int returnLongest(){
			return longest;
		}
		
		int returnWeight(){
			return weight;
		}
		
		void printNodeInfo(){
			printf("Node number: %d\nlongest: %d\nWeight: %d\n",nodeNum, longest,weight);
		}
		
		void printNodesChild(){
			printNodeInfo();
			printf("=== # of child: %d ===\n", children.size());
			for(int i = 0 ; i < children.size();i++){
				children[i]->printNodeInfo();
			}
			cout<<"=====================\n";
		}
};

class Tree{
	private:
		int n_vertex;		
		Node* root = nullptr;
		map<int, Node*> location;
		bool* visited;
		int maxDiameter = -1;
		
	public:
		Tree(int n){
			n_vertex = n;
			visited = new bool[n+1];
			visited[0] = true; // 0 not using!!
			root = new Node(1);
			
			location[1] = root;
			for(int i = 2 ; i <= n ; i++){
				location[i] = new Node(i);
			}
			
			// parent, child, weight
			int p, c, w;
			for(int i = 0 ; i < n-1 ; i++){
				cin >> p >> c >> w;
				location[c]->updateWeight(w);
				location[p]->addChild(location[c]);
			}
			
		}
		
		void updateMaxDiameter(int dia){
			if(maxDiameter < dia)
				maxDiameter = dia;
		}
		/**/
		void DFS(Node* node){
			
			vector<Node*> children = node->returnChild();
			for(int i = 0 ; i < children.size() ; i++){
				if(!visited[children[i]->returnNodeNum()])
					DFS(children[i]);
			}
			visited[node->returnNodeNum()]=true;
			
			node->updateLongest();
			int tmp = node->returnDiameter();
//			updateMaxDiameter(node->returnDiameter());
			updateMaxDiameter(tmp);
//			node->printNodeInfo();
//			cout << "curr node diameter: "<<tmp<<endl<<endl;
			
		}
		
		int largestDiameter(){
			DFS(root);
			return maxDiameter;
		} 
		
		void printTreeInfo(){
			cout << "# of vectices: " << n_vertex <<endl;
			for(int i = 1 ; i <= n_vertex ; i++){
				location[i]->printNodesChild();
			}
		}
		void printVisited(){
			for(int i = 1 ; i <= n_vertex ; i++){
				printf("%d\t",i);
			}
			cout<<endl;
			for(int i = 1 ; i <= n_vertex ; i++){
				cout << visited[i] << "\t";
			}
		}
};

int n;

int main(){
	cin >> n;
	Tree t = Tree(n);
	cout << t.largestDiameter();
//	t.printTreeInfo();
//	t.printVisited();
	return 0;
}
