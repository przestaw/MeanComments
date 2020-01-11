//
// Created by przemek on 13.12.2019.
//
#include "Solver.h"
#include <boost/algorithm/string.hpp>
#include <GraphContainer.h>

using boost::chrono::microseconds;
using boost::chrono::milliseconds;
using Node = GraphContainer::Node;

bool Solver::is_fair(GraphContainer &problem, uint64_t &time) {
    boost::chrono::high_resolution_clock::time_point start, end;
    Node *curr_node;
    auto nodes = problem.getNodes();

    start = boost::chrono::high_resolution_clock::now();

    for (auto &iter : nodes) {
        if (iter.node_color == Node::Color::not_visited) {
            iter.node_color = Node::Color::black;
            unvisited_nodes.emplace_back(iter.id);
            while (!unvisited_nodes.empty()) {
                //pop node
                curr_node = &nodes[unvisited_nodes.back()];
                unvisited_nodes.pop_back();
                //iter on adj
                for (uint64_t it_no : curr_node->adjacent) {
                    //color if not visited
                    if (nodes[it_no].node_color == Node::Color::not_visited) {
                        nodes[it_no].node_color =
                                (curr_node->node_color == Node::Color::black)
                                ? Node::Color::white : Node::Color::black;

                        unvisited_nodes.push_front(it_no);
                    } else if (nodes[it_no].node_color == curr_node->node_color) {
                        end = boost::chrono::high_resolution_clock::now();
                        time += boost::chrono::duration_cast<microseconds>(end - start).count();
                        this->clear();
                        return true;
                    }
                }
            }
        }
    }

    end = boost::chrono::high_resolution_clock::now();
    time += boost::chrono::duration_cast<microseconds>(end - start).count();
    this->clear();
    return false;
}

void Solver::clear() {
    unvisited_nodes.clear();
}
