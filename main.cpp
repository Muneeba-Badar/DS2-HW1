#include "PostScriptFileSimplifier.hpp"

int main(){
    PostScriptFileSimplifier p;
    std::vector<std::string> var_for_vec;
    var_for_vec = p.read_file(p.store_file);
    p.simplifyFile(var_for_vec);
    return 0;
}