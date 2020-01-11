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
#include "GraphContainer.h"

/**
 * class created to solve problem instances
 */
class Solver {
public:
    /**
     * loads problem instance to the object and runs check
     * @param problem_instance problem instance as a vector of lines
     * @param time reference to which time elapsed will be added
     * @return result : if account is fair
     */
    //bool is_fair(std::vector<std::string> &problem_instance, uint64_t &time);

    /**
     * loads problem instance to the object and runs check
     * @param problem_instance problem instance as a stream containing lines
     * @param time reference to which time elapsed will be added
     * @return result : if account is fair
     */
    //bool is_fair(std::stringstream &problem_instance, uint64_t &time);

    bool is_fair(GraphContainer &problem, uint64_t &time);
private:
    /**
     * internal method containing algorithm
     * @param time reference to witch time of computing will be added
     * @return result : if account is fair
     */
    //bool check_is_fair(uint64_t &time);

    /**
     * Clears graph after running algorithm to prepare it for next instance
     */
    inline void clear();

    std::list<uint64_t> unvisited_nodes; //!< contains queue of unvisited nodes
};

#endif //AAL_SOLVER_H
