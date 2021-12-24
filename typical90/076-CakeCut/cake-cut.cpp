/*
    076 - Cake Cut（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bx
        Author: Keitaro Naruse
        Date:   2021-12-23, 2021-12-24
        MIT License
*/

// # Solution
// - Read Ai and culculate the sum of Ai
// - if Ai > sum/10 Ai = 0
// - blocks are separated by 0

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Constant
    const long long M = 10LL;

    //  Read N
    int N = 0;
    std::cin >> N;

    //  Read Ai
    std::vector< long long > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        //  Debug
        // std::cerr << A.at( i ) << " ";
    }
    //  Debug
    // std::cerr << std::endl;


    //  Make Bi, the cumulative sum
    std::vector< long long > B( 2 * N, 0LL );
    B.at( 0 ) = A.at( 0 );
    for( int i = 1; i < N; i ++ ) {
        B.at( i ) = B.at( i - 1 ) + A.at( i ); 
    }
    for( int i = 0; i < N; i ++ ) {
        B.at( i + N ) = B.at( i - 1 + N ) + A.at( i ); 
    }
    for( int i = 0; i < 2 * N; i ++ ) {
        //  Debug
        // std::cerr << B.at( i ) << " ";
    }
    //  Debug
    // std::cerr << std::endl;
    
    //  Solution check
    long long sum = B.at( N - 1 );
    if( sum % M != 0LL ) {
        std::cout << "No" << std::endl;
        return( 0 );
    }
    long long sum_tenth = B.at( N - 1 ) / M;

    //  Main
    bool isYes = false;
    for( int L = 0; L < N; L ++ ) {
        long long BR = B.at( L ) + sum_tenth;
        if( *std::lower_bound( B.begin(), B.end(), BR ) == BR ) {
            isYes = true;
            break;
        }
    }

    //  Display result
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
