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
    if (v == pi[v]) {
        return v;
    }
    pi[v] = find(pi.at(v), pi);
    return pi[v];
}

/*
 * union_by_rank
 */
void union_by_rank(int u, int v, vector<int> &rank, vector<int> &pi) {
    int vParent = find(pi[v], pi);
    int uParent = find(pi[u], pi);
    if (rank[vParent] <= rank[uParent]) {
        pi[vParent] = uParent;
        vParent++;
    } else {
        pi[uParent] = vParent;
        uParent++;
    }
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
        Vertex u = edge.first;
        Vertex v = edge.second;
        if (find(u.label, pi) != find(v.label, pi)) {
            union_by_rank(u.label, v.label, rank, pi);
            mst.push_back(edge);
            u.mstNeighbors.push_back(v.label);
            for(int neighbor : u.mstNeighbors) {
                cout << neighbor << '\n';
            }
            v.mstNeighbors.push_back(u.label);
            for (int neighbor : v.mstNeighbors) {
                cout << neighbor << '\n';
            }

        }
    } //for

    return mst;
}