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

/**
 * class created to solve problem instances
 */
class Solver {
private:
    /**
     * struct describing one Node - user in the graph where: edge - comment
     */
    struct Node {
        /**
         * This is enum determines if the node was visited or is in one of the visited groups
         */
        enum class Color {
            not_visited = 0, //!< Node was not visited
            black = 1,       //!< Node is in "black" group
            white = -1       //!< Node is in "white" group
        };

        /**
         * Constructor creates a Node with identifying id
         * @param id
         */
        explicit Node(uint64_t id);

        /**
         * Helper method to add edge to a node
         * @param node adjacent node
         */
        inline void add_adjacent(uint64_t node) {
            adjacent.push_back(node);
        }

        uint64_t id; //!< identifying id
        Color node_color; //!< determines if the node was visited or is in one of the visited groups
        std::vector<uint64_t> adjacent; //!< adjacent nodes - describes edges
    };

public:
    /**
     * loads problem instance to the object and runs check
     * @param problem_instance problem instance as a vector of lines
     * @param time reference to which time elapsed will be added
     * @return result : if account is fair
     */
    bool is_fair(std::vector<std::string> &problem_instance, uint64_t &time);

    /**
     * loads problem instance to the object and runs check
     * @param problem_instance problem instance as a stream containing lines
     * @param time reference to which time elapsed will be added
     * @return result : if account is fair
     */
    bool is_fair(std::stringstream &problem_instance, uint64_t &time);

private:
    /**
     * internal method containing algorithm
     * @param time reference to witch time of computing will be added
     * @return result : if account is fair
     */
    bool check_is_fair(uint64_t &time);

    /**
     * Internal method for adding edges to the graph
     * @param name_one one name
     * @param name_two second name
     */
    inline void add_edge_by_names(std::string &name_one, std::string &name_two);

    /**
     * Clears graph after running algorithm to prepare it for next instance
     */
    void clear();

    std::vector<Node> nodes; //!< Node container, pointers to each cell are passed to fill adjacency lists
    std::map<std::string, uint64_t> node_names; //!< Map used to determine which id to give to a certain Node
    std::list<uint64_t> unvisited_nodes; //!< contains queue of unvisited nodes
};

#endif //AAL_SOLVER_H
