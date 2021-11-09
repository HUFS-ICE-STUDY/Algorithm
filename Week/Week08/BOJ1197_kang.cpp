#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int V, E;

typedef tuple<int, int, int> edgeInfo; // tuple type name definition

struct Node{
	int key;
	Node* parent;
	int rank=0;
};

/* Union-Find Algorithm */

Node makeNode(int x){
	Node newNode;
	newNode.key = x;
	return newNode;
}

Node* find(Node* x){
	
	while(x->parent!= x){
		x = (x->parent);
	} 
	return x;
}

void unionNode(Node* x, Node* y){
	Node* v = find(x);
	Node* w = find(y);
	if(v->rank > w->rank){
		Node* tmp = v;
		v = w;
		w = tmp;
	}
	v->parent = w;
	if(v->rank == w->rank)
		w->rank ++;
}
/* Union-Find Algorithm end */
int Kruskal(int V, priority_queue<edgeInfo, vector<edgeInfo>, greater<edgeInfo> > edges){

	int r_val = 0;

	Node nodes[V];

	//initialize node for Union-Find
	for(int i = 0 ; i < V ; i++){
		nodes[i] = makeNode(i);
		nodes[i].parent = &nodes[i];
	}

	/* pop edge while edges heap is empty.
	   priority_queue works exactly same as heap, in this used min-heap
	*/

	while(!edges.empty()){
		int w, u, v;
		tie(w,u,v) = edges.top();
		// cout << u << " " << v << " " << w << endl;
		edges.pop();
		// cout << "parent of u: " << find(&nodes[u])->key<<endl;
		// cout << "parent of v: " << find(&nodes[v])->key<<endl;

		// if there is a cycle -- discard edge
		
		if(find(&nodes[u])->key != find(&nodes[v])->key){
			// else -- Union the node -- mark as in the same tree.
			unionNode(&nodes[u],&nodes[v]);
			// append weight
			r_val += w;
		}
	}
	return r_val;
	
}


int main(){
	priority_queue<edgeInfo, vector<edgeInfo>, greater<edgeInfo>> edges;
	cin >> V >> E;

	for(int i = 0 ; i < E ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edgeInfo edge = make_tuple(w,u,v);
		edges.push(edge);
	}
	cout << Kruskal(++V,edges);
	
};
