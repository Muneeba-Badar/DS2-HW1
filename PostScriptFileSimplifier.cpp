#include "PostScriptFileSimplifier.hpp"

PostScriptFileSimplifier psfs;

std::vector<std::string> PostScriptFileSimplifier::read_file(std::vector<std::string> store_file){
    std::ifstream myfile;
    myfile.open("input\\file-2.eps"); //open the first file

    while(myfile >> psfs.file_word){ //pushes into the vector till file ends
        store_file.push_back(psfs.file_word);
    }

    myfile.close(); //close the file

    return store_file;
}

void PostScriptFileSimplifier::simplifyFile(std::vector<std::string> store_file){
    int num1, num2, counter;
    std::string lineToWrite;
    
    // Create and open a text files
    std::ofstream MyFile("test-output\\file-2-simplified.eps");

    for (int i = 0; i < store_file.size(); i++) //iterates over the entire vector which stores which stores each element of the file
    {
        if(isdigit(store_file[i][0])) //if the element is a digit push it into stack1
        {
            int x = std::stoi(store_file[i]); //converts the digit from string to int
            psfs.stack1.push_back(x); //pushes into the stack
        }
        else //if element is not a digit
        {
            if (psfs.stack1.size() >= 2) //if more than 2 numbers in stack1
            {
                if(store_file[i] == "add")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = std::to_string(num2+num1) + " ";
                }
                else if(store_file[i] == "sub")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = std::to_string(num2-num1) + " ";
                }
                
                else if(store_file[i] == "mul")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = std::to_string(num2*num1) + " ";
                }
                else if(store_file[i] == "div")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = std::to_string(num2/num1) + " ";
                }
                else
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite =  std::to_string(num1) + " " + std::to_string(num2) + " " + store_file[i] + '\n';
                }
                MyFile << lineToWrite; //writes in the file
                continue;
            }
            else if (psfs.stack1.size() == 1)
            {
                if(store_file[i] == "sqrt")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = std::to_string(sqrt(num1)) + " ";
                }
                else if(store_file[i] == "exp")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = std::to_string(exp(num1)) + " ";
                }
                else
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite =  std::to_string(num1) + " " + store_file[i] + '\n';
                }
                MyFile << lineToWrite; //writes in the file
            }
            else
            {
                MyFile << store_file[i] << '\n'; //writes in the file
            }      
        }
    }
    MyFile.close();
}