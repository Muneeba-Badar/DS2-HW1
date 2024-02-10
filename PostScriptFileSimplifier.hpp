#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
// #include "StackPostscript.hpp"


class PostScriptFileSimplifier{
    public:
        std::string file_word; //variable to store each word in file
        std::vector<std::string> store_file; //a vector to store what is being read in the file
        std::vector<int> stack1; //stack for numbers (Stores the numbers which are in the file)

        PostScriptFileSimplifier(){}; //constructor
        ~PostScriptFileSimplifier(){}; //destructor

        std::vector<std::string> read_file(std::vector<std::string> store_file); //function that reads the files
        void simplifyFile(std::vector<std::string> store_file);
        // int pop(std::vector<int> stack1);
};