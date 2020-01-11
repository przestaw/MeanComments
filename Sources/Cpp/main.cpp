#include <iostream>
#include <vector>
#include <fstream>
#include <boost/program_options.hpp>
#include <Generator.h>
#include <Solver.h>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::cerr;

using namespace boost::program_options;

struct Args {
    enum class Mode {
        profiling, output, input
    };
    Mode mode = Mode::output;
    uint64_t group_count = 0;
    uint64_t count = 0;
    uint64_t comments = 0;
    uint64_t iter = 1;
    bool fairness = false;
    bool use_file = false;
    bool rand_group_count = false;
    string filename;
};

int parse_arguments(Args &args, int argc, const char *argv[]);

void do_profiling(const Args &args, const uint64_t &seed);

void do_output(const Args &args);

void do_input(const Args &args);

int main(int argc, const char *argv[]) {
    Args args;

    if (parse_arguments(args, argc, argv) == 0) {
        switch (args.mode) {
            case Args::Mode::profiling:
                do_profiling(args, 12);
                break;
            case Args::Mode::output:
                do_output(args);
                break;
            case Args::Mode::input:
                do_input(args);
                break;
        }
    }
    return 0;
}

void do_profiling(const Args &args, const uint64_t &seed) {
    Generator generator;
    Solver solver;
    uint64_t time = 0;
    uint64_t l_count = 0;

    if (!args.rand_group_count) {
        l_count = args.rand_group_count;
    }

    std::mt19937_64 randomEngine(seed);

    for (uint64_t i = 0; i < args.iter; ++i) {
        if (args.rand_group_count) {
            l_count = randomEngine() % (7 * args.count / 10) + (3 * args.count / 10) + 1;
        }
        vector<string> prob =
                generator.generate_instance(args.fairness,
                                            args.count,
                                            l_count,
                                            args.comments);
        GraphContainer graph(prob);
        solver.is_fair(graph, time);
    }
    double avg_time = (time * 1.) / args.iter;
    cout << args.count << ", " << args.comments << ", " << avg_time << '\n';
}

void do_output(const Args &args) {
    Generator generator;
    std::stringstream prob =
            generator.generate_instance_output(args.fairness,
                                               args.count,
                                               args.group_count,
                                               args.comments);
    if (args.use_file) {
        std::fstream file;
        try {
            file.open(args.filename, std::ios::out);
            file << prob.str();
            file.close();
        } catch (const std::fstream::failure &ex) {
            std::cerr << "Exception opening file\n";
        }
    } else {
        cout << prob.str();
    }
}

void do_input(const Args &args) {
    Solver solver;
    uint64_t time = 0; //for compatibility

    std::stringstream prob;
    if (args.use_file) {
        std::fstream file;
        try {
            file.open(args.filename, std::ios::in);
            prob << file.rdbuf();
            file.close();
        } catch (const std::fstream::failure &ex) {
            std::cerr << "Exception opening file\n";
            return; // we have nothing to solve
        }
    } else {
        //prob << cin.rdbuf();
    }

    GraphContainer graph(prob);

    if (solver.is_fair(graph, time)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
}

int parse_arguments(Args &args, int argc, const char *argv[]) {
    try {
        options_description desc{"Options"};
        desc.add_options()
                ("help,h", "Help screen")
                ("comments_count,c", value<uint64_t>()->default_value(10), "Count of one of the comments")
                ("users_count", value<uint64_t>()->default_value(5), "Count of users")
                ("group_count", value<uint64_t>()->default_value(0), "Count of one group of users if account is fair")
                ("fairness,f", value<bool>()->default_value(false), "Determines if account should be fair or not")
                ("iter", value<uint64_t>()->default_value(1), "Number of iteration if profiling flag is present")
                ("output,o", value<string>(), "Output file, leave blank to output to stdout")
                ("input,i", value<string>(), "Input file")
                ("mode,m", value<uint16_t>()->default_value(0),
                 "Mode in which program runs [1 = solving (default), 2 = generation, 3 = profiling]");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        /* Parse options */
        if (vm.count("help")) {
            std::cout << desc << '\n';
            return 1;
        } else {
            args.fairness = vm["fairness"].as<bool>();
            args.count = vm["users_count"].as<uint64_t>();
            args.group_count = vm["group_count"].as<uint64_t>();
            args.comments = vm["comments_count"].as<uint64_t>();
            args.iter = vm["iter"].as<uint64_t>();

            switch (vm["mode"].as<uint16_t>()) {
                case 1:
                    args.mode = Args::Mode::input;
                    if (vm.count("input")) {
                        args.filename = vm["input"].as<std::string>();
                    }
                    break;
                case 2:
                    args.mode = Args::Mode::output;
                    if (vm.count("output")) {
                        args.use_file = true;
                        args.filename = vm["output"].as<std::string>();
                    }
                    if (args.group_count == 0) {
                        // random value form platform specific generator,
                        // eg /dev/random
                        args.group_count =
                                std::random_device()()
                                % (7 * args.count / 10) + (3 * args.count / 10) + 1;
                    }
                    break;
                case 3:
                    args.mode = Args::Mode::profiling;
                    if (args.group_count == 0) {
                        args.rand_group_count = true;
                    }

                    break;
                default:
                    throw error("Unsupported mode !\nSupported modes are : "
                                "\n[1 = solving, 2 = generation, 3 = profiling]"
                                "\nUse --help or -h option to show available arguments");
            }
        }
    } catch (const error &ex) {
        cerr << ex.what() << " !\n";
        return -1;
    }
    return 0;
}