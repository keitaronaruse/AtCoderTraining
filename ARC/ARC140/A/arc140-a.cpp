/**
 * @file arc140-a.cpp
 * @brief ARC140 Problem A - Right String
 * @author Keitaro Naruse
 * @date 2022-05-15
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc140/tasks/arc140_a
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <set>

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
    std::vector< std::string > dict( N );
    std::string s = S, t = s;
    for( int i = 0; i < N; i++ ) {
        dict.at( i ) = t;
        t = t.substr( 1, N - 1 ) + t.substr( 0, 1 );
    }

    std::vector< int > dist( N, 0 );
    int sum_dist = 0;
    for( int i = 1; i < N; i++ ) {
        dist.at( i ) = hamming_dist( dict.at( 0 ), dict.at( i ) );
        sum_dist += dist.at( i );
    }

    int answer = 0;
    for( int k = 0; sum_dist != 0 && k < K; k++ ) {
        int idx_dist2 = -1;
        for( int i = 1; i < N; i++ ) {
            if( dist.at( i ) == 2 ) {
                idx_dist2 = i;
                break;
            }
        }

        if( idx_dist2 == -1 ) {
            int n = N;
            while( s.at( n / 2 ) == s.at( 0 ) ) {
                n /= 2;
            }
            if( n != 0 ) {
                s.at( n ) = s.at( 0 );
            } else {
                for( int i = 1; i < N; i++ ) {
                    if( s.at( i ) != s.at( 0 ) ) {
                        s.at( i ) = s.at( 0 );
                    }
                }
            }
        } else {
            for( int j = 0; j < N; j++ ) {
                if( s.at( j ) != dict.at( idx_dist2 ).at( j ) ) {
                    s.at( j ) = dict.at( idx_dist2 ).at( j );
                    break;
                }
            }
        }
        t = s;
        for( int i = 0; i < N; i++ ) {
            dict.at( i ) = t;
            t = t.substr( 1, N - 1 ) + t.substr( 0, 1 );
        }
        sum_dist = 0;
        for( int i = 1; i < N; i++ ) {
            dist.at( i ) = hamming_dist( dict.at( 0 ), dict.at( i ) );
            sum_dist += dist.at( i );
        }
    }
    if( sum_dist == 0 ) {
        answer = 1;
    }
    else {
        std::set< std::string > counter;
        for( int i = 0; i < N; i ++ ) {
            counter.insert( dict.at(i) );
        }
        answer = counter.size();
    }
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
