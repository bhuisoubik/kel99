#include "../../include/lexer.h"
struct TokenType {
    string OUT = "OUT";
    string IN = "INPUT";
    string EQUAL = "EQUAL";
    string VALUE = "VALUE";
    string VAR = "VARIABLE";
    string INT = "TP:INT";
    string STR = "TP:STRING";
    string AD = "OP:ADD";
    string DF = "OP:DIFF";
    string ML = "OP:MUL";
    string DV = "OP:DIV";
    string MD = "OP:MOD";
    string LOOP = "LOOP";
    string LOOP_END = "LOOP_END";
    string TCONV = "TYPECONV";
} TT;

vector<string> lexer(string src) {
    vector<string> tokens;
    string tok = "", val_str = "",var_str = "";
    bool value_state = false, var_state = false;
    for(int i = 0; i < src.length();i++){
        tok += src[i];
        if(tok == " " || tok == "\n" || tok == "\t"){
            tok = "";
        } else if (tok == "out") {
            tokens.push_back(TT.OUT);
            tok = "";
        } else if (tok == "in") {
            tokens.push_back(TT.IN);
            tok = "";
        } else if (tok == "("){
            value_state = true;
        } else if (tok == ")") {
            if(val_str[1] == 'I' || val_str[1] == 'S'){
                tokens.push_back(TT.VALUE + ":" + val_str.substr(1, val_str.length()-1));
            } else {
                cout << "Invalid Flag";
                exit(EXIT_FAILURE);
            }
            val_str = tok = "";
            value_state = false;
        } else if (value_state) {
            val_str += tok;
            tok = "";
        } else if (tok == "[") {
            var_state = true;
        } else if (tok == "]") {
            tokens.push_back(TT.VAR + ":" + var_str.substr(1, var_str.length()-1));
            tok = var_str = "";
            var_state = false;
        } else if (var_state) {
            var_str += tok;
            tok = "";
        } else if (tok == ":"){
            tokens.push_back(TT.EQUAL);
            tok = "";
        } else if (tok == "ad") {
            tokens.push_back(TT.AD);
            tok = "";
        } else if (tok == "df") {
            tokens.push_back(TT.DF);
            tok = "";
        } else if (tok == "ml") {
            tokens.push_back(TT.ML);
            tok = "";
        } else if (tok == "dv") {
            tokens.push_back(TT.DV);
            tok = "";
        } else if (tok == "md") {
            tokens.push_back(TT.MD);
            tok = "";
        } else if (tok == "tconv") {
            tokens.push_back(TT.TCONV);
            tok = "";
        } else if (tok == "I") {
            tokens.push_back(TT.INT);
            tok = "";
        } else if (tok == "S") {
            tokens.push_back(TT.STR);
            tok = "";
        } else if (tok == "loop") {
            tokens.push_back(TT.LOOP);
            tok = "";
        } else if (tok == "endloop"){
            tokens.push_back(TT.LOOP_END);
            tok = "";
        }
    }

    return tokens;
}