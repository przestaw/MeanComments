//
// Created by przemek on 13.12.2019.
//

#include "Generator.h"

Generator::Generator(std::initializer_list<string> names_list) : randomEngine(std::random_device{}()) {
    if (names_list.size() > 2) {
        names = names_list;
    } else {
        throw std::length_error("Too few names one the list");
    }
}

vector<string> Generator::gen_user_groups(uint64_t count) {
    uint64_t c_mul = count / names.size();
    vector<string> tempNames;

    for (uint64_t i = 0; i <= c_mul; ++i) {
        for (string &iter : names) {
            tempNames.push_back(iter + std::to_string(i));
        }
    }
    std::shuffle(tempNames.begin(), tempNames.end(), randomEngine);

    tempNames.resize(count);
    return tempNames;
}

vector<string> Generator::write_comments(uint64_t no_of_comm, vector<string> &users, uint64_t l_count) {
    vector<string> buffer;
    uint64_t seed,
            count = users.size(),
            r_count;
    if (l_count >= count) {
        return buffer;
    } else {
        r_count = count - l_count;
    }

    for (uint64_t i = 0; i < no_of_comm; ++i) {
        seed = randomEngine() % count;
        if (seed < l_count) {
            buffer.push_back(
                    '#' + users[seed] + ": @"
                    + users[l_count + (randomEngine() % r_count)]
                    + " <Wredny Komentarz>\n");
        } else {
            buffer.push_back(
                    '#' + users[seed] + ": @"
                    + users[randomEngine() % l_count]
                    + " <Wredny Komentarz>\n");
        }
    }
    return buffer;
}

vector<string> Generator::write_fair_comments(uint64_t no_of_comm, vector<string> &users, uint64_t l_count) {
    vector<string> buffer;
    uint64_t seed,
            count = users.size(),
            r_count;
    if (l_count >= count) {
        return buffer;
    } else {
        r_count = count - l_count;
    }

    for (uint64_t i = 0; i < no_of_comm; ++i) {
        seed = randomEngine() % count;
        if (seed < l_count) {
            buffer.push_back(
                    '#' + users[seed]
                    + ": @" + users[randomEngine() % l_count]
                    + " <Wredny Komentarz>\n");
        } else {
            buffer.push_back(
                    '#' + users[seed]
                    + ": @" + users[l_count + randomEngine() % r_count]
                    + " <Wredny Komentarz>\n");
        }
    }

    return buffer;
}

vector<string>
Generator::generate_instance(bool fair, uint64_t users_count, uint64_t l_group_count, uint64_t comments_count) {
    vector<string> ret;
    vector<string> users = gen_user_groups(users_count);
    uint64_t fair_comments = 1 + comments_count / 25;

    if (fair) {
        vector<string> in_group = write_fair_comments(fair_comments, users, l_group_count);
        ret = write_comments(comments_count - fair_comments, users, l_group_count);

        std::for_each(in_group.begin(), in_group.end(), [&ret, this]
                (string &line) {
            //insert at random position
            ret.insert(ret.begin() + randomEngine() % ret.size(), line);
        });
    } else {
        //no need for shuffle
        ret = write_comments(comments_count, users, l_group_count);
    }

    return ret;
}

std::stringstream
Generator::generate_instance_output(bool fair, uint64_t users_count, uint64_t l_group_count, uint64_t comments_count) {
    std::stringstream ret;
    vector<string> instance = generate_instance(fair, users_count, l_group_count, comments_count);
    std::for_each(instance.begin(), instance.end(), [&ret]
            (string &line) { ret << line; });
    return ret;
}

std::stringstream Generator::generate_instance_output(vector<string> &problem_instance) {
    std::stringstream ret;
    std::for_each(problem_instance.begin(), problem_instance.end(), [&ret]
            (string &line) { ret << line; });
    return ret;
}