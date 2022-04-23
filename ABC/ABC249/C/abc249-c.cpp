/**
* @file abc249-c.cpp
* @brief ABC249 Problem C - Just K
* @author Keitaro Naruse
* @date 2022-04-23, 2022-04-24
* @copyright MIT License
* @details https://atcoder.jp/contests/abc249/tasks/abc249_c
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > > & vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 15 ], K = [ 1, N ]
    int N, K;
    std::cin >> N >> K;

    //  Read Si
    std::vector< std::string > S( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> S.at( i );
    }

    //  Main
    //  Preprocess
    const int Z = 26;
    //  Make the tables of the number of alphabets
    std::vector< std::vector< int > > num_alpha( N, std::vector< int >( Z, 0 ) );
    for( int i = 0; i < N; i ++ ) {
        for( size_t j = 0; j < S.at( i ).size(); j ++ ) {
            num_alpha.at( i ).at( S.at( i ).at( j ) - 'a' ) ++;
        }
    }

    //  Search
    int max_appear = 0;
    int M = 1 << N;
    //  For each of combinations
    for( int k = 1; k < M; k ++ ) {
        //  Calculate the sum of the number of the alphabet appearance
        int b = 1;
        std::vector< int > sum_alpha( Z, 0 );
        for( int i = 0; i < N; i ++ ) {
            if( ( k & b ) == b ) {
                for( int j = 0; j < Z; j ++ ) {
                    sum_alpha.at( j ) += num_alpha.at( i ).at( j );
                }
            }
            b *= 2;
        }

        //  Find the number of the alphapets appeared exactly the K times
        int num_appear = 0;
        for( int j = 0; j < Z; j ++ ) {
            if( sum_alpha.at( j ) == K ) {
                num_appear ++;
            }
        }
        max_appear = std::max( max_appear, num_appear );
    }
    std::cout << max_appear << std::endl;

    //  Finalize
    return( 0 );
}
