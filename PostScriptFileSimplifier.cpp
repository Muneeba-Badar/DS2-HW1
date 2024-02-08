#include "PostScriptFileSimplifier.hpp"

PostScriptFileSimplifier psfs;
StackPostscript<int> sps;

int PostScriptFileSimplifier::pop(std::vector<int> stack1){
    return stack1[stack1.size()];
}

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
    // Create and open a text files
    std::ofstream MyFile("test-output\\file-1-simplified.ps");
   

    for (int i = 0; i < store_file.size(); i++){
        // Write to the file
        int x, y; //iska int hona zaroori nahi hai float bhi ho sakta hai depending on ke stack mein kia hai
        if(store_file[i] == "add" || store_file[i] == "sub" || store_file[i] == "div" || store_file[i] == "mul"){
            // x = psfs.stack1[psfs.stack1.size()];
            // y = psfs.stack1[psfs.stack1.size()];
            x = psfs.pop(psfs.stack1);
            y = psfs.pop(psfs.stack1);
            
            if (store_file[i] == "add"){
                sps.add(x,y);
            }
            else if (store_file[i] == "sub"){
                sps.sub(x,y);
            }
            else if (store_file[i] == "mul"){
                sps.mul(x,y);
            }
            else if (store_file[i] == "div"){
                sps.div(x,y);
            }
        }
        // if(isdigit(store_file[i])){
        //     num = std::stoi(store_file[i]);
        // }
        MyFile << store_file[i] << " ";
    }
    MyFile.close();
}
