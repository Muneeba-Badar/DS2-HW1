#include "PostScriptFileSimplifier.hpp"

PostScriptFileSimplifier psfs;

string strip(const string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    
    if (start == string::npos || end == string::npos)
        return ""; // String only contains whitespace
    cout<<str.substr(start, end - start + 1);
    return str.substr(start, end - start + 1);
}

vector<string> PostScriptFileSimplifier::read_file(vector<string>& store_file){
    ifstream myfile;
    myfile.open("input\\file-1.ps"); //open the first file

    while(myfile >> psfs.file_word){ //pushes into the vector till file ends
        store_file.push_back(psfs.file_word);
    }

    myfile.close(); //close the file

    return store_file;
}

void PostScriptFileSimplifier::simplifyFile(vector<string>& store_file){
    int num1, num2, num3, counter;
    string lineToWrite, lineToWrite2;
    
    // Create and open a text files
    ofstream MyFile("test-output\\file-1-simplified.ps");

    for (int i = 0; i < store_file.size(); i++) //iterates over the entire vector which stores which stores each element of the file
    {
        if(isdigit(store_file[i][0])) //if the element is a digit push it into stack1
        {
            int x = stoi(store_file[i]); //converts the digit from string to int
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
                    lineToWrite = to_string(num2+num1) + " ";
                }
                else if(store_file[i] == "sub")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num2-num1) + " ";
                }
                
                else if(store_file[i] == "mul")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num2*num1) + " ";
                }
                else if(store_file[i] == "div")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num2/num1) + " ";
                }
                else if(store_file[i] == "exch")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num2) + " " +to_string(num1) + " ";
                }
                else if(store_file[i] == "mod")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    num2 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num1%num2) + " ";
                }
                else
                {
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
                    MyFile << lineToWrite2;
                }
            }
            else if (psfs.stack1.size() == 1)
            {
                if(store_file[i] == "sqrt")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(sqrt(num1)) + " ";
                }
                else if(store_file[i] == "exp")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(exp(num1)) + " ";
                }
                else if(store_file[i] == "dup")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(num1) + " " + to_string(num1) + " ";
                }
                else if(store_file[i] == "cos")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(cos(num1)) + " ";
                }
                else if(store_file[i] == "sin")
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite = to_string(sin(num1)) + " ";
                }
                else
                {
                    num1 = psfs.stack1.back();
                    psfs.stack1.pop_back();
                    lineToWrite =  to_string(num1) + " " + store_file[i] + '\n';
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