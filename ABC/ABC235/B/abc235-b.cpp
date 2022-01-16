/*
    ABC235 Problem B - Climbing Takahashi
        https://atcoder.jp/contests/abc235/tasks/abc235_b
        Author: Keitaro Naruse
        Date:   2022-01-15
        MIT License
*/

// # Solution
// - Move until thecondition is not satisfied

#include <iostream>
#include <vector>

const bool Debug = false;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Hi
    std::vector< int > H( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> H.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << H.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    int pos = 0;
    while( H.at( pos ) < H.at( pos + 1 ) ) {
        pos ++;
        if( pos >= N - 1 ) {
            break;
        }
    }
    //  Display the result
    std::cout << H.at( pos ) << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
