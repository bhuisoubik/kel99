#include "../../include/cli.hpp"
#define VERSION "1.0.0"
void cli(char *file) {
    if(file == NULL){
        cout << "kelc: fatal error: invalid argument or file not found\n";
        cout << "exit code (" << EXIT_FAILURE << ")";
        exit(EXIT_FAILURE);
    } else if (file == "-v" || file == "version"){
        cout << "KELC Version: " << VERSION << "\n";
    } else {
        string data;
        ifstream read_file(file);
        if(read_file) {
            ostringstream ss;
            ss << read_file.rdbuf();
            data = ss.str();
        }
        run(data);
    }
}