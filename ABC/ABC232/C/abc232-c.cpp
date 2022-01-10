/*
    ABC232 Problem C - Graph Isomorphism
        https://atcoder.jp/contests/abc232/tasks/abc232_c
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-10
        MIT License
*/

// # Solution
// - Represent two graphs  as adjacent matricies of AB and CD
// - Permutation of the index of AB to the one of CD

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Read N and M
    int N = 0, M = 0;
    std::cin >> N >> M;
    if( Debug ) {
        std::cerr << N << " " << M << std::endl;
    }

    //  Read A and B, and make the adjacent matrix AB
    std::vector< std::vector< bool > > AB( N, std::vector< bool >( N, false ) );
    for( int i = 0; i < M; i ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        if( Debug ) {
            std::cerr << A << " " << B << std::endl;
        }
        A --;
        B --;
        AB.at( A ).at( B ) = true;
        AB.at( B ).at( A ) = true;
    }

    //  Read C and D, and make the adjacent matrix CD
    std::vector< std::vector< bool > > CD( N, std::vector< bool >( N, false ) );
    for( int i = 0; i < M; i ++ ) {
        int C = 0, D = 0;
        std::cin >> C >> D;
        if( Debug ) {
            std::cerr << C << " " << D << std::endl;
        }
        C --;
        D --;
        CD.at( C ).at( D ) = true;
        CD.at( D ).at( C ) = true;
    }

    //  Main
    std::vector< int > P;
    for( int j = 0; j < N; j ++ ) {
        P.push_back( j );
    }

    do {
        bool isYes = true;
        if( Debug ) {
            for( int j = 0; j < N; j ++ ) {
                std::cerr << "(" << j << "," << P.at( j ) << ") ";
            }
            std::cerr << std::endl;
        }
        //  Match the two adjacent matrices of AB and CD
        for( int j = 0; ( j < N ) && isYes; j ++ ) {
            for( int k = 0; ( k < N ) && isYes; k ++ ) {
                if( AB.at( j ).at( k ) != CD.at( P.at( j ) ).at( P.at( k ) ) ) {
                    //  Unmatch
                    isYes = false;
                }
            }
        }
        if( isYes ) {
            if( Debug ) {
                for( int j = 0; j < N; j ++ ) {
                    std::cerr << "(" << j << "," << P.at( j ) << ") ";
                }
                std::cerr << std::endl;
            }
            std::cout << "Yes" << std::endl;
            return( 0 );
        }
    } while( std::next_permutation( P.begin(), P.end() ) );

    //  Display result
    std::cout << "No" << std::endl;
 
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
