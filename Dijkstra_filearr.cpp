// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph
#define V 75
double total = 0;
double disMax = 0;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(double dist[], bool sptSet[])
{
  
    // Initialize min value
    double min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(double dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(double graph[V][V], int src)
{
    double dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // print the constructed distance array
//    printSolution(dist);
    for(int i=src;i<V;++i)
        total += dist[i];
}

int ArgPos(char* str, int argc, char** argv){
    int a;

    for(a = 1 ; a < argc ; a++) if (!strcmp(str, argv[a])){
        if(a == argc - 1){
            std::cout << "Argument missing for " << str << std::endl;
            exit(1);
        }

        return a;
    }

    return -1;
}

// driver program to test above function
int main(int argc, char** argv)
{
    int i;
    char* coordinate_file = new char[20];
    char* connect_file = new char[20];
    //strcpy(source_file, "source.txt");
    char* filename = new char[20];
    strcpy(filename, "");

    if((i = ArgPos((char*)"-coordinate_file", argc, argv)) > 0) strcpy(coordinate_file, argv[i + 1]);
    if((i = ArgPos((char*)"-connect_file", argc, argv)) > 0) strcpy(connect_file, argv[i + 1]);
    if((i = ArgPos((char*)"-save", argc, argv)) > 0) strcpy(filename, argv[i + 1]);

    fstream file(coordinate_file);
    fstream file1(connect_file);

    double x1,y1,x2,y2;
    int a,b;
    double array[V][V] = {0};
  
    if(file.is_open() && file1.is_open()){
        while(file >> x1 >> y1 >> x2 >> y2){
            double s = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
            if(s>disMax)
                disMax = s;
            file1 >> a >> b;
            array[a][b] = s;
            array[b][a] = s;
        }
    }
    else{
        cout << "file not open" << endl;
    }

    file.close();file1.close();
/*
    for(int i = 0;i<100;++i){
        for(int j=0;j<100;++j)
            cout << array[i][j] << " ";
        cout << endl;
    }
*/
    /* Let us create the example graph discussed above */
    /*
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
*/
    clock_t start, end;
    
    start = clock();

    for(int i=0;i<V;++i)
        dijkstra(array, 0);

    end = clock();

    double v = V;
    double average = total / (v*(v-1)/2);

    double duration = double(end - start) / double(CLOCKS_PER_SEC);

    ofstream output;
    output.open(filename, ios_base::app);

    output << V << ",";
//    output << "array" << ",";
    output << total << ",";
    output << average << endl;
//    cout << "max=" << disMax << endl;
//    output << duration << endl;

    output.close();

    return 0;
}
