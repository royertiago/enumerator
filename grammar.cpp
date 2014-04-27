/* grammar.cpp
 * Implementação de grammar.h
 */

#include <set>
#include "grammar.h"

using std::set;
using std::vector;
using std::string;

Grammar::Grammar( string Vt, string s, vector<Production> p ) :
    terminals( Vt ),
    start( s ),
    productions( p )
{}

bool Grammar::sentence( string sf, string t ) {
    return sf.find_first_not_of( t ) == string::npos;
}
