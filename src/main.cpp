// #include <iostream>
// #include <print>
// #include <string>
#include <vector>

int main(int argc, char** argv) {

    (void) argc;
    (void) argv;

    std::vector<int> v;
    v.push_back(100);
    
    printf("Access v: %d\n", v[0]);
    // printf("Access v: %d\n", v[1]);
}
