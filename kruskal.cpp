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

/**
 * find
 *      finds the parent vertex of any given vertex label
 *  @param v
 *      the label of the vertex we want to find the parent vertex of
 *  @param pi
 *      the vector which contains the information for the parent of each vertex
 *  @return
 *      the parent vertex of vertext labeled "v"
 */
int find(int v, vector<int> &pi) {
    if (v == pi[v]) {
        return v;
    }
    pi[v] = find(pi.at(v), pi);
    return pi[v];
}

/**
 * union_by_rank
 *      unions two disjoint sets together based on any vertex within those disjoint sets
 *  @param u
 *      the first disjoint vertex we want to union
 *  @param v
 *      the second disjoint vertex we want to union
 *  @param rank
 *      the vector of vertices which contain rank based on label
 *  @param pi
 *      the vector of verticies which contain parent vertex based on label
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

/**
 * kruskal
 *      creates an MST using kruskal's algorithm
 *      finds the smallest edge possible to add to an MST without creating cycles
 *      we avoid creating cycles through use of disjoint sets (see find and union_by_rankmake)
 *  @param adjList
 *      an adjacency list which helps represent our "forest" or collection of vertices
 *  @param edgeList
 *      a sorted list of edges
 *  @return
 *      a minimum-spanning-tree containing the shortest path to each vertex
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
    // loop through each edge in our sorted edgelist so we can add by priority
    for (Edge edge : edgeList) {
        // look at the two vertices of our potential edge
        Vertex u = edge.first;
        Vertex v = edge.second;
        // if both vertices are in the same set then it creates a cycle, so we should move on without this cycle
        if (find(u.label, pi) != find(v.label, pi)) {
            // union the two disjoint sets each vertex populates
            union_by_rank(u.label, v.label, rank, pi);
            mst.push_back(edge);
            // add both vertices to each others' neighbors list for the MST
            adjList[u.label].mstNeighbors.push_back(v.label);
            adjList[v.label].mstNeighbors.push_back(u.label);
            // debug to find missing MST neighbors(?)
            // cout << "u info\n";
            // cout << u.printVertex() << "\n";
            // cout << "v info\n";
            // cout << v.printVertex() << "\n";
        } //if
    } //for

    return mst;
}