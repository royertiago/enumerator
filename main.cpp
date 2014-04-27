/* main.cpp */

#include <string>
#include <vector>
#include <iostream>
#include "production.h"
#include "parse.h"

using std::vector;
using std::string;

using std::cin;
using std::cout;
using std::endl;

int main() {
    Production p( "AA", "" );
    vector<string> res = p.apply( "A" );
    for( string& str : res )
        cout << str << endl;

    return 0;
}
