/* grammar.cpp
 * Implementação de grammar.h
 */

#include <set>
#include <algorithm>
#include <iterator>
#include "grammar.h"

#include <stdio.h>

using std::set;
using std::vector;
using std::string;
using std::copy_if;
using std::back_inserter;

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

    vector<string> sentences; //Lista a ser retornada
    set<string> T; //Conjunto das formas sentencias geradas até agora
    set<string> Tp; //Conjunto das próximas formas sentenciais a serem geradas
    Tp.insert( start );

    do {
        T = Tp;
        Tp.clear();
        for( const string& str : T )
            for( Production& p : productions ) {
                vector<string> v = p.apply( str );
                Tp.insert( v.begin(), v.end() );
            }
        /* Aqui, todas as novas formas sentenciais já foram geradas.
         * Adicionemos as sentenças formadas à lista oficial: */
        copy_if( Tp.begin(), Tp.end(), back_inserter(sentences), isSentence );
    } while( (int) sentences.size() < amount );

    return sentences;
}
