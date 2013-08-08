//O(VlogE) prim's algorithm
///////////////////////////
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <time.h>
using namespace std;
#define SIZE 50
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
// constructor
prims::prims() {    
}
// create graph function
void prims::createGraph(){
    int head=0,tail=0,weight=0;
    ed edge;
    string line;
    ifstream myfile ("sparseAdjList50.txt");
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
// prims O(VlogE) implementation
void prims::primsAlgo() {
    int head=0,tail=0,weight=0;
    int min=0,u=-1,v=-1,a=0,b=0;
    int visited[SIZE+1]={0};
    int mincost = 0;
    int numEdges = 1;
    head = pq.top()->head;
    tail = pq.top()->tail;
    weight = pq.top()->weight;
    pq.pop();
    visited[head]=1;
    while(!pq.empty() && numEdges < SIZE) {
        if(head == tail) {
            visited[head]=0;
        }          
        else {
            if(visited[head] != 0) {
                min=weight;
                a=u=head;
                b=v=tail;
            }
            if(visited[u]==0 || visited[v]==0) {
                cout << "\nEdge " << numEdges++ << ":(" << a << ' ' << b << ") cost:" << min;
                numEdges++;
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
// main function
void main() {
    prims MST;
    cout<<"\nPrim's Algorithm to find Minimum Spanning Tree\n";
    MST.createGraph();
    cout<<"\nStarting Prim's Algorithm...\n";
    clock_t begin = clock();
    MST.primsAlgo();
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "\nElapsed milliseconds for prim's algorithm: " <<  elapsed_secs * 1000 << "ms" << endl;    
    return;
}

//////////prim's algorithm (priority queue implementation)
//////#include <iostream>
//////#include <fstream>
//////#include <queue>
//////#include <string>
//////#include <time.h>
//////
//////using namespace std;
//////
//////#define SIZE 25
//////#define INFINITY 9999
//////const int MAX=322;
//////
//////typedef struct data {
//////    int w,h,t;
//////}*d;
//////
//////class pqueue {
//////public:
//////    data d[MAX];
//////    int count;
//////    int start;
//////    pqueue() {
//////        count=0;
//////        start=0;
//////    }
//////    void insert(data d1);
//////    data top();
//////    void display(int num);
//////    bool empty();
//////};
//////void pqueue :: insert(data d1) {
//////    d[count]=d1;
//////    count++;
//////}
//////data pqueue :: top() {
//////    int temp = start;
//////    start++;
//////    return d[start];   
//////}
//////bool pqueue :: empty() {
//////    if(start < MAX)
//////        return false;
//////    return true;
//////
//////}
//////
//////class prims {
//////    pqueue pq;
//////    int nodes;
//////public:
//////    prims();
//////    void createGraph();
//////    void primsAlgo();
//////};
//////
//////prims::prims() {    
//////}
//////
//////void prims::createGraph(){
//////    int head=0,tail=0,weight=0;
//////    data edge;
//////    string line;
//////    ifstream myfile ("sparseAdjList25.txt");
//////    cout << "\nProcessing adjacency list...\n";
//////    if (myfile.is_open()) {
//////        getline (myfile,line);
//////        while(stoi(line) != 10000000) {
//////            edge.h = stoi(line);
//////            getline (myfile,line);
//////            edge.t = stoi(line);
//////            getline (myfile,line);
//////            edge.w = stoi(line);
//////            getline (myfile,line);
//////            pq.insert(edge);         
//////        };
//////        myfile.close();
//////    }
//////    else cout << "Unable to open file\n"; 
//////}
//////
//////void prims::primsAlgo() {
//////    int head=0,tail=0,weight=0;
//////    int lasthead=0;
//////    int min=1,u=-1,v=-1,a=0,b=0;
//////    int visited[SIZE+1]={0};
//////    int mincost = 0;
//////    int numEdges = 1;
//////    data *ed = new data;
//////    ed = &pq.top();
//////    head = ed.h;
//////    tail = ed.t;
//////    weight = ed.w;
//////    visited[head]=1;
//////    ed = &pq.top();
//////    while(!pq.empty()) {
//////        if(head == tail) {
//////            //visited[head]=0;
//////        }          
//////        else {
//////            if(visited[head] != 0) {
//////                min=weight;
//////                a=u=head;
//////                b=v=tail;
//////            }
//////            if(visited[u]==0 || visited[v]==0) {
//////                cout << "\nEdge " << numEdges++ << ":(" << a << ' ' << b << ") cost:" << min;
//////                mincost+=min;
//////                visited[b]=1;
//////            }
//////        }
//////
//////        ed = &pq.top();
//////        if(!pq.empty()) {
//////            head = ed.h;
//////            tail = ed.t;
//////            weight = ed.w;
//////        }
//////    }
//////    cout << "\nMinimun cost = " << mincost;
//////}
//////
//////void main() {
//////    prims MST;
//////    cout<<"\nPrim's Algorithm to find Minimum Spanning Tree\n";
//////    MST.createGraph();
//////    clock_t begin = clock();
//////    MST.primsAlgo();
//////    clock_t end = clock();
//////    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//////    cout << "\nElapsed milliseconds for prim's algorithm: " <<  elapsed_secs * 1000 << "ms" << endl;    
//////    return;
//////}
////// Prim's Algorithm in C++ using a heap with the best S vertex for
////// every T vertex.  Adjacency lists are used for storing the
////// undirected graph.
////// See CSE 2320 Notes 13
////
////#include <iostream>
////#include <stdlib.h>
////#include <fstream>
////#include <time.h>
////#include <string>
////#include "minHeap.h"
////
////using namespace std;
////
////// Basic Definitions
////
////#define NODES 25
////#define EDGES 322
////#define oo (1000000000)
////
////// Declarations
////
////int numVertices,numEdges;
////struct edge {
////    int tail,head,weight;
////    int next;  // subscript of next edge with same tail 
////};
////typedef struct edge;
////edge edgeTab[EDGES];
////int firstEdge[NODES];  // Table indicating first edge for a tail
////
////void read_input_file()
////{
////    // Reads a file with a weighted, undirected graph and
////    // stores as unordered adjacency lists.
////    int tail,head,weight,i,j,workingEdges;
////
////    // read number of nodes and edges
////    numVertices = NODES;
////    numEdges = EDGES;
////    //edgeTab[EDGES]=(edge) malloc(2*EDGES*sizeof(edge));
////    //firstEdge[NODES]=(int) malloc(NODES*sizeof(int));
////    //if (!firstEdge || !edgeTab)
////    //{
////    //    cout << "edgeTab malloc failed " << __LINE__ << "\n";
////    //    exit(0);
////    //}
////
////    // Initially, all adjacency lists are empty
////    for (i=0;i<numVertices;i++)
////        firstEdge[i]=0;
////
////    // read edges, each with a weight
////    workingEdges=0;
////    string line;
////
////    ifstream myfile ("sparseAdjList25.txt");
////    cout << "\nProcessing adjacency list...\n";
////
////    for (i=0; i<numEdges; i++)
////    {
////        cin >> tail >> head >> weight;
////        // Test for illegal edge.
////        if (tail<0 || tail>numVertices-1 || head<0
////            || head>numVertices-1 || weight<=0)
////        {
////            cout << "Invalid input " << tail << head << weight << " at " <<
////                __LINE__ << "\n";
////            exit(0);
////        }
////        // Save input edge and insert in adjacency list
////        edgeTab[workingEdges].tail=tail;
////        edgeTab[workingEdges].head=head;
////        edgeTab[workingEdges].weight=weight;
////        edgeTab[workingEdges].next=firstEdge[tail];
////        firstEdge[tail]=workingEdges;
////        workingEdges++;
////        // Save inverse of input edge and insert in adjacency list
////        edgeTab[workingEdges].tail=head;
////        edgeTab[workingEdges].head=tail;
////        edgeTab[workingEdges].weight=weight;
////        edgeTab[workingEdges].next=firstEdge[head];
////        firstEdge[head]=workingEdges;
////        workingEdges++;
////    }
////    if (myfile.is_open()) {
////        getline (myfile,line);
////        while(stoi(line) != 10000000) {
////            // Save input edge and insert in adjacency list
////            head = stoi(line);            
////            getline (myfile,line);
////            tail = stoi(line);           
////            getline (myfile,line);
////            weight = stoi(line);           
////            getline (myfile,line);
////            // Save input edge and insert in adjacency list
////            edgeTab[workingEdges].tail=tail;
////            edgeTab[workingEdges].head=head;
////            edgeTab[workingEdges].weight=weight;
////            edgeTab[workingEdges].next=firstEdge[tail];
////            firstEdge[tail]=workingEdges;
////            workingEdges++;
////            // Save inverse of input edge and insert in adjacency list
////            edgeTab[workingEdges].tail=head;
////            edgeTab[workingEdges].head=tail;
////            edgeTab[workingEdges].weight=weight;
////            edgeTab[workingEdges].next=firstEdge[head];
////            firstEdge[head]=workingEdges;
////            workingEdges++;
////        };
////        myfile.close();
////    }
////    else cout << "Unable to open file\n";
////}
////
////void prim()
////{
////    typedef enum {s,t} stType;
////
////    int i,j,MSTedgeCount=0,MSTweight=0;
////    stType *flag;
////    heapEntryType smallest,changing;
////    int *priority,*bestSneighbor;
////
////    flag=(stType*) malloc(numVertices*sizeof(stType));
////    priority=(int*) malloc(numVertices*sizeof(heapEntryType));
////    bestSneighbor=(int*) malloc(numVertices*sizeof(int));
////
////    if (!flag || !priority || !bestSneighbor)
////    {
////        cout << "malloc failed " << __LINE__ << "\n";
////        exit(0);
////    }
////    // Vertex 0 starts in S.  Other vertices start in T.
////    flag[0]=s;
////    for (i=1;i<numVertices;i++)
////        flag[i]=t;
////
////    // Some T vertices might not have an edge from vertex 0.
////    priority[0]=0;  // Dummy entry for vertex 0
////    for (i=1;i<numVertices;i++)
////        priority[i]=oo;
////
////    // Initialize T-heap with edges from vertex 0.
////    for (i=firstEdge[0];
////        i!=(-1);
////        i=edgeTab[i].next)
////    {
////        priority[edgeTab[i].head]=edgeTab[i].weight;
////        bestSneighbor[edgeTab[i].head]=0;
////    }
////
////    // Constructor does BuildMinHeap
////    minHeap heap(numVertices,priority,numVertices);
////    free(priority);
////
////    // Remove dummy entry from heap
////    smallest=heap.extractMin();
////    if (smallest.id!=0)
////    {
////        cout << "Heap problem " << __LINE__ << "\n";
////        exit(0);
////    }
////
////    // Each iteration finds another MST edge
////    for (MSTedgeCount=0;MSTedgeCount<numVertices-1;MSTedgeCount++)
////    {
////        // Get minimum weight edge from S to T.
////        smallest=heap.extractMin();
////        if (smallest.priority==oo) // no edges remain that bridge S & T
////            break;
////
////        MSTweight+=smallest.priority;
////        cout << "Include edge from " << bestSneighbor[smallest.id] <<
////            " to " << smallest.id << " of weight " << smallest.priority << "\n";
////        flag[smallest.id]=s;
////
////        // Scan adjacency list looking for improvements
////        for (j=firstEdge[smallest.id];
////            j!=(-1);
////            j=edgeTab[j].next)
////            if (flag[edgeTab[j].head]==t
////                && edgeTab[j].weight<heap.getPriority(edgeTab[j].head))
////            {
////                changing.id=edgeTab[j].head;
////                changing.priority=edgeTab[j].weight;
////                heap.changePriority(changing);
////                bestSneighbor[edgeTab[j].head]=smallest.id;
////            }
////    }
////    if (MSTedgeCount<numVertices-1)
////        cout << "Stopped after collecting " << MSTedgeCount << " edges of weight "
////        << MSTweight << "\n";
////    else
////        cout << "Found MST with weight " << MSTweight << "\n";
////    free(flag);
////    free(bestSneighbor);
////}
////
////int main()
////{
////    int i,j;
////    float startCPU,stopCPU;
////
////    read_input_file();
////    clock_t begin = clock();
////    prim();
////    clock_t end = clock();
////    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
////    cout << "\nElapsed milliseconds for prim's algorithm: " <<  elapsed_secs * 1000 << "ms" << endl;    
////    free(edgeTab);
////    free(firstEdge);
////    return 0;
////}
//// Prim's Algorithm in C++ using a heap with the best S vertex for
//// every T vertex.  Adjacency lists are used for storing the
//// undirected graph.
//// See CSE 2320 Notes 13
//
//#include <iostream>
//#include <time.h>
//#include <stdlib.h>
//#include "minHeap.h"
//
//using namespace std;
//
////// For getrusage()
////#include <sys/time.h>
////#include <sys/resource.h>
//
//// Basic Definitions
//
//#define oo (1000000000)
//
//// Declarations
//
//int numVertices,numEdges;
//struct edge {
//    int tail,head,weight;
//    int next;  // subscript of next edge with same tail 
//};
//typedef struct edge edgeType;
//edgeType *edgeTab;
//int *firstEdge;  // Table indicating first edge for a tail
//
////float CPUtime()
////{
////    struct rusage rusage;
////
////    getrusage(RUSAGE_SELF,&rusage);
////    return rusage.ru_utime.tv_sec+rusage.ru_utime.tv_usec/1000000.0
////        + rusage.ru_stime.tv_sec+rusage.ru_stime.tv_usec/1000000.0;
////}
//
//void read_input_file()
//{
//    // Reads a file with a weighted, undirected graph and
//    // stores as unordered adjacency lists.
//    int tail,head,weight,i,j,workingEdges;
//
//    // read number of nodes and edges
//    cin >> numVertices >> numEdges;
//
//    // Tables are allocated with space for inverses.
//    firstEdge=(int*) malloc(numVertices*sizeof(int));
//    edgeTab=(edgeType*) malloc(2*numEdges*sizeof(edgeType));
//    if (!firstEdge || !edgeTab)
//    {
//        cout << "edgeTab malloc failed " << __LINE__ << "\n";
//        exit(0);
//    }
//
//    // Initially, all adjacency lists are empty
//    for (i=0;i<numVertices;i++)
//        firstEdge[i]=(-1);
//
//    // read edges, each with a weight
//    workingEdges=0;
//    for (i=0; i<numEdges; i++)
//    {
//        cin >> tail >> head >> weight;
//        // Test for illegal edge.
//        if (tail<0 || tail>numVertices-1 || head<0
//            || head>numVertices-1 || weight<=0)
//        {
//            cout << "Invalid input " << tail << head << weight << " at " <<
//                __LINE__ << "\n";
//            exit(0);
//        }
//        // Save input edge and insert in adjacency list
//        edgeTab[workingEdges].tail=tail;
//        edgeTab[workingEdges].head=head;
//        edgeTab[workingEdges].weight=weight;
//        edgeTab[workingEdges].next=firstEdge[tail];
//        firstEdge[tail]=workingEdges;
//        workingEdges++;
//        // Save inverse of input edge and insert in adjacency list
//        edgeTab[workingEdges].tail=head;
//        edgeTab[workingEdges].head=tail;
//        edgeTab[workingEdges].weight=weight;
//        edgeTab[workingEdges].next=firstEdge[head];
//        firstEdge[head]=workingEdges;
//        workingEdges++;
//    }
//}
//
//void prim()
//{
//    typedef enum {s,t} stType;
//
//    int i,j,MSTedgeCount=0,MSTweight=0;
//    stType *flag;
//    heapEntryType smallest,changing;
//    int *priority,*bestSneighbor;
//
//    flag=(stType*) malloc(numVertices*sizeof(stType));
//    priority=(int*) malloc(numVertices*sizeof(heapEntryType));
//    bestSneighbor=(int*) malloc(numVertices*sizeof(int));
//
//    if (!flag || !priority || !bestSneighbor)
//    {
//        cout << "malloc failed " << __LINE__ << "\n";
//        exit(0);
//    }
//    // Vertex 0 starts in S.  Other vertices start in T.
//    flag[0]=s;
//    for (i=1;i<numVertices;i++)
//        flag[i]=t;
//
//    // Some T vertices might not have an edge from vertex 0.
//    priority[0]=0;  // Dummy entry for vertex 0
//    for (i=1;i<numVertices;i++)
//        priority[i]=oo;
//
//    // Initialize T-heap with edges from vertex 0.
//    for (i=firstEdge[0];
//        i!=(-1);
//        i=edgeTab[i].next)
//    {
//        priority[edgeTab[i].head]=edgeTab[i].weight;
//        bestSneighbor[edgeTab[i].head]=0;
//    }
//
//    // Constructor does BuildMinHeap
//    minHeap heap(numVertices,priority,numVertices);
//    free(priority);
//
//    // Remove dummy entry from heap
//    smallest=heap.extractMin();
//    if (smallest.id!=0)
//    {
//        cout << "Heap problem " << __LINE__ << "\n";
//        exit(0);
//    }
//
//    // Each iteration finds another MST edge
//    for (MSTedgeCount=0;MSTedgeCount<numVertices-1;MSTedgeCount++)
//    {
//        // Get minimum weight edge from S to T.
//        smallest=heap.extractMin();
//        if (smallest.priority==oo) // no edges remain that bridge S & T
//            break;
//
//        MSTweight+=smallest.priority;
//        cout << "Include edge from " << bestSneighbor[smallest.id] <<
//            " to " << smallest.id << " of weight " << smallest.priority << "\n";
//        flag[smallest.id]=s;
//
//        // Scan adjacency list looking for improvements
//        for (j=firstEdge[smallest.id];
//            j!=(-1);
//            j=edgeTab[j].next)
//            if (flag[edgeTab[j].head]==t
//                && edgeTab[j].weight<heap.getPriority(edgeTab[j].head))
//            {
//                changing.id=edgeTab[j].head;
//                changing.priority=edgeTab[j].weight;
//                heap.changePriority(changing);
//                bestSneighbor[edgeTab[j].head]=smallest.id;
//            }
//    }
//    if (MSTedgeCount<numVertices-1)
//        cout << "Stopped after collecting " << MSTedgeCount << " edges of weight "
//        << MSTweight << "\n";
//    else
//        cout << "Found MST with weight " << MSTweight << "\n";
//    free(flag);
//    free(bestSneighbor);
//}
//
//int main()
//{
//    int i,j;
//    //float startCPU,stopCPU;
//
//    read_input_file();
//    //startCPU=CPUtime();
//    clock_t begin = clock();
//    prim();
//    clock_t end = clock();
//    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//    cout << "\nElapsed milliseconds for prim's algorithm: " <<  elapsed_secs * 1000 << "ms" << endl;   
//    //stopCPU=CPUtime();
//    //cout << "Heap-based Prim's time " << stopCPU-startCPU << "\n";
//    free(edgeTab);
//    free(firstEdge);
//}
