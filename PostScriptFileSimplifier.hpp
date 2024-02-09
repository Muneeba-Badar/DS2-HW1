#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// #include "StackPostscript.hpp"


class PostScriptFileSimplifier{
    public:
        std::string file_word; //variable to store each word in file
        std::vector<std::string> store_file; //a vector to store what is being read in the file
        std::vector<int> stack1; //stack for numbers

        PostScriptFileSimplifier(){}; //constructor
        ~PostScriptFileSimplifier(){}; //destructor

        std::vector<std::string> read_file(std::vector<std::string> store_file); //function that reads the files
        void simplifyFile(std::vector<std::string> store_file);
        int pop(std::vector<int> stack1);
};

/*
class PostScriptFileSimplifier{
    public:
        std::string file_word; //variable to store each word in file
        std::vector<std::string> store_file; //a vector to store what is being read in the file

        PostScriptFileSimplifier(){}; //constructor
        ~PostScriptFileSimplifier(){}; //destructor

        std::vector<std::string> read_file(std::vector<std::string> store_file){
            std::ifstream myfile;
            myfile.open("input\\file-1.ps"); //open the first file

            while(myfile >> file_word){ //pushes into the vector till file ends
            //     if (myfile >> '\n'){
            //         std::cout<<"new lineee";
            //     }
            //     store_file.push_back(file_word);
            // }
            std::cout<<file_word;
                if (file_word.back() == '\0') {
                std::cout << "New line detected after word: " << file_word.substr(0, file_word.size() - 1) << std::endl;
                }
                
                else {
                    store_file.push_back(file_word);
                }
            }
            myfile.close(); //close the file

            return store_file;
        }

        void simplifyFile(std::vector<std::string> store_file){
            // Create and open a text file
            std::ofstream MyFile("test-output\\file-1-simplified.ps");
            for (int i = 0; i < store_file.size(); i++){
                // Write to the file
                MyFile << store_file[i];
            }
            MyFile.close();
        }
};
*/