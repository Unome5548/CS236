#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::ofstream;
using namespace std;

int checkWords(string word, int n);
int checkSingleChar(char c, int n);
int lastSymbols(char c);
int sendToken(string word, int n);

    string word;
    string str;
    bool stringBool = false;
    bool w = false;
    bool comment = false;
    int n = 0;


int main(int argc, char* argv[])
{
    ifstream in;
    in.open(argv[1]);
    ofstream myfile;
    myfile.open(argv[2]);

    while (in.good()){
        char c = in.get();       // get character from file
        if(in.good()){
            if(c == '\n'){
                if(w){
                    checkWords(word, n);
                    w = false;
                    word = "";
                }
                if(stringBool){
                    cout << "ERROR OMG!!!" << endl;
                }
                n++;
                comment = false;
            }
            else if(c == '\''){
                // switch(stringBool){
                //     case false:
                //         checkWords(word, n);
                //         w = false;
                //         word = "";
                //         stringBool = true;
                //     case true:
                //         stringBool = false;
                //         cout << "(STRING,\"" << str << "\"," << n << ")" << endl;
                //         str = "";
                // }
                    if(stringBool == false){
                        checkWords(word, n);
                        w = false;
                        word = "";
                        stringBool = true;
                    }
                    else{
                        stringBool = false;
                        sendToken(str, n);
                        str = "";
                    }
            }  
            else if(stringBool){
                str.append(1, c);
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
            else if(isdigit(c)){
                word.append(1,c);
            }
            else{          
                lastSymbols(c);
            }
        }
    }
    in.close();
    myfile.close();
}

int lastSymbols(char c){
    if(w == true){
        checkWords(word, n);
        w = false;
        word = "";
    }
    else if(c == '#'){
        comment = true;
    }
    else {
        checkSingleChar(c, n);
    }
}

int checkWords(string word, int n){
    if(word == "Schemes"){
        cout << "(SCHEMES,\"Schemes\"," << n << ")" << endl;
    }
    else if(word == "Facts"){
        cout << "(FACTS,\"Facts\"," << n << ")" << endl;
    }
    else if(word == "Rules"){
        cout << "(RULES,\"Rules\"," << n << ")" << endl;
    }
    else if(word == "Queries"){
        cout << "(QUERIES,\"Queries\"," << n << ")" << endl;
    }
    else if(word == ""){
        //do nothing
    }
    else{
        cout << "(ID,\"" << word << "\"," << n << ")" << endl;
    }
}

int checkSingleChar(char c, int n){
    switch(c){
        case '.':
            cout << "(PERIOD,\".\"," << n << ")" << endl;
            break;
        case ',':
            cout << "(COMMA,\",\"," << n << ")" << endl;
            break;
        case '?':
            cout << "(Q_MARK,\"?\"," << n << ")" << endl;
            break;
        case '(':
            cout << "(LEFT_PAREN,\"(\"," << n << ")" << endl;
            break;
        case ')':
            cout << "(RIGHT_PAREN,\")\"," << n << ")" << endl;
            break;
        case ':':
            cout << "(COLON,\":\"," << n << ")" << endl;
            break;
        case ' ':
            break;
        default:
            cout << "ERROR2" << c << "LINE N" << n << endl;
            break;
    }
}

int sendToken(string word, int n){
    if(comment == false){
        cout << "(STRING,\""<< word << "\"," << n << ")" << endl;
    }
}





