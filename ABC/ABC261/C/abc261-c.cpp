/**
 * @file abc261-c.cpp
 * @brief ABC261 Problem C - NewFolder(1)
 * @author Keitaro Naruse
 * @date 2022-07-23
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc261/tasks/abc261_c
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main( ) {
    //  Read N = [ 2, 2*10^5 ]
    int N;
    std::cin >> N;

    //  Read  | Si | = [ 1, 10 ]
    std::vector< std::string > S( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> S.at( i );
    }

    //  Main
    //  Preprocess
    std::map< std::string, int > counter;
    for( int i = 0; i < N; i++ ) {
        if( counter.count( S.at( i ) ) == 0 ) {
            std::cout << S.at( i ) << std::endl;
        } else {
            std::cout << S.at( i ) << "("
                      << std::to_string( counter.at( S.at( i ) ) ) << ")"
                      << std::endl;
        }
        counter[ S.at( i ) ]++;
    }

    //  Finalize
    return ( 0 );
}
