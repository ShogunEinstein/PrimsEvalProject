#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <time.h>

#define SIZE 100
#define INFINITY 9999
using namespace std;

int main() {
    int n = SIZE;
    int temp = 0;
    int sparseAdjMat[SIZE][SIZE];
    int denseAdjMat[SIZE][SIZE];
    char filename1[88]; //*** Output filename1
    char filename2[88]; //*** Output filename2
    char filename3[88]; //*** Output filename3
    char filename4[88]; //*** Output filename4
    char filename5[88]; //*** Output filename5
    strcpy(filename1, "sparseAdjMat.txt");
    strcpy(filename2, "denseAdjMat.txt");
    strcpy(filename3, "sparseAdjList1.txt");
    strcpy(filename4, "denseAdjList.txt");
    strcpy(filename5, "sparseAdjList11.txt");
    ofstream FILE1(filename1); //*** ASCII output file
    ofstream FILE3(filename3); //*** ASCII output file
    ofstream FILE5(filename5); //*** ASCII output file
    // initialize random seed:
    srand (time(NULL));


    // initializing sparse adj matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sparseAdjMat[i][j] = INFINITY;
        }
    }

    // initializing dense adj matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            denseAdjMat[i][j] = INFINITY;
        }
    }


    //sparse adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(rand() % 2 == 1) {
                temp = rand() % SIZE + 1;
                sparseAdjMat[i][j] = temp;
                sparseAdjMat[j][i] = temp;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            FILE1 << sparseAdjMat[i][j] << endl;
            if(sparseAdjMat[i][j] != 9999) {
                count++;
                FILE3 << i+1 << endl << j+1 << endl << sparseAdjMat[i][j] << endl; // i+1: head, j+1: tail, sparseAdjMat[i][j]: weight
            }
        }
        //FILE1 << endl;
    }
    FILE1.close();
    FILE3 << "10000000";
    FILE3.close();
    FILE5 << count;
    FILE3.close();


    ofstream FILE2(filename2); //*** ASCII output file
    ofstream FILE4(filename4); //*** ASCII output file
    //dense adjaceny matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(rand() % 8 != 2) {
                temp = rand() % SIZE + 1;
                denseAdjMat[i][j] = temp;
                denseAdjMat[j][i] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            FILE2 << denseAdjMat[i][j] << endl;;
            if(denseAdjMat[i][j] != 9999) {
                FILE4 << i+1 << endl << j+1 << endl << denseAdjMat[i][j] << endl; // i+1: head, j+1: tail, denseAdjMat[i][j]: weight
            }
        }
        //FILE2 << endl;
    }
    FILE2.close();
    FILE4 << "10000000";
    FILE4.close();

    return 0;
}
