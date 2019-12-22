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

int main(int argc, const char *argv[]) {
    std::random_device rd;
    std::mt19937_64 randomEngine(rd());

    /* Initialize */
    uint64_t l_count = 0, count = 0, comments = 0, iter = 1;
    bool fairness = false, profiling = false, file_out = false, rand_group_count = false, generating = false;
    string filename;

    /*
     * Using boost to parse program options
     */
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
                ("output,o", value<string>(), "Output file, leave blank to output to stdout")
                ("generating,g", value<bool>()->default_value(false), "Determines if current run is for profiling");

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
            generating = vm["generating"].as<bool>();

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
    uint64_t time = 0;

    if (profiling) {
        for (uint64_t i = 0; i < iter; ++i) {
            if (rand_group_count) {
                l_count = randomEngine() % (7 * count / 10) + (3 * count / 10) + 1;
            }
            vector<string> prob = generator.generate_instance(fairness, count, l_count, comments);
            solver.is_fair(prob, time);
//            std::cerr << solver.is_fair(prob, time);
        }
        double avg_time = (time * 1.) / iter;
        cout << count << ", " << comments << ", " << avg_time << '\n';
    } else {
        if (generating) {
            std::stringstream prob = generator.generate_instance_output(fairness, count, l_count, comments);
            if (file_out) {
                std::fstream file;
                file.open(filename, std::ios::out);
                file << prob.str();
                file.close();
            } else {
                cout << prob.str();
            }
        } else {
            vector<string> prob = generator.generate_instance(fairness, count, l_count, comments);
            if (solver.is_fair(prob, time)) {
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        }
    }
    return 0;
}
