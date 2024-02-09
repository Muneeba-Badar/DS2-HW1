#include "PostScriptFileSimplifier.hpp"

PostScriptFileSimplifier psfs;

std::vector<std::string> PostScriptFileSimplifier::read_file(std::vector<std::string> store_file){
    std::ifstream myfile;
    myfile.open("input\\file-1.ps"); //open the first file

    while(myfile >> psfs.file_word){ //pushes into the vector till file ends
        store_file.push_back(psfs.file_word);
    }

    myfile.close(); //close the file

    return store_file;
}

void PostScriptFileSimplifier::simplifyFile(std::vector<std::string> store_file){
    int num1, num2, ans;
    std::cout<<num1<<" "<<num2<<" "<<ans;
    // Create and open a text files
    std::ofstream MyFile("test-output\\file-1-simplified.ps");
    for (int i = 0; i < store_file.size(); i++){
        if (isdigit(store_file[i][0]) == false && psfs.stack1.empty() == true){
            MyFile << store_file[i] << " ";
        }
        else if (isdigit(store_file[i][0]) == true){
            psfs.stack1.push_back(std::stoi(store_file[i]));
            // std::cout<< " string " << store_file[i] << " num " << std::stoi(store_file[i]);
        }
        else if (isdigit(store_file[i][0]) == false && stack1.empty() != false){
            while(stack1.empty() == false){
                num2 = psfs.stack1[psfs.stack1.size()];
                psfs.stack1.pop_back();
                num1 = psfs.stack1[psfs.stack1.size()];
                psfs.stack1.pop_back();
            }
            if (store_file[i] == "add"){
                ans = num1+num2;
                MyFile << ans << " ";
            }
            else if (store_file[i] == "sub"){
                ans = num1-num2;
                MyFile << ans << " ";
            }
            else if (store_file[i] == "mul"){
                ans = num1*num2;
                MyFile << ans << " ";
            }
            else{
                MyFile << num1 << " ";
                MyFile << num2 << " ";
                MyFile << store_file[i] << " ";
            }
        }  
    }
    MyFile.close();
}

