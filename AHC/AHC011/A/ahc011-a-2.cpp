/**
 * @file ahc011-a-2.cpp
 * @brief AHC011 Problem A - Sliding Tree Puzzle
 * @author Keitaro Naruse
 * @date 2022-06-05
 * @copyright MIT License
 * @details https://atcoder.jp/contests/ahc011/tasks/ahc011_a
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

template < class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p ) {
    os << "( " << p.first << ", " << p.second << " )";
    return ( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os,
                          const std::vector< std::vector< T > >& vv ) {
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return ( os );
}

int score_board( const std::vector< std::vector< char > >& board ) {
    int n = ( int ) board.size( );
    std::vector< std::vector< int > > score( n, std::vector<int>( n, 1 ) );
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            int mask;
            if( '0' <= board.at( i ).at( j ) && board.at( i ).at( j ) <= '9' ) {
                mask = board.at( i ).at( j ) - '0';
            }
            else {
                mask = board.at( i ).at( j ) - 'a' + 10;
            }
            
            //  Left connector
            if( mask & 1 != 0) {
                if( i >= 1 ) {
                    ;
                }
            }
            //  Up connector
            if( mask & 2 != 0) {
                ;
            }
            //  Right connector
            if( mask & 4 != 0) {
                ;
            }
            //  Down connector
            if( mask & 8 != 0) {
                ;
            }
        }
    }
}

int main( ) {
    //  Read N = [ 6, 10 ], T = 2 * N^3
    int N, T;
    std::cin >> N >> T;

    //  Read tij
    int pi, pj;
    std::vector< std::vector< char > > t( N, std::vector< char >( N, ' ' ) );
    for( int i = 0; i < N; i++ ) {
        for( int j = 0; j < N; j++ ) {
            std::cin >> t.at( i ).at( j );
            if( t.at( i ).at( j ) == '0' ) {
                pi = i;
                pj = j;
            }
        }
    }

    //  Main
    //  Preprocess: analyze the pieces
    std::map< char, int > pieces;
    for( int i = 0; i < N; i++ ) {
        for( int j = 0; j < N; j++ ) {
            pieces[ t.at( i ).at( j ) ]++;
        }
    }

    //  Find the solution
    while( !( pi == N - 1 && pj == N - 1 ) ) {
        if( pi < N - 1 ) {
            std::cout << "D";
            pi++;
        } else if( pj < N - 1 ) {
            std::cout << "R";
            pj++;
        }
    }
    std::cout << std::endl;

    for( const auto& p : pieces ) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    //  Finalize
    return ( 0 );
}
