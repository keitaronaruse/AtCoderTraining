/**
* @file abc246-a.cpp
* @brief ABC244 Problem A - Four Points
* @author Keitaro Naruse
* @date 2022-04-02
* @copyright MIT License
* @details https://atcoder.jp/contests/abc246/tasks/abc246_a
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Constant
    const int N = 3;

    //  Read Ai = [ 0, 10^9 ]
    std::vector< int > x( N + 1 ), y( N + 1 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> x.at( i ) >> y.at( i );
    }

    //  Main
    if( x.at( 0 ) == x.at( 1 ) ) {
        x.at( N ) = x.at( 2 );
    }
    else if( x.at( 1 ) == x.at( 2 ) ) {
        x.at( N ) = x.at( 0 );
    }
    else if( x.at( 2 ) == x.at( 0 ) ) {
        x.at( N ) = x.at( 1 );
    }

    if( y.at( 0 ) == y.at( 1 ) ) {
        y.at( N ) = y.at( 2 );
    }
    else if( y.at( 1 ) == y.at( 2 ) ) {
        y.at( N ) = y.at( 0 );
    }
    else if( y.at( 2 ) == y.at( 0 ) ) {
        y.at( N ) = y.at( 1 );
    }

    std::cout << x.at( N ) << " " << y.at( N ) << std::endl;

    //  Finalize
    return( 0 );
}
