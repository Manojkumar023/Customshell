#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<sstream>
#include<thread>
#include<cstdlib>
using namespace std;
#define maxhistorysize 10

class Customshell {
public:
    void run(){
        string input;
        while(true) {
        cout<<"custom_shell>";
            getline(cin,input);
            if (input=="exit") break;
            processcommand(input);
        }
    }

private:
    unordered_map<string,string>variables; 
    queue<string>history; 
    

    void processcommand(const string& input) {
        addtohistory(input);
        istringstream stream(input);
        string command;
        stream>>command;

        if(command=="set") {
            setvariable(stream);
        }else if (command=="get") {
            getvariable(stream);
        }else if (command=="history") {
            printhistory();
        }else {
            executecommand(input);
        }
    }

    void addtohistory(const std::string& command) {
        if(history.size()>=maxhistorysize) {
            history.pop(); 
        }
        history.push(command);
    }

    void printhistory(){
        queue<string>temp=history;
        while(!temp.empty()){
            cout<<temp.front()<<endl;
            temp.pop();
        }
    }

    void setvariable(istringstream& stream) {
        string varname, varvalue;
        stream>>varname>>varvalue;
        variables[varname]=varvalue;
    }

    void getvariable(istringstream& stream) {
        string varname;
        stream>>varname;
        if(variables.find(varname)!=variables.end()) {
            cout<<variables[varname]<<endl;
        }else{
            cout<<"Variable not found."<<endl;
        }
    }

    void executecommand(const string& command) {
        //usind thread to execute the command
        thread([command]() {
            int result=system(command.c_str());
            if (result!=0) {
                cerr<<"Command execution failed with code: "<<result<<endl;
            }
        }).join(); //waiting for the thread to complete
    }
};

int main() {
    Customshell shell;
    shell.run();
    return 0;
}
