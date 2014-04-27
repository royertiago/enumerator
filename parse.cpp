/* parse.cpp
 * Implementação de parse.h */

#include <cstring>
#include "parse.h"

using std::strtok;
using std::vector;
using std::string;

vector<Production> Parse::productionList( char * str ) {
    vector<Production> prods;
    string left = strtok( str, " ->|" );

    char * lastStr;
    while( (lastStr = strtok( 0, " ->|" )) != nullptr )
        prods.push_back( Production( left, lastStr ) );

    return prods;
}
