/*
    001 - Yokan Party（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_a
        Author: Keitaro Naruse
        Date:   2021-12-29
        MIT License
*/

//  # Solution

#include <iostream>
#include <vector>

const bool Debug = true;

int main()
{
    //  Initialize
    //  Read N and L
    int N = 0, L = 0;
    std::cin >> N >> L;
    if( Debug ) {
        std::cerr << N << " " << L << std::endl;
    }
    //  Read K
    int K = 0;
    std::cin >> K;
    if( Debug ) {
        std::cerr << K << std::endl;
    }
    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        if( Debug ) {
            std::cerr << A.at( i ) << "" << std::endl;
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    //  Main
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
