/*
 * CSC-301
 * kruskal.cpp
 * Spring 2025
 *
 * Partner 1: Benjamin Sheeley
 * Partner 2: Raj Jhanwar
 * Date: 04/14/2025
 */

#include "kruskal.hpp"

using namespace std;

/*
 * find
 */
int find(int v, vector<int> &pi) {
    return -1;
}

/*
 * union_by_rank
 */
void union_by_rank(int u, int v, vector<int> &rank, vector<int> &pi) {
    return;
}

/*
 * kruskal
 */
vector<Edge> kruskal(vector<Vertex> &adjList, vector<Edge> &edgeList) {
    // Initialize the empty MST.
    vector<Edge> mst;
    
    // For each vertex, we need rank values and pi pointers (ints) for the
    // Disjoint Sets. Initialize the rank to 0 and pi to be the vertex labels.
    int n = adjList.size();
    vector<int> rank(n, 0);
    vector<int> pi(n);
    for (int i=0; i<pi.size(); i++) {
        pi[i] = i;
    }
    // loop through each edge in our sorted edgelist
    for (Edge edge : edgeList) {
        // if the rank of one of our vertices is 0, we know it does not have any parents
        if (rank[edge.first.label] == 0) {

        }
    }

    return mst;
}