#include <functional>

// void show_list(deque<string>);

unordered_map<string, function<void(deque<string>)> > function_table = {
    // {"normal", &show_list},
    // {"list", &show_list},
};
