#include <iostream>
#include <vector>
#include <fstream>
#include <boost/program_options.hpp>
#include <Generator.h>

using std::vector;
using std::string;
using std::cout;
using std::endl;

using namespace boost::program_options;

inline std::fstream open_output_stream(string filename) {
    std::fstream ret;
    ret.open(filename, std::ios::out);
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

        /* Initialize arguments ? */
        uint64_t l_count = 4,
                r_count = 2;
        bool fairness = false, file_out = false;


        if (vm.count("help")) {
            std::cout << desc << '\n';
            return 0;
        } else {
            if (vm.count("fairness"))
                fairness = vm["fairness"].as<bool>();
            if (vm.count("output"))
                file_out = true;
            //TODO : l_count, r_count
            //TODO : function for fair account
        }

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
