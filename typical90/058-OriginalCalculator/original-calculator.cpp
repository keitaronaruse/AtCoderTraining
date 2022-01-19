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
    //  Initial value
    int x = N, y = 0, z = 0;
    //  dictionary.at( x ) = position
    std::vector< int > dictionary( M, -1 );
    //  Find cycle
    dictionary.at( x ) = 0;
    for( int k = 0; k < M; k ++ ) {
        y = find_y( x );
        z = ( x + y ) % M;
        if( dictionary.at( z ) == -1 ) {
            dictionary.at( z ) = dictionary.at( x ) + 1;
            x = z;
        }
        else {
            break;
        }
    }
    if( Debug ) {
        std::cerr << "x: ( " << x << ", " << dictionary.at( x ) << " )" <<std::endl;
        std::cerr << "z: ( " << z << ", " << dictionary.at( z ) << " )" <<std::endl;
    }

    // Display result
    long long cycle_start = dictionary.at( z );
    long long cycle_end = dictionary.at( x );
    long long cycle_length = cycle_end - cycle_start + 1LL;

    if( cycle_length == 1LL ) {
        std::cout << N << std::endl;
    }
    else {
        int k = 0;
        if( cycle_end >= K ) {
            k = ( int ) K;
        }
        else {
            k = ( int ) ( ( K - cycle_end ) % cycle_length + cycle_start ) - 1;
        }
        auto it = std::find( dictionary.begin(), dictionary.end(), k );
        std::cout << it - dictionary.begin() << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
