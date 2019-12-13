//
// Created by przemek on 13.12.2019.
//

#include "Generator.h"

vector<string> Generator::names({NAMES__ALL});

vector<string> Generator::gen_user_groups(uint64_t count) {
    uint64_t c_mul = count / names.size();
    vector<string> tempNames;

    for (uint64_t i = 0; i <= c_mul; ++i) {
        for (string iter : names) {
            tempNames.push_back(iter + std::to_string(i));
        }
    }

    std::random_device rd;
    std::mt19937_64 randomEngine(rd());

    std::shuffle(tempNames.begin(), tempNames.end(), randomEngine);

    tempNames.resize(count);

    return tempNames;
}

std::stringstream Generator::write_comments(uint64_t no_of_comm, vector<string> &users, uint64_t l_count) {
    std::stringstream buffer;
    uint64_t seed,
            count = users.size(),
            r_count;
    if (l_count >= count) {
        return buffer;
    } else {
        r_count = count - l_count;
    }

    std::random_device rd;
    std::mt19937_64 randomEngine(rd());

    for (uint64_t i = 0; i < no_of_comm; ++i) {
        seed = randomEngine() % count;
        if (seed < l_count) {
            buffer << '#' << users[seed] << ": @" << users[l_count + randomEngine() % r_count]
                   << " <Wredny Komentarz>\n";
        } else {
            buffer << '#' << users[seed] << ": @" << users[randomEngine() % l_count] << " <Wredny Komentarz>\n";
        }
    }

    return buffer;
}

std::stringstream Generator::write_fair_comments(uint64_t no_of_comm, vector<string> &users, uint64_t l_count) {
    std::stringstream ret;
    //TODO : add fair comments
    return ret;
}

std::stringstream
Generator::generate_instance(bool fair, uint64_t users_count, uint64_t l_group_count, uint64_t comments_count) {
    std::stringstream ret;
    vector<string> users = gen_user_groups(users_count);
    uint64_t fair_comments = 1 + comments_count / 25;
    if (fair) {
        ret = write_comments(comments_count - fair_comments, users, l_group_count);
        ret << write_fair_comments(fair_comments, users, l_group_count).str();
    } else {
        ret = write_comments(comments_count, users, l_group_count);
    }
    return ret;
}


