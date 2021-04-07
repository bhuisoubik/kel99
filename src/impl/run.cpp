#include "../../include/run.h"
#include "../../include/lexer.h"
#include "../../include/parser.h"

void run(string src) {
    parser(lexer(src));
}