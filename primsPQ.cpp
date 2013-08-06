////prim's algorithm (priority queue implementation)

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <time.h>

using namespace std;
#define SIZE 100
#define INFINITY 9999

typedef struct EDGE {
    int tail,head,weight; 
}*ed;

class CompareEdges {
public:
    bool operator()(ed e1, ed e2)
    {
        if (e1->weight > e2->weight) return true;
        return false;
    }
};

class prims {
    priority_queue<ed,vector<ed>, CompareEdges> pq;
public:
    prims();
    void createGraph();
    void primsAlgo();
};

prims::prims() {    
}

void prims::createGraph(){
    int head=0,tail=0,weight=0;
    ed edge;
    string line;
    ifstream myfile ("sparseAdjList1.txt");
    cout << "\nProcessing adjacency list...\n";
    if (myfile.is_open()) {
        getline (myfile,line);
        while(stoi(line) != 10000000) {
            edge = new EDGE;
            edge->head = stoi(line);
            head = edge->head;
            getline (myfile,line);
            edge->tail = stoi(line);
            tail = edge->tail;
            getline (myfile,line);
            edge->weight = stoi(line);
            weight = edge->weight;
            getline (myfile,line);
            pq.push(edge);          
        };
        myfile.close();
    }
    else cout << "Unable to open file\n"; 
}

void prims::primsAlgo() {
    int head=0,tail=0,weight=0;
    int min=0,u=-1,v=-1,a=0,b=0;
    int visited[SIZE]={0};
    int mincost = 0;
    int numEdges = 1;
    head = pq.top()->head;
    tail = pq.top()->tail;
    weight = pq.top()->weight;
    pq.pop();
    visited[1]=1;
    while(!pq.empty()) {
        if(head == tail) {
            //visited[head]=0;
        }          
        else {
            if(visited[head] != 0) {
                min=weight;
                a=u=head;
                b=v=tail;
            }
            if(visited[u]==0 || visited[v]==0) {
                cout << "\nEdge " << numEdges++ << ":(" << a << ' ' << b << ") cost:" << min;
                mincost+=min;
                visited[b]=1;
            }
        }
        pq.pop();
        if(!pq.empty()) {
             
            head = pq.top()->head;
            tail = pq.top()->tail;
            weight = pq.top()->weight;
        }
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