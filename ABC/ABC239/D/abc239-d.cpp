/**
* @file abc239-d.cpp
* @brief ABC239 Problem D - Prime Sum Game 
* @author Keitaro Naruse
* @date 2022-02-19, 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc239/tasks/abc239_d
*/

// # Solution

#include <iostream>
#include <vector>

const bool Debug = false;

int main()
{
    const int N = 100;
    //  Read A, B, C, D = [ 1, 100 ]
    int A = 0, B = 0, C = 0, D = 0;
    std::cin >> A >> B >> C >> D;
    if( Debug ) {
        std::cerr << A << " " << B << " " << C << " " << D << std::endl;
    }
    
    //  Main
    //  Prime table
    std::vector< bool > prime( 2 * N + 1, true );
    prime.at( 0 ) = false;
    prime.at( 1 ) = false;
    for( int i = 2; i * i < 2 * N + 1; i ++ ) {
        for( int k = i + i; k < 2 * N + 1; k += i ) {
            prime.at( k ) = false;
        }
    }
    if( Debug ) {
        for( int i = 0; i < 2 * N + 1; i ++ ) {
            std::cerr << prime.at( i );
        }
        std::cerr << std::endl;
    }

    //  Primable table
    std::vector< std::vector< bool > > primable( N + 1, std::vector< bool >( N + 1, false ) );
    for( int i = A; i <= B; i ++ ) {
        for( int j = C; j <= D; j ++ ) {
            primable.at( i ).at( j ) = prime.at( i + j );
        }
    }
    if( Debug ) {
        for( int i = A; i <= B; i ++ ) {
            for( int j = C; j <= D; j ++ ) {
                std::cerr << primable.at( i ).at( j );
            }
            std::cerr << std::endl;
        }
    }

    //  Judge
    bool isTakahashiWinnable = false;
    for( int i = A; i <= B; i ++ ) {
        bool isAokiWinnable = false;
        for( int j = C; j <= D; j ++ ) {
            if( primable.at( i ).at( j ) ) {
                isAokiWinnable = true;
            }
        }
        if( !isAokiWinnable ) {
            isTakahashiWinnable = true;
            break;
        }
    }
    if( isTakahashiWinnable ) {
        std::cout << "Takahashi" << std::endl;
    }
    else {
        std::cout << "Aoki" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
