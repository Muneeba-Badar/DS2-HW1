#include "PostScriptFileSimplifier.hpp"

PostScriptFileSimplifier psfs;

vector<string> PostScriptFileSimplifier::read_file(vector<string>& store_file){
    ifstream myfile;
    myfile.open("input\\file-2.eps"); //open the first file

        while(myfile >> psfs.file_word)
        {
            psfs.store_file.push_back(psfs.file_word); //pushes each element into the vector
        }
    
    myfile.close(); //close the file

    return psfs.store_file;
}

void PostScriptFileSimplifier::simplifyFile(vector<string>& store_file){
    int num1, num2, num3, counter;
    string lineToWrite, lineToWrite2;
    
    // Create and open a text files
    ofstream MyFile("test-output\\file-2-simplified.eps");
    for (int i = 0; i < psfs.store_file.size(); i++) //iterates over the entire vector which stores which stores each element of the file
    {
        if(isdigit(store_file[i][0])) //if the element is a digit push it into stack1
        {
            int x = stoi(store_file[i]); //converts the digit from string to int
            psfs.stack1.push_back(x); //pushes into the stack
        }
        else //if element is not a digit
        {
            if (psfs.stack1.size() >= 2) //if 2 ore more numbers in stack1
            {
                if(store_file[i] == "add") //if the next element is add 
                {
                    //pop the last 2 elements from the stack
                    num1 = psfs.stack1.back(); 
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    //string created to write in the file
                    lineToWrite = to_string(num2+num1) + " ";
                }
                else if(store_file[i] == "sub") //if the next element is sub
                {
                    //pop the last 2 elements from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num2-num1) + " ";
                }
                
                else if(store_file[i] == "mul") //if the next element is mul
                {
                    //pop the last 2 elements from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num2*num1) + " ";
                }
                else if(store_file[i] == "div") //if the next element is div
                {
                    //pop the last 2 elements from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num2/num1) + " ";
                }
                else if(store_file[i] == "exch") //if the next element is echage
                {
                    //pop the last 2 elements from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num2) + " " +to_string(num1) + " ";
                }
                else if(store_file[i] == "mod") //if the next element is mod
                {
                    //pop the last 2 elements from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num1%num2) + " ";
                }
                else
                {
                    //pop the last 2 elements from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite =  to_string(num1) + " " + to_string(num2) + " " + store_file[i] + '\n';
                }
                if(psfs.stack1.empty())
                {
                    MyFile << lineToWrite; //writes in the file
                }
                else
                {
                    num3 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite2 = to_string(num3) + " " + lineToWrite;
                    MyFile << lineToWrite2; //writes in the file
                }
            }
            else if (psfs.stack1.size() == 1) //if 1 numbers in stack1
            {
                if(store_file[i] == "sqrt") //if the next element is sqrt
                {
                    //pop the last element from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(sqrt(num1)) + " ";
                }
                else if(store_file[i] == "exp") //if the next element is exp
                {
                    //pop the last element from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(exp(num1)) + " ";
                }
                else if(store_file[i] == "dup") //if the next element is duplicate
                {
                    //pop the last element from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num1) + " " + to_string(num1) + " ";
                }
                else if(store_file[i] == "cos") //if the next element is cos
                {
                    //pop the last element from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(cos(num1)) + " ";
                }
                else if(store_file[i] == "sin") //if the next element is sin
                {
                    //pop the last element from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(sin(num1)) + " ";
                }
                else
                {
                    //pop the last element from the stack
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite =  to_string(num1) + " " + store_file[i] + '\n';
                }
                MyFile << lineToWrite; //writes in the file
            }
            else //if stack is empty directly write it in the file
            {
                MyFile << store_file[i] << '\n'; //writes in the file
            }      
        }
    }
    MyFile.close();
}