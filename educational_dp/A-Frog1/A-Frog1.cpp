/**
* @file A-Frog1.cpp
* @brief A - Frog 1
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_a
*/

#include <iostream>
#include <vector>
#include <algorithm>

namespace nrs {
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 )? a : -a );
    }
}

const bool Debug = false; 

int main()
{
    //  Read N = [ 2, 100,000 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Read Hi = [ 1, 10,000 ]
    std::vector< int > h( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> h.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << h.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    //  Main::Initialize
    //  dp table: 
    //  - size: N
    //  - value: N * h = 10^5 * 10^4 = 10^9 -> int 
    //  - dp_cost.at( i ) is the minimum of 
    //    - dp_cost.at( i - 1 ) + cost( i, i - 1), or
    //    - dp_cost.at( i - 2 ) + cost( i, i - 2) 
    std::vector< int > dp_cost( N, -1 );
    
    //  Initail boundary condition
    //  The frog is at the stone 1 with 0 cost
    dp_cost.at( 0 ) = 0;
    //  The frog moves to the stone 2 with the following cose
    dp_cost.at( 1 ) = nrs::abs( h.at( 1 ) - h.at( 0 ) );
    //  Main::Loop
    for( int i = 2; i < N; i ++ ) {
        dp_cost.at( i ) = std::min(
            dp_cost.at( i - 1 ) + nrs::abs( h.at( i ) - h.at( i - 1 ) ),
            dp_cost.at( i - 2 ) + nrs::abs( h.at( i ) - h.at( i - 2 ) )
        );
    }
    //  Main::Finalize
    //  Display the result
    std::cout << dp_cost.at( N - 1 ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
