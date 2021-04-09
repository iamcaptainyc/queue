#include <iostream>
#include <iomanip>
#include "queue.h"

#define MAXINT 32767
#define MAXVNUM 100

using namespace std;

typedef char vtype;
typedef int arctype;

typedef struct{
	vtype vex[MAXVNUM];
	arctype arcs[MAXVNUM][MAXVNUM];
	int vexnum,arcnum;
}AMGraph;

int locate(AMGraph G,vtype v)
{
	for(int i=0;i<G.vexnum;i++){
		if(G.vex[i]==v) return i;
	}
	return -1;
}

int createUDN(AMGraph &G)//建无向网 
{
	cout<<"请输入节点个数与边数目：\n";
	cin>>G.vexnum>>G.arcnum;//输入节点数目和边的数目 
	for(int i=0;i<G.vexnum;i++){//输入点 
		cin>>G.vex[i];
	}
	for(int i=0;i<G.vexnum;i++){
		for(int j=0;j<G.vexnum;j++){
			G.arcs[i][j]=MAXINT;
		}
	}
	
	cout<<"please input the vex i,vex j and the weight as sequence:\n";
	for(int i=0;i<G.arcnum;i++){//输入权值
		vtype v1,v2;
		int i1,i2,weight;
		cin>>v1>>v2>>weight;
		i1=locate(G,v1),i2=locate(G,v2);
		G.arcs[i2][i1]=G.arcs[i1][i2]=weight;
	}
}

void show(AMGraph &G)
{
	cout<<"该无向图顶点个数为"<<G.vexnum<<'\n';
	cout<<"该无向图边的个数为"<<G.arcnum<<'\n';
	
	cout<<"The vexes:\n";
	for(int i=0;i<G.vexnum;i++){
		cout<<G.vex[i]<<' ';
	} 
	
	cout<<'\n'<<"The AMGraph:\n";
	for(int i=0;i<G.vexnum;i++){
		for(int j=0;j<G.vexnum;j++){
			cout<<setw(6)<<G.arcs[i][j];
		}
		cout<<'\n';
	}
}

int firstadjvex(AMGraph G,vtype v)
{
	for(int i=0;i<G.vexnum;i++){
		if(G.arcs[v][i]<MAXINT) return i;
	}
	return -1;
}

int nextadjvex(AMGraph G,vtype v,vtype w)
{
	for(int i=w+1;i<G.vexnum;i++){
		if(G.arcs[v][i]<MAXINT) return i;
	}
	return -1;
}



bool visited[MAXVNUM];

void dfs(AMGraph G,vtype v)
{
	int w;
	visited[v]=true;
	cout<<G.vex[v]<<' ';
	for(w=firstadjvex(G,v);w>=0;w=nextadjvex(G,v,w)){
		if(!visited[w]) dfs(G,w);
	}
}

void dfstraverse(AMGraph G)
{
	for(int i=0;i<G.vexnum;i++){
		visited[i]=false;
	}
	
	for(int v=0;v<G.vexnum;v++){
		if(!visited[v]) dfs(G,v);
	}
}

void bfs(AMGraph G,vtype v)
{
	cout<<G.vex[v]<<' ';
	visited[v]=true;
	queue q;
	iniqueue(q);
	enqueue(q,v);
	while(!empty(q)){
		int u;
		dequeue(q,u);
		for(int w=firstadjvex(G,u);w>=0;w=nextadjvex(G,u,w)){
			if(!visited[w]){
				cout<<G.vex[w]<<' ';
				visited[w]=true;
				enqueue(q,w);
			}
		}
	}
}

void bfstraverse(AMGraph G)
{
	for(int i=0;i<G.vexnum;i++){
		visited[i]=false;
	}
	for(int v=0;v<G.vexnum;v++){
		if(!visited[v]) bfs(G,v);
	}
}

//普里姆算法
struct close{
	vtype adjvex;//存节点数据 
	arctype lowcost;
}closedge[MAXVNUM];

int Min(struct close closedge[])
{
	int min;
	for(int i=0;i<MAXVNUM;i++){
		if(closedge[i].lowcost!=0){
			min=i;
			break;
		} 
	}
	for(int i=0;i<MAXVNUM;i++){
		if(closedge[i].lowcost!=0&&closedge[i].lowcost<closedge[min].lowcost)
			min=i; 
	}
	return min;
 } 

void prim(AMGraph G,vtype u)
{
	int k;
	k=locate(G,u);//找到对应下标 
	for(int i=0;i<G.vexnum;i++){
		if(i!=k) closedge[i]={u,G.arcs[k][i]};
	}
	closedge[k].lowcost=0;
	
	for(int i=1;i<G.vexnum;i++){
		k=Min(closedge);
		cout<<closedge[k].adjvex<<' '<<G.vex[k]<<'\n';
		closedge[k].lowcost=0;
		for(int j=0;j<G.vexnum;j++){
			if(G.arcs[k][j]<closedge[j].lowcost){
				closedge[j].lowcost=G.arcs[k][j];
				closedge[j].adjvex=G.vex[k];
			}
		}
	}
}


int main()
{
	AMGraph G;
	createUDN(G);
	show(G);
	cout<<endl<<"以下为DFS：\n";
	dfstraverse(G);
	cout<<endl<<"以下为BFS：\n";
	bfstraverse(G);
	cout<<'\n'<<"以下为普里姆算法：\n";
	prim(G,G.vex[0]);
	return 0;
}
