/*
    034 - There are few types of elements（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_ah
        Author: Keitaro Naruse
        Date:   2022-01-07
        MIT License
*/

// # Solution
// - Caliculate by IMOS method

#include <iostream>
#include <vector>
#include <map>

const bool Debug = true;

int main()
{
    //  Read N and K
    int N = 0, K = 0;
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }

    //  Main
    std::vector< int > A( N );
    std::map< int, int > C;
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        if( Debug ) {
            std::cerr << A.at( i ) << " ";
        }
        C[ A.at(i) ] ++;
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    if( Debug ) {
        for( auto c : C ) {
            std::cerr << c.first << " " << c.second << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
