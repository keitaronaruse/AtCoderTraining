/**
* @file arc135-b.cpp
* @brief ARC135 Problem B
* @author Keitaro Naruse
* @date 2022-02-15
* @copyright MIT License
* @details https://atcoder.jp/contests/arc135/tasks/arc135_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = true;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 3 * 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read Si
    std::vector< int > S( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> S.at( i );
    }
    if( Debug ) {
        std::cerr << S << std::endl;
    }

    //  Main
    //  Make Xi
    std::vector< int > X( N + 2, 0 );
    X.at( 0 ) = 0;
    X.at( 1 ) = 0;
    for( int i = 2; i < N + 2; i ++ ) {
        X.at( i ) = S.at( i - 2 ) - X.at( i - 1 ) - X.at( i - 2 );
    }
    if( Debug ) {
        std::cerr << X << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
