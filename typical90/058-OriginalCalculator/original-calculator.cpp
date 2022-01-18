/*
    058 - Original Calculator（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_bf
        Author: Keitaro Naruse
        Date:   2022-01-18
        MIT License
*/

// # Solution
// - Make counter by the associative memory

#include <iostream>
#include <map>
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
    //  Read H and K
    int N = 0;
    long long K = 0LL; 
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }

    //  Main
    //  { x, z }
    std::map< int, int > counter;
    //  Initial value
    int x = N, y = 0, z = 0;
    for( long long k = 0LL; k < K; k ++ ) {
        if( counter.count( x ) == 0 ) {
            y = find_y( x );
            z = ( x + y ) % 100000;
            counter[ x ] = z;
        }
        else {
            z = counter[ x ];
        }
        x = z;
    }

    // Display result
    std::cout << x << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
