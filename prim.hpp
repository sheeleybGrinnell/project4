/*
 * CSC-301
 * prim.hpp
 * Spring 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include "Vertex.hpp"
#include "Edge.hpp"

/*
 * getMin
 * -------------
 *
 * Description -
 *      Finds the index of the unvisited vertex with the minimum cost value.
 *      This is used in Prim's algorithm to select the next vertex to add to the MST.
 *
 * Parameters -
 *      cost: A vector of doubles representing the cost of reaching each vertex.
 *      visited: A vector of booleans indicating whether each vertex has been visited.
 *
 * Return Value -
 *      The index of the unvisited vertex with the lowest cost.
 *      Returns -1 if all vertices have been visited.
 */
int getMin(std::vector<double> &cost, std::vector<bool> &visited);

/*
 * isEmpty
 * ---------
 *
 * Description -
 *      Checks if all vertices in the graph have been visited.
 *      Used to determine the termination condition for Prim's algorithm.
 *
 * Parameters -
 *      visited: A vector of booleans indicating whether each vertex has been visited.
 *
 * Return Value -
 *      true if all vertices are visited, otherwise false.
 */
bool isEmpty(std::vector<bool> &visited);

/*
 * prim
 * ---------
 *
 * Description -
 *      Implements Prim's algorithm to generate a Minimum Spanning Tree (MST)
 *      from a given graph represented by an adjacency list and a flattened adjacency matrix.
 *
 * Parameters -
 *      adjList: A vector of Vertex objects representing the graph's vertices.
 *      adjMat: A flattened 2D adjacency matrix (1D vector) containing edge weights between vertices.
 *
 * Return Value -
 *      A vector of Edge objects representing the MST of the graph.
 */
std::vector<Edge> prim(std::vector<Vertex> &adjList, 
                       std::vector<double> &adjMat);

#endif  // PRIM_HPP_
