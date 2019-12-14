//
// Created by przemek on 13.12.2019.
//
#include <cstdio>
#include "Solver.h"

#include <boost/algorithm/string.hpp>

bool Solver::is_fair(std::stringstream &problem_instance, microseconds &time) {
    string line; // names
    vector<string> tokens;
    while (getline(problem_instance, line)) {
        std::cout << line << '\n';
        boost::split(tokens, line, boost::is_any_of(" :@#"), boost::token_compress_on);

        //std::cout << tokens[0] << '\n';
        std::cout << tokens[1] << '\n';
        std::cout << tokens[2] << '\n';
        //TODO: load
    }
    //TODO: run check
    return false;
}

bool Solver::is_fair(std::vector<string> &problem_instance, microseconds &time) {
    vector<string> tokens;
    for (string &line : problem_instance) {
        std::cout << line;
        boost::split(tokens, line, boost::is_any_of(" :@#"), boost::token_compress_on);

        //std::cout << tokens[0] << '\n';
        std::cout << tokens[1] << '\n';
        std::cout << tokens[2] << '\n';
        //TODO: load
    }
    //TODO: run check
    return false;
}

bool Solver::check_is_fair(microseconds &time) {
    boost::chrono::process_real_cpu_clock::time_point start, end;
    //czapeczka?
    Node *curr_node;

    start = boost::chrono::process_real_cpu_clock::now();
    while (!unvisited_nodes.empty()) {
        curr_node = unvisited_nodes.back();
        unvisited_nodes.pop_back();

        for (auto &it : curr_node->adjacent) {
            if (it->node_color == Node::Color::not_visited) {
                it->node_color =
                        (curr_node->node_color == Node::Color::black)
                        ? Node::Color::white : Node::Color::black;
                unvisited_nodes.push_front(it);
            } else if (it->node_color != curr_node->node_color) {
                it->node_color = curr_node->node_color;
            } else {
                end = boost::chrono::process_real_cpu_clock::now();
                time += boost::chrono::duration_cast<microseconds>(start - end);
                return true;
            }
        }
    }
    end = boost::chrono::process_real_cpu_clock::now();
    time += boost::chrono::duration_cast<microseconds>(start - end);
    this->clear();
    return false;
}

void Solver::clear() {
    nodes.clear();
    node_names.clear();
    unvisited_nodes.clear();
}

Solver::Node::Node(uint64_t id)
        : id(id), node_color(Color::not_visited) {}