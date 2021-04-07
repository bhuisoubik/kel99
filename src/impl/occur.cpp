#include "../../include/occur.h"

int occur(vector<string> vec, string find, int n){
    int cnt = 0, val = 0;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == find){
            cnt++;
        }
        
        if(cnt == n && vec[i] == find) {
            val = i;
        }
    }
    return val;
}