#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// #include "StackPostscript.hpp"


class PostScriptFileSimplifier{
    public:
        string file_word; //variable to store each word in file
        vector<string> store_file; //a vector to store what is being read in the file
        vector<int> stack1; //stack for numbers (Stores the numbers which are in the file)

        PostScriptFileSimplifier(){}; //constructor
        ~PostScriptFileSimplifier(){}; //destructor

        vector<string> read_file(vector<string>& store_file);
        void simplifyFile(vector<string>& store_file);
};