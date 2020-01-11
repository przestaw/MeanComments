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
     * internal method containing algorithm
     * @param problem reference to a problem instance to be solved
     * @param time reference to witch time of computing will be added
     * @return result : if account is fair
     */
    bool is_fair(GraphContainer &problem, uint64_t &time);

private:
    /**
     * Clears graph after running algorithm to prepare it for next instance
     */
    inline void clear();

    std::list<uint64_t> unvisited_nodes; //!< contains queue of unvisited nodes
};

#endif //AAL_SOLVER_H
