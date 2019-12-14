//
// Created by przemek on 13.12.2019.
//

#ifndef AAL_SOLVER_H
#define AAL_SOLVER_H

#include <iosfwd>
#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <boost/chrono.hpp>

using std::string;
using std::vector;
using std::list;
using std::map;
using boost::chrono::microseconds;

class Solver {
private:
    struct Node {
        enum class Color {
            not_visited = 0, black = 1, white = -1
        };

        Node(uint64_t id);

        inline void add_adjacent(Node *node) {
            adjacent.push_back(node);
        }

        uint64_t id;
        Color node_color;
        vector<Node *> adjacent;
    };

public:
    //NOTE : time is added to time reference not assigned
    bool is_fair(vector<string> &problem_instance, microseconds &time);

    bool is_fair(std::stringstream &problem_instance, microseconds &time);

private:
    bool check_is_fair(microseconds &time);

    void clear(); // clear for next instance

    vector<Node> nodes; // Node container, pointers to each cell are passed to fill adjacency lists
    map<string, uint64_t> node_names;
    list<Node *> unvisited_nodes; //NOTE: check if not already visited


};


#endif //AAL_SOLVER_H
