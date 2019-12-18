//
// Created by przemek on 13.12.2019.
//
#include "Solver.h"
#include <boost/algorithm/string.hpp>

using std::string;
using std::vector;
using std::list;
using std::map;
using boost::chrono::microseconds;
using boost::chrono::milliseconds;

bool Solver::is_fair(std::stringstream &problem_instance, uint64_t &time) {
    string line;
    vector<string> tokens;
    while (getline(problem_instance, line)) {
        boost::split(tokens, line, boost::is_any_of(" :@#"), boost::token_compress_on);
        add_edge_by_names(tokens[1], tokens[2]);
    }
    return check_is_fair(time);
}

bool Solver::is_fair(std::vector<string> &problem_instance, uint64_t &time) {
    string name_one, name_two;
    vector<string> tokens;
    for (string &line : problem_instance) {
        boost::split(tokens, line, boost::is_any_of(" :@#"), boost::token_compress_on);
        add_edge_by_names(tokens[1], tokens[2]);
    }
    return check_is_fair(time);
}

inline void Solver::add_edge_by_names(string &name_one, string &name_two) {
    uint64_t node_one, node_two;
    if (node_names.find(name_one) == node_names.end()) {
        node_one = nodes.size();
        nodes.emplace_back(node_one);
        node_names.emplace(name_one, node_one);

        nodes[node_one].name = name_one;
    } else {
        node_one = node_names[name_one];
    }

    if (node_names.find(name_two) == node_names.end()) {
        node_two = nodes.size();
        nodes.emplace_back(node_two);
        node_names.emplace(name_two, node_two);

        nodes[node_two].name = name_two;
    } else {
        node_two = node_names[name_two];
    }

    if (std::count(nodes[node_one].adjacent.begin(), nodes[node_one].adjacent.end(), node_two) == 0 &&
        node_one != node_two) {
        nodes[node_one].add_adjacent(node_two);
        nodes[node_two].add_adjacent(node_one);
    } // this is symmetrical, if there is no such "edge" we add it
}

bool Solver::check_is_fair(uint64_t &time) {
    boost::chrono::high_resolution_clock::time_point start, end;
    Node *curr_node;
    nodes[0].node_color = Node::Color::black;
    unvisited_nodes.emplace_back(0);

    start = boost::chrono::high_resolution_clock::now();
    do {
        while (!unvisited_nodes.empty()) {
            curr_node = &nodes[unvisited_nodes.back()];
            unvisited_nodes.pop_back();

            for (uint64_t it_no : curr_node->adjacent) {
                Node *it = &nodes[it_no];
                if (it->node_color == Node::Color::not_visited) {
                    it->node_color =
                            (curr_node->node_color == Node::Color::black)
                            ? Node::Color::white : Node::Color::black;
                    unvisited_nodes.push_front(it_no);
                } else if (it->node_color == curr_node->node_color) {
                    end = boost::chrono::high_resolution_clock::now();
                    time += boost::chrono::duration_cast<milliseconds>(start - end).count();
                    this->clear();
                    return true;
                }
            }
        }
    } while (this->check_nodes());

    end = boost::chrono::high_resolution_clock::now();
    time += boost::chrono::duration_cast<milliseconds>(start - end).count();
    this->clear();
    return false;
}

inline bool Solver::check_nodes() {
    //auto new_end = std::remove_if(nodes.begin(), nodes.end(), [](Node &node){ return node.node_color != Node::Color::not_visited;});
    //nodes.erase(new_end, nodes.end());

    //NOTE: cannot erase since it will destroy indexes or pointers
    auto iter = std::find_if(nodes.begin(), nodes.end(),
                             [](Node &node) { return node.node_color == Node::Color::not_visited; });
    if (iter == nodes.end()) {
        return false;
    } else {
        (*iter).node_color = Node::Color::black;
        unvisited_nodes.emplace_back((*iter).id);
        return true;
    }
};

void Solver::clear() {
    nodes.clear();
    node_names.clear();
    unvisited_nodes.clear();
}

Solver::Node::Node(uint64_t id)
        : id(id), node_color(Color::not_visited) {
    node_color = Color::not_visited;
}