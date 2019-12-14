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

inline std::fstream open_output_stream(string filename) {
    std::fstream ret;
    ret.open(filename, std::ios::app);
    return ret;
}

int main(int argc, const char *argv[]) {
    try {
        options_description desc{"Options"};
        desc.add_options()
                ("help,h", "Help screen")
                ("comments_count,c", value<uint64_t>()->required(), "Count of one of the comments")
                ("users_count", value<uint64_t>()->required(), "Count of users")
                ("group_count", value<uint64_t>()->default_value(0), "Count of one group of users if account is fair")
                ("fairness,f", value<bool>()->default_value(false), "Determines if account should be fair or not")
                ("output,o", value<string>(), "Output file, leave blank to output to stdout");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        /* Initialize */
        uint64_t l_count = 4, count = 6;
        bool fairness = false, file_out = false, rand_group_count = false;

        std::random_device rd;
        std::mt19937_64 randomEngine(rd());

        /* Parse options */
        if (vm.count("help")) {
            std::cout << desc << '\n';
            return 0;
        } else {
            if (vm.count("fairness"))
                fairness = vm["fairness"].as<bool>();
            if (vm.count("output"))
                file_out = true;
            count = vm["users_count"].as<uint64_t>();
            l_count = vm["group_count"].as<uint64_t>();

            if (l_count == 0 && !fairness) {
                rand_group_count = true;
            } else if (l_count == 0) {
                //at least 10 % + 1
                l_count = randomEngine() % (9 * count) / 10 + count / 10 + 1;
            }
        }

        Generator generator;
        Solver solver;
        boost::chrono::microseconds time;

        std::stringstream prob = generator.generate_instance_output(false, 5, 2, 10);
        solver.is_fair(prob, time);

        cout << "= = = = = = = =\n";

        std::vector<string> prob2 = generator.generate_instance(false, 5, 2, 10);
        solver.is_fair(prob2, time);
//        vector<string> users = gen_user_groups(l_count + r_count);
//
//        if(file_out){
//            std::fstream file = open_output_stream(vm["filename"].as<string>());
//            file << write_comments(l_count * r_count, users, l_count).str();
//            file.close();
//        } else {
//            cout << write_comments(l_count * r_count, users, l_count).str();
//        }
    }
    catch (const error &ex) {
        std::cerr << ex.what() << " !\n";
    }
    return 0;
}
