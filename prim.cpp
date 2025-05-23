/*
 * CSC-301
 * prim.cpp
 * Fall 2022
 *
 * Partner 1: Raj Jhanwar
 * Partner 2: Ben Sheeley
 * Date: 04/15/2025
 */

#include "prim.hpp"

using namespace std;

/* 
 *  getMin
 * ----------
 * Helper function to find the unvisited vertex with the minimum cost.
 * 
 * Parameters:
 * - cost: vector containing current minimum edge costs for each vertex.
 * - visited: vector indicating whether a vertex has been visited.
 *
 * Returns:
 * - Index of the vertex with the smallest cost that hasn't been visited.
 */

int getMin(vector<double> &cost, vector<bool> &visited) {
    int n = cost.size();
    int minimum = -1;
    double mincost = 1e9;

    // Iterate through all vertices
    for (int i = 0; i < n; i++) {
        // If the vertex is unvisited and has a lower cost, we update min
        if (mincost > cost[i] && !visited[i]) {
            mincost = cost[i];
            minimum = i;
        }
    }
    return minimum; // Returning the index of the vertex with minimum cost
}

/*
 *  isEmpty
 * ----------
 * Checks if all vertices have been visited.
 *
 * Parameters:
 * - visited: vector indicating visited status of each vertex.
 *
 * Returns:
 * - true if all vertices are visited; false otherwise.
 */

bool isEmpty(vector<bool> &visited) {
    // Return false if any vertex is still unvisited
    for (int i = 0; i < visited.size(); i++)
        if (visited[i] == false)
            return false;
    return true;
}

/*
 *  prim
 * ----------
 * Main function to compute the Minimum Spanning Tree (MST) using Prim's algorithm.
 *
 * Parameters:
 * - adjList: vector of Vertex structs representing the graph's adjacency list.
 * - adjMat: flattened 2D adjacency matrix representing edge weights between vertices.
 *
 * Returns:
 * - A vector of Edges that make up the MST.
 */

vector<Edge> prim(vector<Vertex> &adjList, vector<double> &adjMat) {
    // Initialize the empty MST.
    vector<Edge> mst;

    // For each vertex, we need a visited flag, a 'cost' for Prim's, and the
    // 'prev' values to track the MST. Store these in seperate vectors.
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<double> cost(n, numeric_limits<double>::infinity());
    vector<int> prev(n, -1);

    // Picking a random starting vertex with srand
    srand(time(0));
    int start_vertex = rand() % n; 
    cost[start_vertex] = 0;        

    int minNode;                    
    int nextNode;

    // Looping until all vertices are added to MST
    while(!isEmpty(visited)) {
        minNode = getMin(cost, visited); // picking the next vertex with minimum cost
        visited[minNode] = true; // marking the node visited

        // Looping over all vertices to update costs
        for(int i = 0; i < n; i++) {
            if (visited[i]) 
                continue;   
            // Converting the index in the 1D adjMat from 2D coordinates
            else {
                nextNode = (minNode * n) + i;

                // If this edge is cheaper, updating the 'cost' and 'prev'
                if (cost[i] > adjMat[nextNode]) {
                    cost[i] = adjMat[nextNode];
                    prev[i] = minNode;
                }
            }
        }
    }

    // Building our MST by converting 'prev' into actual edges
    for(int i = 0; i < n; i++) { 
        if (prev[i] == -1)
            continue;

        // Creating edge from prev[i] to 'i' with corresponding weight
        Edge new_edge(adjList[prev[i]], adjList[i], adjMat[(i * n) + prev[i]]);
        mst.push_back(new_edge);

        adjList[i].mstNeighbors.push_back(adjList[prev[i]].label);
        adjList[prev[i]].mstNeighbors.push_back(adjList[i].label);
    }

    return mst;
}
