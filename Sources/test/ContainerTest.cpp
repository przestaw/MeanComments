//
// Created by przemek on 11.01.2020.
//

#include <boost/test/unit_test.hpp>
#include "GraphContainer.h"

BOOST_AUTO_TEST_SUITE(Container_Test_Suite)

    BOOST_AUTO_TEST_CASE(Container_vector_3Users5Comments) {
        std::vector<std::string> test_vec;

        test_vec.emplace_back("#Paskal0: @Gwido0 <Wredny Komentarz>");
        test_vec.emplace_back("#Paskal0: @Gwido0 <Wredny Komentarz>");
        test_vec.emplace_back("#Gwido0: @Paskal0 <Wredny Komentarz>");
        test_vec.emplace_back("#Gwido0: @Nika0 <Wredny Komentarz>");
        test_vec.emplace_back("#Gwido0: @Nika0 <Wredny Komentarz>");

        GraphContainer prob(test_vec);

        BOOST_CHECK_EQUAL(prob.getNodes().size(), 3);
    }

    BOOST_AUTO_TEST_CASE(Container_vector_5Users15Comments) {
        std::vector<std::string> test_vec;

        test_vec.emplace_back("#Paskal0: @Gwido0 <Wredny Komentarz>");
        test_vec.emplace_back("#Paskal0: @Gwido0 <Wredny Komentarz>");
        test_vec.emplace_back("#Boguchwał0: @Nika0 <Wredny Komentarz>");
        test_vec.emplace_back("#Emil0: @Boguchwał0 <Wredny Komentarz>");
        test_vec.emplace_back("#Nika0: @Boguchwał0 <Wredny Komentarz>");
        test_vec.emplace_back("#Gwido0: @Nika0 <Wredny Komentarz>");
        test_vec.emplace_back("#Paskal0: @Boguchwał0 <Wredny Komentarz>");
        test_vec.emplace_back("#Gwido0: @Nika0 <Wredny Komentarz>");
        test_vec.emplace_back("#Emil0: @Boguchwał0 <Wredny Komentarz>");
        test_vec.emplace_back("#Gwido0: @Nika0 <Wredny Komentarz>");
        test_vec.emplace_back("#Nika0: @Gwido0 <Wredny Komentarz>");
        test_vec.emplace_back("#Boguchwał0: @Emil0 <Wredny Komentarz>");
        test_vec.emplace_back("#Gwido0: @Emil0 <Wredny Komentarz>");
        test_vec.emplace_back("#Gwido0: @Paskal0 <Wredny Komentarz>");
        test_vec.emplace_back("#Boguchwał0: @Nika0 <Wredny Komentarz>");

        GraphContainer prob(test_vec);

        BOOST_CHECK_EQUAL(prob.getNodes().size(), 5);
    }


    BOOST_AUTO_TEST_CASE(Container_stringstream_3Users5Comments) {
        std::stringstream file;

        file << "#Paskal0: @Gwido0 <Wredny Komentarz>\n"
             << "#Paskal0: @Gwido0 <Wredny Komentarz>\n"
             << "#Gwido0: @Paskal0 <Wredny Komentarz>\n"
             << "#Gwido0: @Nika0 <Wredny Komentarz>\n"
             << "#Gwido0: @Nika0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(prob.getNodes().size(), 3);
    }

    BOOST_AUTO_TEST_CASE(Container_stringstream_5Users15Comments) {
        std::stringstream file;

        file << "#Paskal0: @Gwido0 <Wredny Komentarz>\n"
             << "#Paskal0: @Gwido0 <Wredny Komentarz>\n"
             << "#Boguchwał0: @Nika0 <Wredny Komentarz>\n"
             << "#Emil0: @Boguchwał0 <Wredny Komentarz>\n"
             << "#Nika0: @Boguchwał0 <Wredny Komentarz>\n"
             << "#Gwido0: @Nika0 <Wredny Komentarz>\n"
             << "#Paskal0: @Boguchwał0 <Wredny Komentarz>\n"
             << "#Gwido0: @Nika0 <Wredny Komentarz>\n"
             << "#Emil0: @Boguchwał0 <Wredny Komentarz>\n"
             << "#Gwido0: @Nika0 <Wredny Komentarz>\n"
             << "#Nika0: @Gwido0 <Wredny Komentarz>\n"
             << "#Boguchwał0: @Emil0 <Wredny Komentarz>\n"
             << "#Gwido0: @Emil0 <Wredny Komentarz>\n"
             << "#Gwido0: @Paskal0 <Wredny Komentarz>\n"
             << "#Boguchwał0: @Nika0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(prob.getNodes().size(), 5);
    }

BOOST_AUTO_TEST_SUITE_END()