/**
* @file abc241-c.cpp
* @brief ABC241 Problem C
* @author Keitaro Naruse
* @date 2022-02-26
* @copyright MIT License
* @details https://atcoder.jp/contests/abc241/tasks/abc241_c
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< char > >& v )
{
    for( auto k : v ) {
        for( auto s : k ) {
            os << s;
        }
        os << std::endl;
    }
    return( os );
}

int main()
{
    //  Read N = [ 6, 1000 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Sij
    std::vector< std::vector< char > > S( N, std::vector< char >( N, ' ' ) );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            std::cin >> S.at( i ).at( j );
        }
    }
    if( Debug ) {
        std::cerr << S;
    }
    
    //  Main
    const int K = 6;
    std::vector< std::string > patterns;
    //  No period
    patterns.push_back("######");
    //  One period
    for( int i = 0; i < K; i ++ ) {
        std::string s = "######";
        s.at( i ) = '.';
        patterns.push_back( s );
    }
    //  Two periods
    for( int i = 0; i < K; i ++ ) {
        for( int j = i + 1; j < K; j ++ ) {
            std::string s = "######";
            s.at( i ) = '.';
            s.at( j ) = '.';
            patterns.push_back( s );
        }
    }
    if( Debug ) {
        for( auto s : patterns ) {
            std::cerr << s << std::endl;
        }
    }

    //  Main
    //  Horizontal check
    for( int h = 0; h < N; h ++ ) {
        for( int w = 0; w < N - K + 1; w ++ ) {
            for( int i = 0; i < patterns.size(); i ++ ) {
                //  Horizontal check
                bool is_match = true;
                for( int k = 0; k < K; k ++ ) {
                    if( patterns.at( i ).at( k ) != S.at( h ).at( w + k ) ) {
                        is_match = false;
                        break;
                    }
                }
                if( is_match ) {
                    std::cout << "Yes" << std::endl;
                    return( 0 );
                }
            }
        }
    }

    //  Vertical check
    for( int h = 0; h < N - K + 1; h ++ ) {
        for( int w = 0; w < N; w ++ ) {
            for( int i = 0; i < patterns.size(); i ++ ) {
                // //  Vertical check
                bool is_match = true;
                for( int k = 0; k < K; k ++ ) {
                    if( patterns.at( i ).at( k ) != S.at( h + k ).at( w ) ) {
                        is_match = false;
                        break;
                    }
                }
                if( is_match ) {
                    std::cout << "Yes" << std::endl;
                    return( 0 );
                }
            }
        }
    }

    //  Diagonal check
    for( int h = 0; h < N - K + 1; h ++ ) {
        for( int w = 0; w < N - K + 1; w ++ ) {
            for( int i = 0; i < patterns.size(); i ++ ) {
                //  Diagonal check
                bool is_match = true;
                for( int k = 0; k < K; k ++ ) {
                    if( patterns.at( i ).at( k ) != S.at( h + k ).at( w + k ) ) {
                        is_match = false;
                        break;
                    }
                }
                if( is_match ) {
                    std::cout << "Yes" << std::endl;
                    return( 0 );
                }

                //  Another diagonal check
                is_match = true;
                for( int k = 0; k < K; k ++ ) {
                    if( patterns.at( i ).at( k ) != S.at( h + k ).at( w + K - k - 1 ) ) {
                        is_match = false;
                        break;
                    }
                }
                if( is_match ) {
                    std::cout << "Yes" << std::endl;
                    return( 0 );
                }
            }
        }
    }
    std::cout << "No" << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
