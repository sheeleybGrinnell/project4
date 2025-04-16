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

/*
 * tsp
 */
vector<int> tsp(vector<Vertex> &adjList, Vertex &start) {
    // Create the empty tour.
    vector<int> tour;
    vector<int> tempTour;
    // Create the vector for tracking visited during the DFS.
    int n = adjList.size();
    vector<bool> visited(n, false);

    stack<Vertex> s;
    s.push(start);
    while (!s.empty()) {
        // pop and top to remove and assign our curr
        Vertex curr = s.top();
        s.pop();
        if (visited[curr.label]) {
            continue;
        }
        visited[curr.label] = true;
        // add current to our tour
        tempTour.push_back(curr.label);
        for (int neighbor : adjList[curr.label].mstNeighbors) {
            if (!visited[neighbor]) {
                s.push(adjList[neighbor]);
            }
        }
    }
    vector<bool> repeated(n, false);
    for (int city : tempTour) {
        if (repeated[city]) {
            continue;
        } else {
            tour.push_back(city);
        }
    }
    tour.push_back(start.label);
    cout << tour.size() << '\n';
    for (int city: tour) {
        cout << city << " is a city we visit\n";
    }
    return tour;
}