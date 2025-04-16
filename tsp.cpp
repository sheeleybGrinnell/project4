/*
 * CSC-301
 * tsp.cpp
 * Spring 2025
 *
 * Partner 1: Benjamin Sheeley
 * Partner 2: Raj Jhanwar
 * Date: 04/15/2025
 */

#include "tsp.hpp"

using namespace std;

/**
 * tsp
 *  Creates a tour of a complete graph using MST algorithms and DFS
 *  This solves the traveling salesman problem
 *  @param adjList
 *      The adjacency list that contians our vertices and their neighbors
 *  @param start
 *      A vertex which we start our DFS on. It will be visited once at the beginning of our tour and once at the end
 *  @return
 *      a vector of in-order ints which correspond to the vertices on our tour
 */
vector<int> tsp(vector<Vertex> &adjList, Vertex &start) {
    // Create the empty tour.
    vector<int> tour;
    vector<int> tempTour;
    // Create the vector for tracking visited during the DFS.
    int n = adjList.size();
    vector<bool> visited(n, false);
    // Create the stack that we will loop over for our DFS algorithm
    stack<Vertex> s;
    s.push(start);
    // Loop until we have visited every vertex
    while (!s.empty()) {
        // pop and top to remove and assign our curr
        Vertex curr = s.top();
        s.pop();
        // If we have seen this city before skip over it
        if (visited[curr.label]) {
            continue;
        } //if
        visited[curr.label] = true;
        // add current to our tour
        tempTour.push_back(curr.label);
        // Add neighbors so we can visit them later
        for (int neighbor : adjList[curr.label].mstNeighbors) {
            if (!visited[neighbor]) {
                s.push(adjList[neighbor]);
            } //if
        } //for
    } //while
    // Create a vector that tracks any repeated cities in our initial tour
    vector<bool> repeated(n, false);
    // Loop through our initial tour getting rid of any repeated cities
    for (int city : tempTour) {
        if (repeated[city]) {
            continue;
        } else {
            tour.push_back(city);
        } //if/else
    } //for
    // Add our final starting city to make a complete tour
    tour.push_back(start.label);
    return tour;
} //tsp(Vector<Vertex>, Vertex)