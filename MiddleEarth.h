
#include<list>
using namespace std;

#include <cmath>
#include <vector>

typedef pair<int, int> iPair;


class MiddleEarth {



public:
    int V;          // number of vertices
    list<iPair> *adj; // adjacency list

    int T;
    list<int> *jewelers;

    int R;
    list<iPair> *thieves;



    list<int> *visited;








    MiddleEarth(int V, int T, int R);   // constructor
    void addJewels(int t, int c);
    void addThief(int t_1, int t_2, int t);
    void addUndirectedEdge(int u, int v, int w=0);     // add an undirected edge to graph
    void shortestPath(int);
};





