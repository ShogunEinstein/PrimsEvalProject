//prim's algorithm
//////////////////
//prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted undirected cost.
//it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.
//this algorithm is directly based on the mst(minimum spanning tree) property.
//mst-prim(g, w, r)
//1.	for each u  v [g]
//2.	do key[u] ← ∞
//3.	π[u] ← nil
//4.	key[r] ← 0
//5.	q ← v [g]
//6.	while q ≠ ø
//7.		do u ← extract-min(q)
//8.			for each v  adj[u]
//9.				do if v  q and w(u, v) < key[v]
//10.					then π[v] ← u
//11.						key[v] ← w(u, v)
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <conio.h>
using namespace std;
#define SIZE 100
#define INFINITY 9999

class prims {
    int graph[SIZE][SIZE],nodes;
public:
    prims();
    void createGraph();
    void primsAlgo();
};

prims::prims() {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            graph[i][j]=0;
}

void prims::createGraph(){
    int i,j,k=0;
    string line;
    ifstream myfile ("sparseAdjMat.txt");
    nodes = SIZE;
    cout << "\nProcessing adjacency matrix...\n";
    if (myfile.is_open()) {
        for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++) {
                getline (myfile,line);
                graph[i][j] = stoi(line);
                if(k != nodes) {
                    //cout << line << ' ';
                    k++;
                }
                else {
                    k = 1;
                    //cout << endl << line << ' ';
                }
            }
            myfile.close();
    }
    else cout << "Unable to open file\n"; 
    //Assign infinity to all graph[i][j] where weight is 0.
    for(i = 0; i < nodes; i++){
        for(j = 0; j < nodes; j++){
            if(graph[i][j] == 0)
                graph[i][j] = INFINITY;
        }
    }
}

void prims::primsAlgo() {
    int visited[SIZE]={0};
    int i,j,a,b,u,v,min;
    int mincost = 0;
    int numEdges = 1;
    visited[1]=1;
    printf("\n");
    while(numEdges < nodes) {
        for(i=0,min=9999; i<nodes; i++)
            for(j=0; j<nodes; j++)
                if(graph[i][j] < min)
                    if(visited[i] != 0) {
                        min=graph[i][j];
                        a=u=i;
                        b=v=j;
                    }
                    if(visited[u]==0 || visited[v]==0) {
                        cout << "\nEdge " << numEdges++ << ":(" << a+1 << ' ' << b+1 << ") cost:" << min;
                        mincost+=min;
                        visited[b]=1;
                    }
                    graph[a][b]=graph[b][a]=9999;
    }
    cout << "\nMinimun cost = " << mincost;
}

void main() {
    prims MST;
    cout<<"\nPrim's Algorithm to find Minimum Spanning Tree\n";
    MST.createGraph();
    clock_t begin = clock();
    MST.primsAlgo();
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "\nElapsed milliseconds for prim's algorithm: " <<  elapsed_secs * 1000 << "ms" << endl;    
    return;
}