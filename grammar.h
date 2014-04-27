/* grammar.h
 * Classe que representa uma gramática.
 */
#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include <string>
#include "production.h"

class Grammar {
    std::string terminals;
    std::string start; // Símbolo inicial
    std::vector<Production> productions;

public:
    /* Constrói uma gramática com os valores especificados. */
    Grammar( std::string terminals, std::string start, 
            std::vector<Production> productions );

    /* Retorna um vetor com amount palavras que podem
     * ser geradas por esta gramática. */
    std::vector<std::string> generate( int amount );

    /* Determina se a forma sentencial sf é uma sentença,
     * dados os terminais especificados. */
    static bool sentence( std::string sf, std::string terminals );
};
#endif // GRAMMAR_H
