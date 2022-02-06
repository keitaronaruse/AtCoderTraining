/**
* @file abc238-b.cpp
* @brief ABC238 Problem B - Pizza
* @author Keitaro Naruse
* @date 2022-02-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc238/tasks/abc238_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 359 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read Aij
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        std::cerr << A << std::endl;
    }

    //  Main
    int sum = 0;
    for( int i = 0; i < N; i ++ ) {
        sum += A.at( i );
    }
    const int Deg = 360;
    std::vector< int > B( N + 2, 0 );
    B.at( N ) = A.at( N - 1 );
    for( int i = N - 1; i >= 1; i -- ) {
        B.at( i ) = B.at( i + 1 ) + A.at( i - 1 );
    }
    if( Debug ) {
        std::cerr << B << std::endl;
    }

    for( int i = 1; i <= N; i ++ ) {
        B.at( i ) %= Deg;
    }
    if( Debug ) {
        std::cerr << B << std::endl;
    }

    B.at( 0 ) = 0;
    B.at( N + 1) = 360;
    std::sort( B.begin(), B.end() );
    if( Debug ) {
        std::cerr << B << std::endl;
    }

    //  Find the solution
    int max_interval = 0;
    for( int i = 1; i <= N + 1; i ++ ) {
        if( B.at( i ) - B.at( i - 1 ) > max_interval ) {
            max_interval = B.at( i ) - B.at( i - 1 );
        };
    }
    std::cout << max_interval << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
