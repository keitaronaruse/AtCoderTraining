/**
* @file arc139-a.cpp
* @brief ARC139 Problem X
* @author Keitaro Naruse
* @date 2022-04-24
* @copyright MIT License
* @details https://atcoder.jp/contests/arc139/tasks/arc139_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template< class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p )
{
    os << "( " << p.first << ", " << p.second << " )";
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << std::endl;
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > > & vv )
{
    for( const auto& v : vv )  {
        os << v << std::endl;
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 10^5 ]
    int N;
    std::cin >> N;

    //  Read Ti = [ 0, 40 ]
    std::vector< int > T( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> T.at( i );
    }

    //  Main
    //  Preprocess
    const int Z = 64;
    std::vector< std::string > A( N, std::string( Z, ' ' ) );
    // int prev_num = 0;
    std::string prev_str( "" );
    for( int i = 0; i < N; i ++ ) {
        if( T.at( i ) == 0 ) {
            if( prev_str.size() == 0 ) {
                prev_str = "1";
            }
            if( prev_str.at( prev_str.size() - 1 ) == '0' ) {
                prev_str.at( prev_str.size() - 1 ) = '1';
            }
            else {
                bool is_modified = false;
                for( int j = prev_str.size() - 2; j >= 0 ; j -- ) {
                    if( prev_str.at( prev_str.size() - 1 ) == '0' ) {
                        prev_str.at( prev_str.size() - 1 ) == '1';
                        is_modified = false;
                        break;
                    }
                }
                if( !is_modified ) {
                    prev_str = "1" + prev_str;
                }
                ;
            }
        }
        else {
            int ctz = 0;
            for( int j = prev_str.size() - 1; j >= 0; j -- ) {
                if( prev_str.at( j ) == '0' ) {
                    ctz ++;
                }
            }
            if( prev_str.size() <= T.at( i ) ) {
                prev_str = "1" + std::string( T.at( i ), '0' );
            }
            else {
                if( ctz > T.at( i ) ) {
                    prev_str.at( prev_str.size() - 1 - T.at( i ) ) = '1';
                }
                else if( ctz <= T.at( i ) ) {
                    bool is_modified = false;
                    //  Zero padding
                    for( int j = 0; j < prev_str.size(); j ++ ) {
                        if( j < T.at( i ) ) {
                            prev_str.at( prev_str.size() - 1 - j ) = '0';
                        }
                        else if( j == T.at( i ) ) {
                            prev_str.at( prev_str.size() - 1 - j ) = '1';
                        }
                        else if( j > T.at( i ) ) {
                            if( prev_str.at( prev_str.size() - 1 - j ) == '0' ) {
                                prev_str.at( prev_str.size() - 1 - j ) = '1';
                                is_modified = true;
                                break;
                            }
                            else if( prev_str.at( prev_str.size() - 1 - j ) == '1' ) {
                                prev_str.at( prev_str.size() - 1 - j ) = '0';
                            }
                        }
                    }
                    if( !is_modified ) {
                        prev_str = "1" + prev_str;
                    }
                }
            }
        }
    }
    
    long long ans = 0LL, k = 1LL;
    for( int j = prev_str.size() - 1; j >= 0; j -- ) {
        ans += ( long long )( prev_str.at( j ) - '0') * k;
        k *= 2LL;
    }
    std::cout << ans << std::endl;

    //  Finalize
    return( 0 );
}
