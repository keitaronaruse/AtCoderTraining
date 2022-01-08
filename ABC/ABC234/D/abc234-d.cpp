/*
    ABC234 Problem D - Prefix K-th Max
        https://atcoder.jp/contests/abc234/tasks/abc234_d
        Author: Keitaro Naruse
        Date:   2022-01-08
        MIT License
*/

// # Solution
// - 

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

const bool Debug = true;

int main()
{
    //  Read N and K
    int N = 0, K = 0;
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }
    //  Read Pi
    std::vector< int > P( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> P.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << P.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    //  Take the first K
    std::sort( P.begin(), P.begin() + K, std::greater< int >{} );
    std::list< int > H( P.begin(), P.begin() + K  );
    if( Debug ) {
        for( auto h : H ) {
            std::cerr << h << " ";
        }
        std::cerr << std::endl;
    }
    std::cout << *( H.end() -- ) << std::endl;

    for( int i = 1; i < N - K ; i ++ ) {
        for( std::list< int >::iterator it = H.begin(); it != H.end(); it ++ ) {
            if( *it < P.at( K + i ) ) {
                it = H.insert( it, P.at( K + i ) );
                H.pop_back();
            }
        }
        if( Debug ) {
            for( auto h : H ) {
                std::cerr << h << " ";
            }
            std::cerr << std::endl;
        } 
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
