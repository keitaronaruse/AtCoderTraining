/*
    058 - Original Calculator（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_bf
        Author: Keitaro Naruse
        Date:   2022-01-18, 2022-01-19
        MIT License
*/

// # Solution
// - Make counter

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

int find_y( int x ) 
{
    int y = 0;
    int d = 10000;
    for( int k = 0; k < 5; k ++ ) {
        y += x / d;
        x %= d;
        d /= 10;
    }
    return( y );
}

int main()
{
    //  Constants
    const int M = 100000;
    
    //  Read H and K
    int N = 0;
    long long K = 0LL; 
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }

    //  Main
    //  next[ x ] = z;
    std::vector< int > next( M, -1 );
    //  Make the next table: next: x -> z
    for( int x = 0; x < M; x ++ ) {
        next.at( x ) = ( x + find_y( x ) ) % M;
    }
    
    //  order[ x ] = k
    std::vector< int > order( M, -1 );
    //  Find cycle
    int x = N, count = 0;
    while( order.at( x ) == -1 ) {
        order.at( x ) = count;
        x = next.at( x );
        count ++;
    }
    int cycle = count - order.at( x );

    int k = 0;
    if( K < ( long long ) count ) {
        k = ( int ) K;
    }
    else {
        k = ( int ) ( ( K - ( long long ) order.at( x ) ) % ( long long ) cycle ) + order.at( x );
    }

    //  Display result
    for( int i = 0; i < M; i ++ ) {
        if( order.at( i ) == k ) {
            std::cout << i << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
