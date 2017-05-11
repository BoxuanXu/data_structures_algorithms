#include "graph_xubx.h"
#include <vector>

int main()
{
	graph G;
	vector<g_Node> v(4);			
	for(int i = 0; i != 4; ++i)	
	{	
		v[i].data = i;			//节点信息
		G.insert_node(v[i]);
	}
	//Graph G(v);
	G.insert_edge(0, 1);
	G.insert_edge(0, 3);
	G.insert_edge(1, 2);
	G.insert_edge(2, 3);
	G.insert_edge(1, 3);

	G.print_graph();
	G.search_first_byBFS();	
	G.search_first_byDFS();	
	return 0;
}
