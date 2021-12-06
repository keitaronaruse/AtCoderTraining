/*
    014 - We Used to Sing a Song Together（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_n
        Author: Keitaro Naruse
        Date:   2021-12-06
        MIT License
*/

// # Solution
// - Sort Ai, Sort Bi, i = 1,2,...,N
// - i = j

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    //  Debug
    // std::cerr << N << std::endl;

    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        //  Debug
        // std::cerr << A.at( i ) << " ";
    }
    // std::cerr << std::endl;

    //  Read Bi
    std::vector< int > B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
        //  Debug
        // std::cerr << B.at( i ) << " ";
    }
    // std::cerr << std::endl;

    //  Sort A and B
    std::sort( A.begin(), A.end() );
    std::sort( B.begin(), B.end() );
    long long inconvenience = 0LL;
    for( int i = 0; i < N; i ++ ) {
        inconvenience += ( long long )( A.at( i ) > B.at( i ) ) ? A.at( i ) - B.at( i ) : B.at( i ) - A.at( i );
    }
    std::cout << inconvenience << std::endl;

    // Debug
    // for( const auto& a : A ) {
    //     std::cerr << a << " ";
    // }
    // std::cerr << std::endl;

    // for( const auto& b : B ) {
    //     std::cerr << b << " ";
    // }
    // std::cerr << std::endl;    

    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
