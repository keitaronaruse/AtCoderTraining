/**
* @file abc219-d.cpp
* @brief ABC219 Problem D - Strange Lunchbox
* @author Keitaro Naruse
* @date 2022-04-14, 2022-04-19
* @copyright MIT License
* @details https://atcoder.jp/contests/abc219/tasks/abc219_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N = [ 1, 300 ], X, Y = [ 1, 300 ]
    int N, X, Y;
    std::cin >> N >> X >> Y;
    //  Read Ai, Bi = [ 1, 300 ]
    std::vector< int > A( N + 1 ), B( N + 1 );
    for( int i = 1; i <= N; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    } 

    //  Main
    //  dp.at( i = N ).at( j = X ).at( l = Y )
    const int inf = N + 1;
    std::vector< std::vector< std::vector< int > > > dp( N + 1, 
        std::vector< std::vector< int > >( X + 1, std::vector< int >( Y + 1, inf ) ) );
    
    //  Initial boundary
    dp.at( 0 ).at( 0 ).at( 0 ) = 0;
    //  Loop
    for( int i = 1; i <= N; i ++ ) {
        for( int j = 0; j <= X; j ++ ) {
            for( int k = 0; k <= Y; k ++ ) {
                //  If he buys the i-th lunch box
                int u = std::min( j + A.at( i ), X );
                int v = std::min( k + B.at( i ), Y );
                dp.at( i ).at( u ).at( v ) = std::min( 
                    dp.at( i ).at( u ).at( v ), 
                    dp.at( i - 1 ).at( j ).at( k ) + 1 
                ); 
                //  If he does not
                dp.at( i ).at( j ).at( k ) = std::min( 
                    dp.at( i ).at( j ).at( k ), 
                    dp.at( i - 1 ).at( j ).at( k ) 
                ); 
            }
        }
    }
    int answer = dp.at( N ).at( X ).at( Y );
    if( answer == inf ) {
        answer = -1;
    }
    std::cout << answer << std::endl;

    //  Finalize
    return( 0 );
}
