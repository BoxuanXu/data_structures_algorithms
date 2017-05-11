/*******************************************************************************
*
* FileName : graph.h
* Comment  : graph implemented in adjacency matrix
* Version  : 1.0
* Author   : tranticket.com
* Date     : 2017-03-30 13:20
*
*******************************************************************************/

#ifndef _GRAPH_XUBX_H_INCLUDED
#define _GRAPH_XUBX_H_INCLUDED

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class g_Node
{
public:
	int data;
	bool visited;
	vector<int> e;
	g_Node(int val = -1, bool flag = false):data(val), visited(flag){}
	
	void Visited()
	{
		cout<<data<<endl;
	}
		
	bool operator==(g_Node& gN)
	{
		if(data == gN.data && e == gN.e)
			return true;
		else
			return false;
	}
};

class graph
{
public:
	graph()
	{
		max_node = 0;
		max_edge = 0;
	}
	graph(graph& g)
	{
		gg = g.gg;
		max_node = g.max_node;
		max_edge = g.max_edge;
	}

	bool insert_node(g_Node& g)
	{
		gg.push_back(g);
		max_node++;
		return true;	
	}
	

	bool delete_node(int x)
	{
		if(x > gg.size() || x < 0)
			return false;
		vector<g_Node>::iterator iter = gg.begin();
		iter = iter + x;
		gg.erase(iter);
		max_node--;
		return true;
	}	
	
	bool insert_edge(int x, int y)
	{
		if((x > gg.size() || x < 0) || (y > gg.size() || y < 0))
			return false;
		
		for(vector<int>::iterator iter = gg[x].e.begin();iter != gg[x].e.end();++iter)
		{
			if(gg[*iter] == gg[y])
			{
				cout<<"insert false!"<<endl;
				return false;
			}	
		}
		gg[x].e.push_back(y);
		max_edge++;
		return true;
	}

	
	bool delete_edge(int x, int y)
	{
		if((x > gg.size() || x < 0) || (y > gg.size() || y < 0))
			return false;
		
		for(vector<int>::iterator iter = gg[x].e.begin();iter != gg[x].e.end();++iter)
		{
			if(gg[*iter] == gg[y])
			{
				gg[x].e.erase(iter);
				max_edge--;
				return true;
			}	
		}
		cout<<"delete false!"<<endl;
		return false;
	}

	void print_graph()
	{
		if(gg.size() < 1)
		{
			cout<<"graph is empty!"<<endl;
			return;
		}
		
		for(size_t n = 0;n < gg.size();++n)
		{
			cout<<"node is:"<<n<<",";
			for(vector<int>::iterator iter = gg[n].e.begin();iter != gg[n].e.end();++iter)
			{
				cout<<"edge is:"<<*iter<<",";
			}
			cout<<endl;
		}
	}

	void search_first_byBFS()
	{
		for(int i =0;i < max_node;++i)
		{
			if(!gg[i].visited)
			{
				BFS(gg[i]);
			}
		}
		for(vector<g_Node>::iterator k = gg.begin(); k != gg.end(); ++k)//改变访问标志，以便下次访问
			k->visited = false;
	}	

	void BFS(g_Node& gn)
	{
		queue<g_Node> q;
		q.push(gn);
		
		while(q.size())
		{
			g_Node &tmp_gn = q.front();
			if(!tmp_gn.visited)
			{
				tmp_gn.Visited();
				tmp_gn.visited = true;
				for(vector<int>::iterator iter = tmp_gn.e.begin();iter != tmp_gn.e.end();++iter)
				{
					g_Node& t_gn = gg[*iter];
					if(!t_gn.visited)
					{
						
						t_gn.Visited();
						t_gn.visited = true;
						q.push(t_gn);
					}	
				}
			}
			q.pop();
		}
	}

	void search_first_byDFS()
	{
		for(int i =0;i < max_node;++i)
		{
			if(!gg[i].visited)
			{
				DFS(gg[i]);
			}
		}
		for(vector<g_Node>::iterator k = gg.begin(); k != gg.end(); ++k)//改变访问标志，以便下次访问
			k->visited = false;
	}	
	void DFS(g_Node& gn)
	{
		
		gn.Visited();
		gn.visited = true;
		
		for(vector<int>::iterator iter = gn.e.begin();iter != gn.e.end();++iter)
		{
			g_Node &t_gn = gg[*iter];
			if(!t_gn.visited)
				DFS(t_gn);
		}

	}
		
private:
	vector<g_Node> gg;
	int max_node;
	int max_edge;
};

#endif
