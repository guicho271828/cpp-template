#include <experimental/filesystem>
#include <iostream>
#include <unordered_map>
#include <deque>
#include <sstream>

#include "cereal/cereal.hpp"
#include "printer.hpp"
#include "hash.hpp"

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
            string key =
                arg.substr((arg[1] == '-') ? 2:1,
                           end-1);
            
            auto it = alias_table.find(key);
            if (it != alias_table.end()){
                key = it->second;
            }
            
            if (end == string::npos){
                if (bool_options.find(key) == bool_options.end()){
                    stringstream ss;
                    ss << key << " is an unknown boolean option";
                    throw domain_error(ss.str());
                }
                bool_options[key] = true;
            }else{
                if (string_options.find(key) == string_options.end()){
                    stringstream ss;
                    ss << key << " is an unknown key-value option";
                    throw domain_error(ss.str());
                }
                string_options[key] = value;
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

