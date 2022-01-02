/*
    003 - Longest Circular Road（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_c
        Author: Keitaro Naruse
        Date:   2022-01-02
        MIT License
*/

#include <iostream>
#include <vector>
const bool Debug = true;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    
    //  Read A and B
    std::vector< int > A( N ), B( N );
    for( int i = 0; i < N - 1; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
        if( Debug ) {
            std::cerr << A.at( i ) << " " << B.at( i ) << std::endl;
        }
    }

    //  Main

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
