/* production.h
 * Classe que representa as produções de uma gramática.
 */
#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <string>
#include <ostream>
#include <vector>

class Production {
    std::string left; //Lado direito da produção
    std::string right; //Lado esquerdo da produção

public:
    /* Constrói uma produção a partir das strings passadas. */
    Production( std::string left, std::string right );

    Production( const Production& ) = default;
    Production( Production&& ) = default;
    Production& operator=( const Production& ) = default;
    Production& operator=( Production&& ) = default;

    /* Retorna o resultado da aplicação desta produção,
     * de todas as formas possíveis, uma única vez,
     * na string passada.
     *
     * Caso não seja possível aplicar a produção, um vetor
     * vazio é retornado. */
    std::vector<std::string> apply( std::string );

    /* Imprime a produção. Formato: left -> right
     * Não imprime fim de linha. */
    friend std::ostream& operator<<( std::ostream&, const Production& );
};
#endif // PRODUCTION_H
