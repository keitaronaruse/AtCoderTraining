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
#include <vector>
#include <set>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    //  Debug
    std::cerr << N << std::endl;

    //  Main
    //  Make right words
    std::vector< std::set< std::string > > words( N/2 );

    //  Axiom: N == 2, i == 0
    words.at( 0 ).insert( "()" );
    for( int i = 1; i != N / 2; i++ ) {
        //  N == 4, i == 1, S4
        //  (S2)
        //  (j = 0; j != i == 1; j++) 
        //  j == 0(S2), k != i-j-1 == 1-0-1 == 0(S2) 
        //  S2S2
        
        //  N == 6, i == 2, S6
        //  (S4)
        //  (j = 0; j != i == 2; j++) 
        //  j == 0(S2), k != i-j-1 == 2-0-1 == 1(S4) 
        //  S2S4
        //  j == 1(S4), k != i-j-1 == 2-1-1 == 0(S2) 
        //  S4S2

        //  N == 8, i == 3
        //  (S6)
        //  (j = 0; j != i == 3; j++) 
        //  j == 0(S2), k != i-j-1 == 3-0-1 == 2(S6) 
        //  S2S6
        //  j == 1(S4), k != i-j-1 == 3-1-1 == 1(S4) 
        //  S4S4
        //  j == 2(S4), k != i-j-1 == 3-2-1 == 0(S2) 
        //  S6S2
    }

    //  Display result
    if( N % 2 == 0) {
        //  Display output
        for( const auto& e : words.at( N / 2 - 1) ) {
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
