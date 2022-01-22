/**
* @file abc133-a.cpp
* @brief ABC133 Problem A - Erase by Value
* @author Keitaro Naruse
* @date 2022-01-22
* @copyright MIT License
* @details https://atcoder.jp/contests/arc133/tasks/arc133_a
*/

// # Solution

#include <iostream>
#include <vector>

const bool Debug = false;

int main()
{
    //  Read N = [ 1, 200,000 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Ai = [ 1, N ]
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << A.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    //  Find the first i which satisfies Ai > Ai + 1 and set k = i
    int k = N - 1;
    for( int i = 0; i < N - 1; i ++ ) {
        if( A.at( i ) > A.at( i + 1 ) ) {
            k = i;
            break;
        }
    }
    if( Debug ) {
        std::cerr << "k: " << k << std::endl;
    }

    //  Find the solution
    for( int i = 0; i < N; i ++ ) {
        if( A.at( i ) != A.at( k ) ) {
            std::cout << A.at( i ) << " ";
        }
    }
    std::cout << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}

