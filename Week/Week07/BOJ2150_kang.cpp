#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int V;
int E;
vector<vector<int> > answerList ;
int scc_count = 0;

class Graph{
	private:
		int g_size;					// total size of graph
		vector<int>* graph;			// make graph by adjacency list( 인접리스트 ) 
		vector<int>* inv_graph;		// to use Kosaraju-Sharir, make another graph, which direction is opposite of original graph. 
		stack<int> s_sink;			// make stack of sink node.
		bool* visited;				// about visited or not.
		vector<int> answer;			// to remember which node visited.( only for print )
	public:
	
		/* 	
		initialize graph
		input: graph size n
		using n, make adjacency list graph & inverse graph, and visited.
		in this problem, not using 0 index so mark visited[0] as true.
		*/
		Graph(int n){
			g_size = n;
			graph = new vector<int>[g_size];
			inv_graph = new vector<int>[g_size];
			visited = new bool[g_size] {false,};
			visited[0] = true;
		};
		/*
		sort graph's order.
		ex)
			1 4
			4 5
			5 1
			1 6
			6 7
			2 7
			7 3
			3 7
			7 2
			as input of edges, then graph looks like
			
			graph = { {},		0
					  {4,6},	1
					  {7},		2
					  {7},		3
					  {5},		4
					  {1},		5
					  {7},		6
					  {3,2} };	7 --> the adjacent node is not ordered, so make this increasing order.
					  
			## After sortAll() ##
			
			graph = { {},		0
					  {4,6},	1
					  {7},		2
					  {7},		3
					  {5},		4
					  {1},		5
					  {7},		6
					  {2,3} };	7
		*/
		void sortAll(){
			for(int i = 0 ; i < g_size ; i++){
				sort(graph[i].begin(), graph[i].end());
				sort(inv_graph[i].begin(), inv_graph[i].end());
			}
		}
		
		/*
		insert node to graph.
		input : u, v 
		this mean that edge is u->v, directed.
		*/
		void insert(int u, int v){
			graph[u].push_back(v);
			inv_graph[v].push_back(u);
		}
		
		/*
		normal DFS on original graph but append node to answer ( which is vector<int> ) to print answer.
		*/
		void DFS(int node){
			visited[node] = true;
			answer.push_back(node);
			for(int i = 0 ; i < graph[node].size() ; i++){
				if(!visited[graph[node][i]])
					DFS(graph[node][i]);
			}
		}
		/*
		normal DFS but on inversed graph.
		*/
		void invDFS(int node){
			visited[node] = true;
			for(int i = 0 ; i < inv_graph[node].size() ; i++){
				if(!visited[inv_graph[node][i]])
					invDFS(inv_graph[node][i]);
			}
	
			s_sink.push(node);
		}
		/*
		to use kosaraju-sharir algorithm, have to mark inversed graph's sink node to figure out SCC.
		by doing DFS on inverse graph, we know which node is sink node.
		after finish DFS, clean up visited array.
		*/
		void fillStack(){
			for(int i = 0 ; i < g_size ; i++){
				if(!visited[i]){
					// cout << "visit "<<i<<endl;
					invDFS(i);
				}
			}
			visited = new bool[g_size]{false,};
			visited[0]=true;
		}
		
		/*
		core function on this graph.
		pop every nodes in stack, and do DFS noramly.
		then the nodes that fill in answer list is the Strongly Connected Components.
		append answer to answerList.
		then clean up the answer to fill another SCC.
		*/
		int SCC(){
			while(!s_sink.empty()){
				int node = s_sink.top();
				s_sink.pop();
				if (!visited[node]){
					DFS(node);
					scc_count++;
					answerList.push_back(answer);
					answer.clear();
				}
			}
			return scc_count;
		}
	
};

int main() {
	cin >> V >> E;
	Graph graph = Graph(++V);

	/*
	insert node by edge info.
	*/
	for(int i = 0 ; i < E ; i++){
		int u, v;
		cin >> u >> v;
		graph.insert(u,v);
	}
	
	graph.sortAll();
	
	graph.fillStack();
	
	cout << graph.SCC() << endl;
	/*
	have to print nodes order by smallest number in SCC.
	ex) 
		SCC1 : 4 5 1
		SCC2 : 3 2 7
		SCC3 : 6
	then have to print--
		1 5 4 -1
		2 3 7 -1
		6 -1
	in my code, all answer's are stored in vector.
	ex)
	answerList = {{4, 5, 1},
				  {3, 2, 7},
				  {6}};
	using under for looop, make answerList like beneath this line.
	answerList = {{1, 4, 5},
				  {2, 3, 7},
				  {6}};
	*/
	for(int i = 0; i < answerList.size(); i++){
		sort(answerList[i].begin(), answerList[i].end());
	}
	/*
	but sometime answerList can look like this
	answerList = {{2, 3, 7},
				  {1, 4, 5},
				  {6}};
	so, sort answerList again. like beneath this line.
	answerList = {{1, 4, 5},
				  {2, 3, 7},
				  {6}};
	*/
	sort(answerList.begin(), answerList.end());
	for(int i = 0; i < answerList.size(); i++){
		for(int j = 0 ; j < answerList[i].size();j++){
			cout << answerList[i][j] << " ";
		}
		cout << "-1 " <<endl;
	}
	return 0;
}
