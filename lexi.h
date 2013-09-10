#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::ofstream;
using namespace std;


int main(int argc, char* argv[])
{
    ifstream in;
    string s;
    in.open(argv[1]);
    ofstream myfile;
    myfile.open(argv[2]);

    vector<string> words;
    string word;
    bool w = false;
    int n = 0;
                            // loop while extraction from file is possible
    while (in.good()){
        char c = in.get();       // get character from file
        if(in.good()){
            if(c == '\n'){
                n++;
                w = false;
            }
            else if(isalpha(c)){
                if(w == false){
                    w = true;
                    word.append(1,c);
                }
                else{
                    word.append(1,c);
                }
            }
            else{            
                if(w == true){
                    if(word == "Schemes"){
                        cout << "(SCHEMES,\"Schemes\"," << n << ")" << endl;
                    }
                    else{
                        cout << "(ID,\"" << word << "\"," << n << ")" << endl;
                    }
                    w = false;
                    word = "";
                }
                if(c == '.'){
                    cout << "(PERIOD,\".\"," << n << ")" << endl;
                }
                else if(c == ','){
                    cout << "(COMMA,\",\"," << n << ")" << endl;
                }
                else if(c == '?'){
                    cout << "(Q_MARK,\"?\"," << n << ")" << endl;
                }
                else if(c == '?'){
                    cout << "(Q_MARK,\"?\"," << n << ")" << endl;
                }
                else if(c == '('){
                    cout << "(LEFT_PAREN,\"(\"," << n << ")" << endl;
                }
                else if(c == ')'){
                    cout << "(RIGHT_PAREN,\")\"," << n << ")" << endl;
                }
            }
        }
    }
    if(w){
        cout << word << endl;
    }

    for(int i = 0; i < words.size(); i++){
        // cout << words[i] << endl;
    }
    crap();
    in.close();
    myfile.close();
}

void crap(){
    cout << "OMG CRAP!!!!" << endl;
}





