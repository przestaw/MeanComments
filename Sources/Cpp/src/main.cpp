#include <iostream>
#include <vector>
#include <fstream>
#include <boost/program_options.hpp>
#include <Generator.h>
#include <Solver.h>

using std::vector;
using std::string;
using std::cout;
using std::endl;

using namespace boost::program_options;

inline std::fstream open_output_stream(const string &filename) {
    std::fstream ret;
    ret.open(filename, std::ios::out);
    return ret;
}

int main(int argc, const char *argv[]) {
    std::random_device rd;
    std::mt19937_64 randomEngine(rd());

    /* Initialize */
    uint64_t l_count = 0, count = 0, comments = 0, iter = 1;
    bool fairness = false, profiling = false, file_out = false, rand_group_count = false;
    string filename;

    try {
        options_description desc{"Options"};
        desc.add_options()
                ("help,h", "Help screen")
                ("comments_count,c", value<uint64_t>()->required(), "Count of one of the comments")
                ("users_count", value<uint64_t>()->required(), "Count of users")
                ("group_count", value<uint64_t>()->default_value(0), "Count of one group of users if account is fair")
                ("fairness,f", value<bool>()->default_value(false), "Determines if account should be fair or not")
                ("iter,i", value<uint64_t>()->default_value(1), "Number of iteration if profiling flag is present")
                ("profiling,p", value<bool>()->default_value(false), "Determines if current run is for profiling")
                ("output,o", value<string>(), "Output file, leave blank to output to stdout");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        /* Parse options */
        if (vm.count("help")) {
            std::cout << desc << '\n';
            return 0;
        } else {
            fairness = vm["fairness"].as<bool>();
            count = vm["users_count"].as<uint64_t>();
            l_count = vm["group_count"].as<uint64_t>();
            comments = vm["comments_count"].as<uint64_t>();
            iter = vm["iter"].as<uint64_t>();

            if (vm["profiling"].as<bool>()) {
                profiling = true;
                if (l_count == 0) {
                    rand_group_count = true;
                }
            } else {
                if (vm.count("output")) {
                    file_out = true;
                }
                if (l_count == 0) {
                    l_count = randomEngine() % (9 * count) / 10 + count / 10 + 1;
                }
            }
        }
    }
    catch (const error &ex) {
        std::cerr << ex.what() << " !\n";
        return -1;
    }

    Generator generator;
    Solver solver;

    if (profiling) {
        uint64_t time = 0;
        for (uint64_t i = 0; i < iter; ++i) {
            if (rand_group_count) {
                l_count = randomEngine() % (7 * count / 10) + (3 * count / 10) + 1;
            }
            vector<string> prob = generator.generate_instance(false, count, l_count, comments);
            std::cerr << solver.is_fair(prob, time);
        }
        double avg_enlapsed = time / iter;
        cout << count << ", " << comments << ", " << avg_enlapsed << '\n';
    } else {
        //TODO
    }
    return 0;
}
