//
// Created by przemek on 11.01.2020.
//

#ifndef AAL_GRAPHCONTAINER_H
#define AAL_GRAPHCONTAINER_H

#include <cstdint>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <vector>

class GraphContainer {
public:
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

    GraphContainer(const std::vector<std::string> &problem_instance);

    GraphContainer(std::stringstream &problem_instance);

    std::vector<Node> getNodes();

private:
    /**
     * Internal method for adding edges to the graph
     * @param name_one one name
     * @param name_two second name
     */
    inline void add_edge_by_names(std::string &name_one, std::string &name_two);

    std::vector<Node> nodes; //!< Node container, pointers to each cell are passed to fill adjacency lists
    std::map<std::string, uint64_t> node_names; //!< Map used to determine which id to give to a certain Node
};


#endif //AAL_GRAPHCONTAINER_H
