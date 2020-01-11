//
// Created by przemek on 11.01.2020.
//
#include <boost/test/unit_test.hpp>
#include "Solver.h"

BOOST_AUTO_TEST_SUITE(Solver_Test_Suite)

    BOOST_AUTO_TEST_CASE(Solver_GivenExample_True) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Jan: Piekne zdjecie.\n"
             << "#Ola: @Jan Masz racje.\n"
             << "#Ania: @Ola Nie ma racji!\n"
             << "#Jan: @Ania własnie, ze mam!\n"
             << "#Ola: @Ania sama nie masz!\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(true, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_GivenExample_False) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Jan: Piekne zdjecie.\n"
             << "#Ola: @Jan Nieprawda.\n"
             << "#Jan: @Ola czemu tak twierdzisz?\n"
             << "#Ania: @Ola no wlasnie?\n"
             << "#Tomek: @Ania twierdzi tak, bo ma racje!!!\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(false, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_Test_Comment1) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Ilza0: @Odon0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(false, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_Test_Cycle2) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Ilza0: @Odon0 <Wredny Komentarz>\n"
             << "#Odon0: @Ilza0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(false, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_Test_Cycle3) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Ilza0: @Odon0 <Wredny Komentarz>\n"
             << "#Świętopełk0: @Odon0 <Wredny Komentarz>\n"
             << "#Świętopełk0: @Ilza0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(true, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_Test_Cycle4) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Ilza0: @Odon0 <Wredny Komentarz>\n"
             << "#Świętopełk0: @Odon0 <Wredny Komentarz>\n"
             << "#Świętopełk0: @Anzelm0 <Wredny Komentarz>\n"
             << "#Anzelm0: @Ilza0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(false, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_SmallExample_Cycle5) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Ilza0: @Odon0 <Wredny Komentarz>\n"
             << "#Świętopełk0: @Odon0 <Wredny Komentarz>\n"
             << "#Świętopełk0: @Anzelm0 <Wredny Komentarz>\n"
             << "#Anzelm0: @Polmira0 <Wredny Komentarz>\n"
             << "#Polmira0: @Ilza0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(true, test_solver.is_fair(prob, time));
    }


    BOOST_AUTO_TEST_CASE(Solver_SmallExample_False_1) {
        Solver test_solver;
        uint64_t time;
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

        BOOST_CHECK_EQUAL(false, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_SmallExample_False_2) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Kiara0: @Marlena0 <Wredny Komentarz>\n"
             << "#Marlena0: @Narcyz0 <Wredny Komentarz>\n"
             << "#Michał0: @Marlena0 <Wredny Komentarz>\n"
             << "#Michał0: @Franciszek0 <Wredny Komentarz>\n"
             << "#Franciszek0: @Michał0 <Wredny Komentarz>\n"
             << "#Marlena0: @Kiara0 <Wredny Komentarz>\n"
             << "#Narcyz0: @Marlena0 <Wredny Komentarz>\n"
             << "#Michał0: @Franciszek0 <Wredny Komentarz>\n"
             << "#Kiara0: @Franciszek0 <Wredny Komentarz>\n"
             << "#Marlena0: @Narcyz0 <Wredny Komentarz>\n"
             << "#Narcyz0: @Marlena0 <Wredny Komentarz>\n"
             << "#Narcyz0: @Franciszek0 <Wredny Komentarz>\n"
             << "#Marlena0: @Kiara0 <Wredny Komentarz>\n"
             << "#Kiara0: @Franciszek0 <Wredny Komentarz>\n"
             << "#Marlena0: @Kiara0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(false, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_SmallExample_False_3) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Nika0: @Liwia0 <Wredny Komentarz>\n"
             << "#Tulimir0: @Kajfasz0 <Wredny Komentarz>\n"
             << "#Liwia0: @Nika0 <Wredny Komentarz>\n"
             << "#Tulimir0: @Mirosława0 <Wredny Komentarz>\n"
             << "#Nika0: @Liwia0 <Wredny Komentarz>\n"
             << "#Kajfasz0: @Tulimir0 <Wredny Komentarz>\n"
             << "#Kajfasz0: @Nika0 <Wredny Komentarz>\n"
             << "#Liwia0: @Nika0 <Wredny Komentarz>\n"
             << "#Nika0: @Kajfasz0 <Wredny Komentarz>\n"
             << "#Liwia0: @Tulimir0 <Wredny Komentarz>\n"
             << "#Nika0: @Mirosława0 <Wredny Komentarz>\n"
             << "#Tulimir0: @Liwia0 <Wredny Komentarz>\n"
             << "#Tulimir0: @Kajfasz0 <Wredny Komentarz>\n"
             << "#Tulimir0: @Liwia0 <Wredny Komentarz>\n"
             << "#Kajfasz0: @Tulimir0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(false, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_SmallExample_True_1) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Berenika0: @Mirosław0 <Wredny Komentarz>\n"
             << "#Lucjana0: @Mirosław0 <Wredny Komentarz>\n"
             << "#Berenika0: @Mirosław0 <Wredny Komentarz>\n"
             << "#Berenika0: @Mirosław0 <Wredny Komentarz>\n"
             << "#January0: @Lucjana0 <Wredny Komentarz>\n"
             << "#Mirosław0: @Lucjana0 <Wredny Komentarz>\n"
             << "#Hilaria0: @Mirosław0 <Wredny Komentarz>\n"
             << "#Lucjana0: @Mirosław0 <Wredny Komentarz>\n"
             << "#Berenika0: @Mirosław0 <Wredny Komentarz>\n"
             << "#Mirosław0: @January0 <Wredny Komentarz>\n"
             << "#Berenika0: @January0 <Wredny Komentarz>\n"
             << "#Mirosław0: @Hilaria0 <Wredny Komentarz>\n"
             << "#January0: @Lucjana0 <Wredny Komentarz>\n"
             << "#Hilaria0: @Mirosław0 <Wredny Komentarz>\n"
             << "#Mirosław0: @Lucjana0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(true, test_solver.is_fair(prob, time));
    }

    BOOST_AUTO_TEST_CASE(Solver_SmallExample_True_2) {
        Solver test_solver;
        uint64_t time;
        std::stringstream file;

        file << "#Kiliana0: @Iwon0 <Wredny Komentarz>\n"
             << "#Iwon0: @Cina0 <Wredny Komentarz>\n"
             << "#Zbigniew0: @Cina0 <Wredny Komentarz>\n"
             << "#Iwon0: @Cina0 <Wredny Komentarz>\n"
             << "#Cina0: @Iwon0 <Wredny Komentarz>\n"
             << "#Eleonora0: @Zbigniew0 <Wredny Komentarz>\n"
             << "#Cina0: @Iwon0 <Wredny Komentarz>\n"
             << "#Kiliana0: @Eleonora0 <Wredny Komentarz>\n"
             << "#Eleonora0: @Kiliana0 <Wredny Komentarz>\n"
             << "#Eleonora0: @Kiliana0 <Wredny Komentarz>\n"
             << "#Cina0: @Iwon0 <Wredny Komentarz>\n"
             << "#Iwon0: @Kiliana0 <Wredny Komentarz>\n"
             << "#Kiliana0: @Iwon0 <Wredny Komentarz>\n"
             << "#Zbigniew0: @Iwon0 <Wredny Komentarz>\n"
             << "#Eleonora0: @Zbigniew0 <Wredny Komentarz>\n";

        GraphContainer prob(file);

        BOOST_CHECK_EQUAL(true, test_solver.is_fair(prob, time));
    }

BOOST_AUTO_TEST_SUITE_END()