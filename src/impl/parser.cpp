#include "../../include/parser.h"
#include "../../include/get_val_str.h"
#include "../../include/gen_val.h"
#include "../../include/input.h"
#include "../../include/occur.h"

map<string, string> mem;

string int_operation_parser(string op, string left, string right) {
    string l , r;
    if(left.substr(0, 5) == "VALUE"){
        l = left.substr(8, left.length()-1);
    } else if (left.substr(0, 8) == "VARIABLE"){
        string v = mem[left.substr(9, left.length()-1)];
        l = v.substr(2, v.length()-1);
    }

    if(right.substr(0, 5) == "VALUE"){
        r = right.substr(8, right.length()-1);
    } else if (right.substr(0, 8) == "VARIABLE"){
        string v = mem[right.substr(9, right.length()-1)];
        r = v.substr(2, v.length()-1);
    }

    int l_int = get_val_int(l), r_int = get_val_int(r), res;
    if (op == "OP:ADD") {
        res = l_int + r_int;
    } else if (op == "OP:DIFF") {
        res = l_int - r_int;
    } else if (op == "OP:MUL") {
        res = l_int * r_int;
    } else if (op == "OP:DIV") {
        res = l_int / r_int;
    } else if (op == "OP:MOD") {
        res = l_int % r_int;
    } else {
        cout << "Operator not supported\n";
        exit(EXIT_FAILURE);
    }

    return gen_val(res);
}

void parser(vector<string> tokens) {
    int lf_ptr, loop_times, l_end_c = 0;
    for(int i = 0; i < tokens.size();i++){
        if(tokens[i] == "OUT" && tokens[i+1].substr(0,5) == "VALUE"){ // Print values to console
            cout << get_val_str(tokens[i+1].substr(8, tokens[i+1].length()-1));
            i += 1;
        } else if (tokens[i] == "OUT" && tokens[i+1].substr(0, 8) == "VARIABLE"){ // Print variables to console
            string v = mem[tokens[i+1].substr(9, tokens[i+1].length()-1)];
            cout << get_val_str(v.substr(2, v.length()-1));
            i += 1;
        } else if (tokens[i] == "OUT" && tokens[i+1].substr(0, 2) == "OP"){ // Print operational values to console
            string v = int_operation_parser(tokens[i+1], tokens[i+2], tokens[i+3]);
            cout << get_val_str(v.substr(2, v.length()-1));
            i += 3;
        } else if (tokens[i].substr(0, 8) == "VARIABLE" && tokens[i+1] == "EQUAL" && tokens[i+2].substr(0, 5) == "VALUE") { // Assigning a VALUE to variable
            string k = tokens[i].substr(9, tokens[i].length()-1);
            string v = tokens[i+2].substr(6, tokens[i+2].length()-1);
            mem[k] = v;
            i += 2;
        } else if (tokens[i].substr(0, 8) == "VARIABLE" && tokens[i+1] == "EQUAL" && tokens[i+2].substr(0, 8) == "VARIABLE") { // Assigning another Variables's VALUE to variable
            string k = tokens[i].substr(9, tokens[i].length()-1);
            string v = tokens[i+2].substr(9, tokens[i+2].length()-1);
            mem[k] = mem[v];
            i += 2;
        } else if (tokens[i].substr(0, 8) == "VARIABLE" && tokens[i+1] == "EQUAL" && tokens[i+2].substr(0, 2) == "OP") { // Assigning operational VALUE to variable
            string k = tokens[i].substr(9, tokens[i].length()-1);
            string v = int_operation_parser(tokens[i+2], tokens[i+3], tokens[i+4]);
            mem[k] = v;
            i += 4;
        } else if (tokens[i].substr(0, 8) == "VARIABLE" && tokens[i+1] == "EQUAL" && tokens[i+2].substr(0, 5) == "INPUT") { // Assigning INPUT to VARIABLE
            string k = tokens[i].substr(9, tokens[i].length()-1);
            string v = take_input();
            mem[k] = v;
            i += 2;
        } else if (tokens[i].substr(0, 5) == "INPUT"){ // Input
            take_input();
            i += 1;
        } else if (tokens[i] == "TYPECONV" && tokens[i+1].substr(0, 8) == "VARIABLE" && tokens[i+2].substr(0, 4) == "TP:I") { // Type Converion Of Variable to Int
            string m = mem[tokens[i+1].substr(9, tokens[i+1].length()-1)];
            string v = get_val_str(m.substr(2, m.length()-1));
            bool is_valid_num = true;
            
            for(int i = 0; i < v.length(); i++){
                if(!isdigit(v[i])){
                    is_valid_num = false;
                    break;
                }
            }

            if(is_valid_num){
                mem[tokens[i+1].substr(9, tokens[i+1].length()-1)][0] = tokens[i+2][3];
            }
            else {
                cout << "Cannot Convert from Type:STRING to Type:INT";
                exit(EXIT_FAILURE);
            }
            
            i += 2;
        } else if (tokens[i] == "TYPECONV" && tokens[i+1].substr(0, 8) == "VARIABLE" && tokens[i+2].substr(0, 4) == "TP:S"){ // Type Conversion of Variable to String
            mem[tokens[i+1].substr(9, tokens[i+1].length()-1)][0] = tokens[i+2][3];
            i += 2;
        } else if (tokens[i] == "TYPECONV" && tokens[i+1].substr(0, 8) == "VARIABLE" && tokens[i+2].substr(0, 2) == "TP"){ // FlagNotSupported Error
            if(tokens[i+2].substr(3, tokens[i+1].length()-1) != "INT" || tokens[i+2].substr(3, tokens[i+1].length()-1) != "STRING"){
                cout << "Flag not supported\n";
                exit(EXIT_FAILURE);
            }
        } else if (tokens[i] == "LOOP" && tokens[i+1].substr(0, 5) == "VALUE"){ // Loop for VALUE no of times
            lf_ptr = i+1;
            
            if(get_val_int(tokens[i+1].substr(8, tokens[i+1].length()-1)) <= 0){ // Dont loop if value is less than 0
                i = occur(tokens, "LOOP_END", l_end_c+1);
            } else {
                loop_times = get_val_int(tokens[i+1].substr(8, tokens[i+1].length()-1))-1;
                i += 1;
            }
        } else if (tokens[i] == "LOOP" && tokens[i+1].substr(0, 8) == "VARIABLE"){ // Loop for VARIABLE'VALUE no of times
            string v = tokens[i+1].substr(9, tokens[i+1].length()-1);
            lf_ptr = i+1;

            if(get_val_int(mem[v].substr(2, mem[v].length()-1)) <= 0){ // Dont loop if value is less than 0
                i = occur(tokens, "LOOP_END", l_end_c+1);
            } else {
                loop_times = get_val_int(mem[v].substr(2, mem[v].length()-1))-1;
                i += 1;
            }
        } else if (tokens[i] == "LOOP_END"){ // ENDING LOOP
            if(loop_times > 0){
                i = lf_ptr;
                loop_times--;
            }
            l_end_c++;
        } else if (tokens[i].substr(0, 2) == "OP" && tokens[i+1].substr(0, 8) == "VARIABLE") { // Direct Variable Operations
            string k = tokens[i+1].substr(9, tokens[i+1].length()-1);
            string v = int_operation_parser(tokens[i], tokens[i+1], tokens[i+2]);
            mem[k] = v;
            i += 2;
        }
    }
}