/*
AUTHOR: Michael White
STID:  107
DATE: 10/25/2020
CLASS: CS315-002 Fall 2020
PROJECT: pa1-107.cc - the program name followed with the last three digits of your SID#
COMPILATION: g++ pa1-107.cc -o pa1
SYNOPSIS: ./pa1 < input.txt
COMPUTER: VM allocated by the CS department
ALGORITHM: The primary algorithm is BFS which is ran in the inputed adjacency list
COMPLEXITY: O(V+E) with the worst case being all nodes are connected at distance less than 2 and all nodes are connected
BUGS: Issues with comments showing on course comment checker
REFERENCES: The BFS was adapted from my notes taken from our in class demonstration on 10/15/20
NOTES: I'm not sure how my input method would behave if a vertex had no connections
*/
#include <iostream> // used for input and output
#include <sstream> // used to parse each line of input
#include <vector> // used for convience to build adjacency list 
#include <queue> // needed to preform BFS on the graph
using namespace std; 

int main(){
    // input variables
    int vertecies, edges, start;
    cin >> vertecies >> edges >> start; // starting input
    vector<vector<int>> g; // will store out graph
    vector<int> visited;
    string line = "";
    // keep taking input from stdin until there is no more
    while(getline(cin, line)){
        if(line.length() > 0){
            vector<int> row;
            // use string stream to seperate each line of input at the spaces
            istringstream iss(line);
            for(string s; iss >> s;){
                row.push_back(stoi(s)); // add each vertex to connection list
            }
            visited.push_back(0);
            g.push_back(row); // add each row to the graph
        }
    }

    // preform bfs
    int num_neighbors = 0, min_neighbors = 1001, max_neighbors = 0, distance = 2;
    queue<pair<int,int>> q;
    q.push({start,0}); // add the start node to the queue
    visited.at(start) = 1; // mark the start node as visited
    pair<int,int> f; // pair to store the value of a node and its distance from start
    while(!q.empty()){
        f=q.front();
        q.pop();
        int curr_neighbor = 0;
        for(int i = 0; i < g.at(f.first).size(); i++){
            curr_neighbor++;
            // only check unvisited nodes within the distance
            if(visited.at(g.at(f.first).at(i)) == 0 && f.second < distance){
                visited.at(g.at(f.first).at(i)) = 1; // mark the node as visited 
                num_neighbors++;
                q.push({g.at(f.first).at(i), f.second+1}); // add node to the queue
            }
        }
        // recalculate min and max neighbors
        min_neighbors = min(min_neighbors, curr_neighbor);
        max_neighbors = max(max_neighbors, curr_neighbor);        
    }
    // display results to stdout
    cout << num_neighbors << endl << min_neighbors << " " << max_neighbors << endl;
    return 0;
}
