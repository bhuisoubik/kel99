#include "../../include/get_val_str.h"
string get_val_str(string s) {
    string n = "", val = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '|'){
            int acc = stoi(n);
            val += (char) acc; 
            n = "";
        }else{
            n += s[i];
        }
    }
    return val;
}

int get_val_int(string s){
    int val;
    try{
        val = stoi(get_val_str(s));
    } catch (exception& e){
        cout << "Cannot Convert From Type:STRING to Type:INT";
    }
    return val;
}