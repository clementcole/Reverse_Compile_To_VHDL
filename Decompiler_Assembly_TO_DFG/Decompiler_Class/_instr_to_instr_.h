#ifndef _INSTR_TO_INSTR_
#define _INSTR_TO_INSTR_


struct AlistNode{
    int destination;
    struct AlistNode* next;
};

struct Alist{
	struct AlistNode *head;
};

class instr_To_instr{
	private : 
			int V;
			struct Alist* adjacents;
	public:
			instr_To_instr(int V){
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
			    adjacents[dest].head = newNode;
			}
			void print_Block_Graph(){
    			ofstream temp;
    			temp.open("temp.txt");
    			int v;
    			for(v = 0; v < V; ++v){
    				AlistNode* path_finder =  adjacents[v].head;
    				temp<< v;
    				while(path_finder){ 
    					temp <<"->"<< path_finder->destination;
    					path_finder = path_finder->next;
    				}
    				temp<<endl;
    			}
    	    }
};
/*
def __IMPLEMENT_GRAPH__(cgraph, cdot):
    cgraph.write("\nfor (size_t i = 0; i != op_nodes.size(); ++i) {\n")
    cgraph.write("\t\t%s << op_nodes[i]<< \"[label = \"<<op_labels[i]<<\", shape = box ]\"<<endl;\n"%(cdot))
    cgraph.write("\t\tif (src1_labels[i] != \"0\")\n")
    cgraph.write("\t\t%s << src1_edges[i] << \"[label = \"<<src1_labels[i]<<\", shape = plaintext]\"<<endl;\n"%(cdot))
    cgraph.write("\t\tif (src2_labels[i] != \"0\")\n")
    cgraph.write("\t\t%s << src2_edges[i] << \"[label = \"<<src2_labels[i]<<\", shape = plaintext]\"<<endl;\n"%(cdot))
    cgraph.write("\t\tif (dest_labels[i] != \"0\")\n")
    cgraph.write("\t\t%s << dest_edges[i] << \"[label = \"<<dest_labels[i]<<\", shape = plaintext]\"<<endl;\n"%(cdot))
    cgraph.write("}\n")
    cgraph.write("\nfor (size_t  i = 0; i != op_nodes.size(); ++i){\n")
    cgraph.write("\t\tsize_t j = i + 1;\n")
    cgraph.write("\t\t while (j < op_nodes.size()){\n")
    cgraph.write("\t\t\tif (dest_labels[i] == src1_labels[j]){\n")
    cgraph.write("\t\t\t\tif (src1_labels[j] != \"0\"){\n")
    cgraph.write("\t\t\t\t\tgh.addEdge(i, j);\n")
    cgraph.write("\t\t\t\t\t%s<<op_nodes[i]<<\"->\"<<op_nodes[j]<<\"[label = \"<<src1_labels[j]<<\"]\"<<endl;\n"%(cdot))
    cgraph.write("\t\t\t\t}\n")
    cgraph.write("\t\t\t}\n")# End of if (dest_labels[i] == src1_labels[j])
    cgraph.write("\t\t\tif (dest_labels[i] == src2_labels[j]){\n")
    cgraph.write("\t\t\t\tif (src2_labels[j] != \"0\"){\n")
    cgraph.write("\t\t\t\t\tgh.addEdge(i, j);\n")
    cgraph.write("\t\t\t\t\t%s<<op_nodes[i]<<\"->\"<<op_nodes[j]<<\"[label = \"<<src2_labels[j]<<\"]\"<<endl;\n"%(cdot))
    cgraph.write("\t\t\t\t}\n")
    cgraph.write("\t\t\t}\n")
    cgraph.write("\t\tj++;}\n") 
    cgraph.write("}\n") #End of for loop
    #Implementing Tarjan's algorithm to determine nodes that are connected





graph.write("\nGraph gh(%s);\n"%(str(gi)))
            __IMPLEMENT_GRAPH__(graph, dotfile)
            graph.write("\ngh.printGraph();\n")
            graph.write("%s<<\"}\"<<endl;"%(dotfile))

*/
#endif
/*
#include  <iostream>
#include  <list>
 
using namespace std;
 
// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}
 
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}*/
