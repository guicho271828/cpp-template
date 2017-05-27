#include <experimental/filesystem>
#include <iostream>
#include <unordered_map>
#include <deque>

#include "printer.h"

// not in large code base!
using namespace std;
using namespace std::experimental::filesystem ;


unordered_map<string,bool>   bool_options = {
    {"a", false},
    {"l", false}
};

unordered_map<string,string> string_options = {
    
};

unordered_map<string,string> alias_table = {
    {"all", "a"},
};

deque<string> parse_options(int argc, char* argv[]){
    deque<string> args;
    int i = 1;
    for(; i<argc; i++){
        string arg = argv[i];
        if (arg[0] == '-'){
            auto end = arg.find('=');
            string value = arg.substr(end+1);
            if (arg[1] == '-'){
                arg = alias_table[arg.substr(2,end)];
            }
            if (end == string::npos){
                bool_options[arg] = true;
            }else{
                string_options[arg] = value;
            }
        }else{
            break;
        }
    }
    for(; i<argc; i++){
        args.push_back(argv[i]);
    }
    cout << args << endl;
    cout << bool_options << endl;
    cout << string_options << endl;
    cout << alias_table << endl;
    // cout << function_table << endl;
    return args;
}


int main(int argc, char* argv[]) {
    auto rest = parse_options(argc,argv);
    return 0;
}

