#include <iostream>
#include <fstream>
#include "MiddleEarth.h"

using namespace std;

int main() {

//    if (argc != 3) {
//        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
//        return 1;
//    }
//
//    cout << "input file: " << argv[1] << endl;
//    cout << "output file: " << argv[2] << endl;
//
//    ifstream input(argv[1]);
//
//    ofstream output;
//    output.open(argv[2]);
//
    ifstream input("C:\\Users\\Yavuz\\CLionProjects\\project3-yavuz-demir-2015400030-master\\input");


    int numOfTowns, numOfRoads, numOfThieves, numOfJewelers;

    input>> numOfTowns >> numOfRoads >> numOfThieves >> numOfJewelers;

    MiddleEarth myEarth(numOfTowns, numOfThieves, numOfRoads);


    for(int i=0; i<numOfJewelers; i++){
        int a, b;
        input>> a >> b;

        for(int j=0; j<b; j++){
            int x;
            input>> x;

            myEarth.addJewels(a-1, x-1);
        }

    }



    for(int i=0; i<numOfRoads; i++) {
        int a, b, c, d;
        input>> a >> b>> c >> d;
        myEarth.addUndirectedEdge(a-1, b-1, c);
        for(int j=0; j<d; j++){
            int x;
            input>>x;
            myEarth.addThief(a-1, b-1, x-1);
        }


    }

    myEarth.shortestPath(0);






    return 0;
}