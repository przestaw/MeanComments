//
// Created by przemek on 13.12.2019.
//

#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H

#include <initializer_list>
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <algorithm>

#define NAMES__ALL {"Ada", "Adamina", "Adela", "Adelajda", "Adriana", "Adrianna", "Agata", "Agnieszka", "Aida", "Alberta", "Albertyna", "Albina", "Aldona", "Aleksa", "Aleksandra", "Aleksja", "Alfreda", "Alicja", "Alina", "Alojza", "Amalia"}
using std::string;
using std::vector;

/**
 * Generator class for problem instances generation
 */
class Generator {
public:
    /**
     * Constructor for the generator. Wraps random number generator and basic list of names for login creation. Stateless excluding RNG state.
     * @param seed seed for the random engine
     * @param names_list list of names to be used, default is list of polish names from wikipedia.org
     */
    Generator(uint64_t seed, std::initializer_list<string> names_list = NAMES__ALL);

    /**
     * Constructor for the generator. Wraps random number generator and basic list of names for login creation. Stateless excluding RNG state.
     * @param names_list list of names to be used, default is list of polish names from wikipedia.org
     */
    Generator(std::initializer_list<string> names_list = NAMES__ALL);

    /**
     * Generates problem instance according to parameters as a stream
     * @param fair determine if account should be fair or not
     * @param users_count count of all users
     * @param l_group_count count of one of the "groups" commenting
     * @param comments_count number of comments
     * @return problem instance in a stream
     */
    std::stringstream
    generate_instance_output(bool fair, uint64_t users_count, uint64_t l_group_count, uint64_t comments_count);

    /**
     * Creates printable stream from a vector of lines
     * @param problem_instance problem instance
     * @return problem instance in a stream
     */
    std::stringstream generate_instance_output(vector<string> &problem_instance);

    /**
     * Generates problem instance according to parameters as a vector of lines
     * @param fair determine if account should be fair or not
     * @param users_count count of all users
     * @param l_group_count count of one of the "groups" commenting
     * @param comments_count number of comments
     * @return problem instance in a vector
     */
    vector<string> generate_instance(bool fair, uint64_t users_count, uint64_t l_group_count, uint64_t comments_count);

    /**
     * Takes use of class RNG
     * @return random unsigned integer
     */
    inline uint64_t random_unsigned();

private:
    /**
     * Internal method for generating random group of users
     * @param count number of users
     * @return vector of user names
     */
    inline vector<string> gen_user_groups(uint64_t count);

    /**
     * Writes comments between the groups
     * @param no_of_comm number of comments to be written
     * @param users vector of user names
     * @param l_count count count of one of the "groups" commenting
     * @return vector of comments
     */
    inline vector<string> write_comments(uint64_t no_of_comm, vector<string> &users, uint64_t l_count);

    /**
     * Writes comments in the groups
     * @param no_of_comm number of comments to be written
     * @param users vector of user names
     * @param l_count count count of one of the "groups" commenting
     * @return vector of comments
     */
    inline vector<string> write_fair_comments(uint64_t no_of_comm, vector<string> &users, uint64_t l_count);

    /**
     * vector holding basic set of names for problem generation
     */
    vector<string> names;

    /**
     * Random number generator used as entropy source for comments and user creation
     */
    std::mt19937_64 randomEngine;
};


#endif //AAL_GENERATOR_H
