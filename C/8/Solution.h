// 自动机
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Automaton{
    string status = "start";
    unordered_map<string, vector<string>> table ={
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    int get_col (char c){
        if (isspace(c))return 0;
        else if (c == '+' ||c == '-') return 1;
        else if (isdigit(c)) return 2;
        else return 3;
    }
public:
    long long ans = 0;
    int sign = 1;
    void get(char c){
        status = table[status][get_col(c)];
        if(status == "in_number"){
            ans = ans*10 + c -'0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX): min(ans, -(long long)INT_MIN);

        }else if (status == "signed"){
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution {
public:
    int myAtoi(string s) {
        Automaton automaton;
        for(char c:s){
            automaton.get(c);
        }
        return automaton.sign*automaton.ans;
    }
};