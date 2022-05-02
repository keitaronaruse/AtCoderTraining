/**
 * @file arc130-a.cpp
 * @brief ARC131 Problem A - Remove One Character
 * @author Keitaro Naruse
 * @date 2022-05-03
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc130/tasks/arc130_a
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>

int main( ) {
    //  Read N = [ 2, 3*10^5 ]
    int N;
    std::cin >> N;
    //  Read S
    std::string S;
    std::cin >> S;

    //  Main
    //  Preprocess
    std::vector< int > cont_nums;
    char prev_letter = S.at( 0 );
    int cont_letters = 1;
    for( int i = 1; i < N; i++ ) {
        if( S.at( i ) == prev_letter ) {
            cont_letters++;
        } else {
            if( cont_letters >= 2 ) {
                cont_nums.push_back( cont_letters );
            }
            prev_letter = S.at( i );
            cont_letters = 1;
        }
    }
    if( cont_letters >= 2 ) {
        cont_nums.push_back( cont_letters );
    }

    //  Find the solution
    long long answer = 0LL;
    for( auto k : cont_nums ) {
        answer += ( ( long long ) k * ( long long ) ( k - 1 ) / 2LL );
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
