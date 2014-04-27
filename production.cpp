/* production.cpp
 * Implementação de production.h */

#include "production.h"
using std::string;
using std::ostream;
using std::vector;

Production::Production( string l, string r ) :
    left( l ),
    right( r )
{}

vector<string> Production::apply( string a ) {
    vector<string> r;
    size_t last = 0;
    while( (last = a.find(left, last)) != string::npos ) {
        string b = a.substr( 0, last );
        b += right;
        b += a.substr( last + left.size(), string::npos );
        /* a deriva b em um passo usando esta produção. */
        r.push_back( b );
        ++last;
    }
    return r;
}

ostream& operator<<( ostream& os, const Production& prod ) {
    return (os << prod.left << " -> " << prod.right);
}
