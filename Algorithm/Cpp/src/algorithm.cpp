//
// Created by przemek on 20.11.2019.
//

#include "../include/algorithm.h"

using namespace boost::program_options;

void cout_handle(int age) {
    std::cout << "Callback " << age << '\n';
}

int main(int argc, const char *argv[]) {
    try {
        options_description desc{"Options"};
        desc.add_options()
                ("help,h", "Help screen")
                ("count", value<int>()->default_value(100), "Whatever count")
                ("other_count", value<int>()->notifier(cout_handle), "Other nonsense count")
                ("bool", value<bool>()->default_value(true), "some logic value");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.count("help"))
            std::cout << desc << '\n';
        else {
            if (vm.count("count"))
                std::cout << "count: " << vm["count"].as<int>() << '\n';
            if (vm.count("other_count"))
                std::cout << "other_count: " << vm["other_count"].as<int>() << '\n';
            if (vm.count("bool"))
                std::cout << "bool: " << vm["bool"].as<bool>() << '\n';
        }
    }
    catch (const error &ex) {
        std::cerr << ex.what() << '\n';
    }
}