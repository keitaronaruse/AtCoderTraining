/*
    002 - Encyclopedia of Parentheses（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_b
        Author: Keitaro Naruse
        Date:   2021-12-02
        MIT License
*/

// # Solution

#include <iostream>
#include <string>
#include <list>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    //  Debug
    std::cerr << N << std::endl;

    //  Main
    if( N % 2 == 0 ) {
        //  valide case
        std::list< std::string > words;
        std::string word;
        if( N == 2 ) {
            word = "()";
            words.push_back( word );
        }
        //  Display output
        for( const auto& e : words ) {
            std::cout << e << std::endl;
        }
    }
    else {
        //  No valid sequence
        //  Display nothing
        std::cout << std::endl;
    }


    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
