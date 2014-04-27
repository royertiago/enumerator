/* production.cpp
 * Implementação de production.h */

#include "production.h"
using std::string;
using std::ostream;

Production::Production( string l, string r ) :
    left( l ),
    right( r )
{}

ostream& operator<<( ostream& os, const Production& prod ) {
    return (os << prod.left << " -> " << prod.right);
}
