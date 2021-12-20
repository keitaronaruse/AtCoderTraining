/*
    ABC232 Problem C
        https://atcoder.jp/contests/abc232
        Author: Keitaro Naruse
        Date:   2021-12-19
        MIT License
*/

// # Solution
// - 

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N and M
    int N = 0, M = 0;
    std::cin >> N >> M;

    //  Read A and B, and make adjacents
    std::vector< int > A( M, 0 ), B( M, 0 );
    std::vector< std::vector< int > > adj_AB( N );
    for( int i = 0; i < M; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
        adj_AB.at( A.at( i ) - 1 ).push_back( B.at( i ) - 1 );
        adj_AB.at( B.at( i ) - 1 ).push_back( A.at( i ) - 1 );
    }

    //  Read C and D
    std::vector< int > C( M,0 ), D( M, 0 );
    std::vector< std::vector< int > > adj_CD( N );
    for( int i = 0; i < M; i ++ ) {
        std::cin >> C.at( i ) >> D.at( i );
        adj_CD.at( C.at( i ) - 1 ).push_back( D.at( i ) - 1 );
        adj_CD.at( D.at( i ) - 1 ).push_back( C.at( i ) - 1 );
    }

    //  Main
    std::vector< int > P;
    for( int j = 0; j < N; j ++ ) {
        P.push_back( j );
    }

    do {
        bool isYes = true;
        for( int i = 0; i < N; i ++ ) {
            if( adj_AB.at( P.at( i ) ).size() != adj_CD.at( i ).size() ) {
                isYes = false;
                break;
            }
            for( auto v : adj_AB.at( P.at( i ) ) ) {
                if( std::find( 
                    adj_CD.at( i ).begin(), 
                    adj_CD.at( i ).end(), 
                    P.at( v ) ) == adj_CD.at( i ).end() 
                ) {
                    isYes = false;
                    break;
                }                
            }
        }

        if( isYes ) {
            std::cout << "Yes" << std::endl;
            return( 0 );
        }
    } while( std::next_permutation( P.begin(), P.end() ) );

    //  Display result
    std::cout << "No" << std::endl;
 
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
