#include "../../include/input.h"
#include "../../include/gen_val.h"

string take_input() {
    string in;
    getline(cin, in);
    return gen_val(in);
}