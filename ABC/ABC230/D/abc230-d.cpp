/*
    ABC230 Problem D - Destroyer Takahashi
        https://atcoder.jp/contests/abc230/tasks/abc230_d
        Author: Keitaro Naruse
        Date:   2022-01-10
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = true;

int main()
{
    //  Read N and K
    int N = 0, D = 0;
    std::cin >> N >> D;
    if( Debug ) {
        std::cerr << N << " " << D << std::endl;
    }
    //  Read Li and Ri
    std::vector< int > L( N, 0 ), R( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> L.at( i ) >> R.at( i );
        if( Debug ) {
            std::cerr << L.at( i ) << " " << R.at( i ) << std::endl;
        }
        L.at( i ) --;
        R.at( i ) --;
    }

    //  Main
    std::vector< int > B = R;
    std::sort( B.begin(), B.end() );
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << B.at( i ) + 1 << std::endl;
        }
    }
    int head  = 0;
    //  Puch at B[head]
    B.at( head ) + D;
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
