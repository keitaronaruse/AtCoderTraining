/**
 * @file arc140-a.cpp
 * @brief ARC140 Problem A - Right String
 * @author Keitaro Naruse
 * @date 2022-05-15, 2022-06-05
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc140/tasks/arc140_a
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <map>

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

int hamming_dist( const std::string& s, const std::string& t ) {
    int dist = 0;
    for( int i = 0; i < s.size( ); i++ ) {
        if( s.at( i ) != t.at( i ) ) {
            dist++;
        }
    }
    return ( dist );
}

int main( ) {
    //  Read N = [ 1, 2*10^3 ], K = [ 1, N ]
    int N, K;
    std::cin >> N >> K;

    //  Read | S | = [ 1, 2*10^3 ]
    std::string S;
    std::cin >> S;

    //  Main
    int answer = 0;
    for( int k = 1; k <= N; k++ ) {
        if( N % k == 0 ) {
            int num_changes = 0;
            for( int j = 0; j < k; j++ ) {
                const int Z = 26;
                std::vector< int > counter( Z, 0 );
                int max_char = 0;
                int max_idx = 0;
                for( int i = j; i < N; i += k ) {
                    counter.at( S.at( i ) - 'a' )++;
                    if( max_char < counter.at( S.at( i ) - 'a' ) ) {
                        max_char = counter.at( S.at( i ) - 'a' );
                        max_idx = S.at( i ) - 'a';
                    }
                }
                for( int z = 0; z < Z; z ++ ) {
                    if( z != max_idx ) {
                        num_changes += counter.at( z );
                    }
                } 
            }
            if( num_changes <= K ) {
                answer = k;
                break;
            }
        }
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
