//
// Created by przemek on 11.01.2020.
//

#include <boost/algorithm/string.hpp>
#include "GraphContainer.h"
#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::vector;
using std::list;
using std::map;
using boost::is_any_of;

using boost::split;
using Node = GraphContainer::Node;

GraphContainer::Node::Node(uint64_t id_c)
        : id(id_c), node_color(Color::not_visited) {}

GraphContainer::GraphContainer(std::stringstream &problem_instance) {
    string line;
    vector<string> tokens;
    while (getline(problem_instance, line)) {
        if (line.find('@') != std::string::npos) {
            split(tokens, line, is_any_of(" :@#"), boost::token_compress_on);
            add_edge_by_names(tokens[1], tokens[2]);
        }
    }
}

GraphContainer::GraphContainer(const std::vector<string> &problem_instance) {
    string name_one, name_two;
    vector<string> tokens;
    for (const string &line : problem_instance) {
        if (line.find('@') != std::string::npos) {
            split(tokens, line, is_any_of(" :@#"), boost::token_compress_on);
            add_edge_by_names(tokens[1], tokens[2]);
        }
    }
}

inline void GraphContainer::add_edge_by_names(string &name_one, string &name_two) {
    uint64_t node_one, node_two;
    if (node_names.find(name_one) == node_names.end()) {
        node_one = nodes.size();
        nodes.emplace_back(node_one);
        node_names.emplace(name_one, node_one);
    } else {
        node_one = node_names[name_one];
    }

    if (node_names.find(name_two) == node_names.end()) {
        node_two = nodes.size();
        nodes.emplace_back(node_two);
        node_names.emplace(name_two, node_two);
    } else {
        node_two = node_names[name_two];
    }

    if (std::count(nodes[node_one].adjacent.begin(), nodes[node_one].adjacent.end(), node_two) == 0 &&
        node_one != node_two) {
        nodes[node_one].add_adjacent(node_two);
        nodes[node_two].add_adjacent(node_one);
    } // this is symmetrical, if there is no such "edge" we add it
}

vector<Node> GraphContainer::getNodes() {
    return vector<Node>(nodes);
}
