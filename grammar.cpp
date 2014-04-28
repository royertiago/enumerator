/* grammar.cpp
 * Implementação de grammar.h
 */

#include <set>
#include <algorithm>
#include "grammar.h"

using std::set;
using std::vector;
using std::string;
using std::count_if;
using std::copy_if;

Grammar::Grammar( string Vt, string s, vector<Production> p ) :
    terminals( Vt ),
    start( s ),
    productions( p )
{}

bool Grammar::sentence( string sf, string t ) {
    return sf.find_first_not_of( t ) == string::npos;
}

// TODO: altamente ineficiente.
vector<string> Grammar::generate( int amount ) {
    auto isSentence = [this]( string str ) {
        return Grammar::sentence( str, terminals );
    };

    set<string> T; //Conjunto das formas sentencias geradas até agora
    set<string> Tp; //Conjunto das próximas formas sentenciais a serem geradas
    Tp.insert( start );

    int actual = 0;
    
    do {
        T = Tp;
        for( const string& str : T )
            for( Production& p : productions ) {
                vector<string> v = p.apply( str );
                Tp.insert( v.begin(), v.end() );
            }
        /* Aqui, todas as novas formas sentenciais já foram geradas.
         * Temos de contar quantas sentenças há entre elas. */
        actual = count_if( Tp.begin(), Tp.end(), isSentence );
    } while( actual < amount );

    vector<string> r( actual );
    copy_if( Tp.begin(), Tp.end(), r.begin(), isSentence );
    return r;
}
