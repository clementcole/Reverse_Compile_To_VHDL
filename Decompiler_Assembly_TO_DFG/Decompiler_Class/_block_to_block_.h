#ifndef CONNECTED_BLOCKS_GRAPHS_H
#define CONNECTED_BLOCKS_GRAPHS_H

using namespace std;

struct AlistNode{
    int destination;
    struct AlistNode* next;
};

struct Alist{
	struct AlistNode *head;
};

class Block_Graph{
	 private: 
			int V;
			struct Alist* adjacents;
	 public:
			Block_Graph(int V){
				this->V = V;
				adjacents = new Alist[V];
				for (int i = 0; i < V;  ++i){ adjacents[i].head = NULL;	}
			}
			AlistNode* newAlistNode(int dest){
				AlistNode* newNode = new AlistNode;
				newNode -> destination = dest;
				newNode->next = NULL;
				return newNode;
			}
			void addEdge(int src, int dest){
			    AlistNode* newNode = newAlistNode(dest);
			    newNode->next = adjacents[src].head;
			    adjacents[src].head = newNode;
			    newNode = newAlistNode(src);
			    newNode->next = adjacents[dest].head;
			    tadjacents[dest].head = newNode;
			}
			void print_Block_Graph(){
    			ofstream temp;
    			temp.open("temp.dot");
    			int v;
    			for(v = 0; v < V; ++v){
    				AlistNode* path_finder =  adjacents[v].head;
    				temp<< v;
    				while(path_finder){ 
    					temp <<'%s'<< path_finder->destination;
    					path_finder = path_finder->next;
    				}
    				temp<<endl;
    			}
    	    }
};
/*
graph.write("\nGraph gh(%s);\n"%(str(gi)))
            __IMPLEMENT_GRAPH__(graph, dotfile)
            graph.write("\ngh.printGraph();\n")
            graph.write("%s<<\"}\"<<endl;"%(dotfile))

*/
#endif
