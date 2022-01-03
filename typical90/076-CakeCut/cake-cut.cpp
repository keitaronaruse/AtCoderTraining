/*
    076 - Cake Cut（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bx
        Author: Keitaro Naruse
        Date:   2021-12-23, 2022-01-03
        MIT License
*/

// # Solution
// - Read Ai and culculate Bi, the cumulative sum of Ai
// - Because the cumulative sum is a sorted sequence, 
// - we can find the sum / 10 by the binary search

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Constant
    const long long M = 10LL;

    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Read Ai
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        if( Debug ) {
            std::cerr << A.at( i ) << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    //  Make Bi, the cumulative sum
    std::vector< long long > B( 2 * N, 0LL );
    B.at( 0 ) = A.at( 0 );
    for( int i = 1; i < N; i ++ ) {
        B.at( i ) = B.at( i - 1 ) + A.at( i ); 
    }
    for( int i = 0; i < N; i ++ ) {
        B.at( i + N ) = B.at( i - 1 + N ) + A.at( i ); 
    }
    if( Debug ) {
        for( int i = 0; i < 2 * N; i ++ ) {
            std::cerr << B.at( i ) << " ";
        }
        std::cerr << std::endl;
    }
    
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
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
