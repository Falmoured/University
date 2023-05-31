#ifndef __SOLVE_H__
#define __SOLVE_H__
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

const int MAX_SIZE = 100;


namespace falmoured
{ 
    void dijkstra_algorithm(int start, std::vector<std::vector<int>>& graph, std::vector<int>& dist);
}
#endif