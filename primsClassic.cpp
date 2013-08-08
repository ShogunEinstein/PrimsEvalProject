////O(V^2) prim's algorithm
///////////////////////////
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <time.h>
//using namespace std;
//#define SIZE 350
//#define INFINITY 9999
//
//class prims {
//    int graph[SIZE][SIZE],nodes;
//public:
//    prims();
//    void createGraph();
//    void primsAlgo();
//};
//// constructor
//prims::prims() {
//    for(int i=0;i<SIZE;i++)
//        for(int j=0;j<SIZE;j++)
//            graph[i][j]=0;
//}
//// create graph function
//void prims::createGraph(){
//    int i,j,k=0;
//    string line;
//    ifstream myfile ("sparseAdjMat350.txt");
//    nodes = SIZE;
//    cout << "\nProcessing adjacency matrix...\n";
//    if (myfile.is_open()) {
//        for(i=0;i<nodes;i++)
//            for(j=0;j<nodes;j++) {
//                getline (myfile,line);
//                graph[i][j] = stoi(line);
//                if(k != nodes) {
//                    k++;
//                }
//                else {
//                    k = 1;
//                }
//            }
//            myfile.close();
//    }
//    else cout << "Unable to open file\n"; 
//    //Assign infinity to all graph[i][j] where weight is 0.
//    for(i = 0; i < nodes; i++){
//        for(j = 0; j < nodes; j++){
//            if(graph[i][j] == 0)
//                graph[i][j] = INFINITY;
//        }
//    }
//}
//// prims O(V^2) implementation 
//void prims::primsAlgo() {
//    int visited[SIZE]={0};
//    int i,j,a,b,u,v,min;
//    int mincost = 0;
//    int numEdges = 1;
//    visited[1]=1;
//    printf("\n");
//    while(numEdges < nodes) {
//        for(i=0,min=9999; i<nodes; i++)
//            for(j=0; j<nodes; j++)
//                if(graph[i][j] < min)
//                    if(visited[i] != 0) {
//                        min=graph[i][j];
//                        a=u=i;
//                        b=v=j;
//                    }
//                    if(visited[u]==0 || visited[v]==0) {
//                        cout << "\nEdge " << numEdges++ << ":(" << a+1 << ' ' << b+1 << ") cost:" << min;
//                        mincost+=min;
//                        visited[b]=1;
//                    }
//                    graph[a][b]=graph[b][a]=9999;
//    }
//    cout << "\nMinimun cost = " << mincost;
//}
//// main function
//void main() {
//    prims MST;
//    cout<<"\nPrim's Algorithm to find Minimum Spanning Tree\n";
//    MST.createGraph();
//    clock_t begin = clock();
//    MST.primsAlgo();
//    clock_t end = clock();
//    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//    cout << "\nElapsed milliseconds for prim's algorithm: " <<  elapsed_secs * 1000 << "ms" << endl;    
//    return;
//}