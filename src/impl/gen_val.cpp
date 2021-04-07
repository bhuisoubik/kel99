#include "../../include/gen_val.h"

string gen_val(string s) {
    string val = "S-";
    for(int i = 0; i < s.length(); i++){
        int c = (int) s[i];
        val += to_string(c) + "|";
    }
    return val;
}

string gen_val(int s) {
    string val = gen_val(to_string(s));
    val[0] = 'I';
    return val;
}