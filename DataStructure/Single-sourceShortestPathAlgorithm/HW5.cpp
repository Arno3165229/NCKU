#include "Dijkstras.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream file_r; // declare an input object(.txt)
    int number;
    file_r.open("input.txt"); // input file name
    file_r >> number;

    cout<< endl<< "vertex數目: "<< number<< endl<< endl;

    int **graph;
    graph = new int* [number];
    for(int i = 0 ; i < number ; i++){
        graph[i] = new int [number];
    }

    for(int i = 0; i < number; i++){
        for(int j = 0; j < number; j++){
            file_r >> graph[i][j];   // read the key
        }
    }

    cout<< "adjacency matrix: "<< endl;
    for(int i =0; i<number ; i++){
        for(int j = 0; j<number; j++){
            cout<< std ::left<< setw(4) << graph[i][j]<< " ";
        }
        cout<< endl;
    }

    Graph_SP gg(number);
    
    for(int i = 0; i<number; i++){
        for(int j = 0; j<number; j++){
            if(graph[i][j] >= 0){
                gg.AddEdge(i,j,graph[i][j]);
            }
        }
    }

    gg.Dijkstra(0);

    for (int i=0; i<number; i++){
         delete [] graph[i];
     }
     delete [] graph; 


   // Graph_SP g9(6);
   // g9.AddEdge(0, 1, 8);g9.AddEdge(0, 5, 1);
   // g9.AddEdge(1, 0, 3);g9.AddEdge(1, 2, 1);
   // g9.AddEdge(2, 0, 5);g9.AddEdge(2, 3, 2);g9.AddEdge(2, 4, 2);
   // g9.AddEdge(3, 1, 4);g9.AddEdge(3, 2, 6);g9.AddEdge(3, 4, 7);g9.AddEdge(3, 5, 3);
   // g9.AddEdge(5, 3, 2);g9.AddEdge(5, 4, 8);

   // g9.Dijkstra(0);

    return 0;
}