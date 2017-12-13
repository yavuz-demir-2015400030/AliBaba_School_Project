//
// Created by Yavuz on 10/12/2017.
//

//
// Created by Yavuz on 10/12/2017.
//

#include "MiddleEarth.h"
#include <iostream>
#include <queue>

#include "AliBaba.h"


MiddleEarth::MiddleEarth(int V, int T, int R)
{
    this->R = R;
    this->T = T;
    this->V = V;
    adj = new list<iPair>[V];
    jewelers = new list<int>[V];
    thieves = new list<iPair>[V];
    visited = new list<int>[V];

}



void MiddleEarth::addJewels(int t, int c) {

    jewelers[t].push_back(c);

}

void MiddleEarth::addThief(int t_1, int t_2, int t) {
    thieves[t_1].push_back(make_pair(t_2, t));
    thieves[t_2].push_back(make_pair(t_1, t));
}

void MiddleEarth::addUndirectedEdge(int u, int v, int w)
{

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}


string MiddleEarth::shortestPath(int start_node)
{
    priority_queue< AliBaba > pq;
    // initialize start_node
    AliBaba temp(0,0);

    string final;

    pq.push(temp);

    bool isFinised = false;

    while (!pq.empty())
    {

        AliBaba temp = pq.top();

        pq.pop();





        list<int>::iterator citr;
        for (citr = jewelers[temp.loc].begin(); citr != jewelers[temp.loc].end(); ++citr) {

            temp.coins[*citr] = 1;
        }
        int visitor = 0;
        for(int i=0; i< T; i++){
            if(temp.coins[i] == 1) {
                visitor += pow(2, i);
            }
        }



        visited[temp.loc].push_back(visitor);






        if(temp.loc == V-1) {

            for(int i =0; i<temp.path.size(); i++){
                final += to_string(temp.path[i] + 1) ;
                final += " ";
            }
            final += to_string(temp.loc +1);
            isFinised = true;
            break;
        }



        list< iPair >::iterator itr;
        for (itr = adj[temp.loc].begin(); itr != adj[temp.loc].end(); ++itr)
        {

            int curr_neighbor = (*itr).first;
            int curr_weight = (*itr).second;




            bool isValid = true;


            list<iPair>::iterator titr;
            for(titr = thieves[temp.loc].begin(); titr != thieves[temp.loc].end(); ++titr ){
                int locx = (*titr).first;
                int coinx = (*titr).second;
                if(locx == curr_neighbor){
                    if(temp.coins[coinx] == 0){
                        isValid = false;
                        break;
                    }
                }
            }

            bool isVisited = false;



            list<int>::iterator vitr;
            for(vitr = visited[curr_neighbor].begin(); vitr!= visited[curr_neighbor].end(); ++vitr){
                int x = (*vitr);
                if(x == visitor){

                    isVisited = true;
                    break;
                }
            }




            if (isValid && !isVisited)
            {

                AliBaba temp_child(curr_neighbor, temp.dist + curr_weight);
                for(int m=0; m<T; m++){
                    temp_child.coins[m] = temp.coins[m];
                }


                temp_child.path = temp.path;
                temp_child.path.push_back(temp.loc);


                pq.push(temp_child);
            }

        }
    }

    if(!isFinised){
        final = to_string(-1) ;
    }
    return final;

}