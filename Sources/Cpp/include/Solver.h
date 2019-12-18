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

class Solver {
private:
    struct Node {
        enum class Color {
            not_visited = 0, black = 1, white = -1
        };

        std::string name;

        explicit Node(uint64_t id);

        inline void add_adjacent(uint64_t node) {
            adjacent.push_back(node);
        }

        uint64_t id;
        Color node_color;
        std::vector<uint64_t> adjacent;
    };

public:
    //NOTE : time is added to time reference not assigned
    bool is_fair(std::vector<std::string> &problem_instance, uint64_t &time);

    bool is_fair(std::stringstream &problem_instance, uint64_t &time);

private:
    bool check_is_fair(uint64_t &time);

    inline bool check_nodes();

    inline void add_edge_by_names(std::string &name_one, std::string &name_two);
    void clear(); // clear for next instance

    std::vector<Node> nodes; // Node container, pointers to each cell are passed to fill adjacency lists
    std::map<std::string, uint64_t> node_names;
    std::list<uint64_t> unvisited_nodes; //NOTE: check if not already visited
};

#endif //AAL_SOLVER_H
