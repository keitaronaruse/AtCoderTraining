/**
* @file abc241-c.cpp
* @brief ABC241 Problem C - Connect 6
* @author Keitaro Naruse
* @date 2022-02-26, 2022-02-27
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

bool old_solution( int N, int K, const std::vector< std::vector< char > >& S )
{
    //  Matching patterns
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
                    return( true );
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
                    return( true );
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
                    return( true );
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
                    return( true );
                }
            }
        }
    }
    return( false );
}

bool new_solution( int N, int K, const std::vector< std::vector< char > >& S )
{
    for( int h = 0; h < N; h ++ ) {
        for( int w = 0; w < N; w ++ ) {
            //  check out in the width direction
            if( w <= N - K ) {
                int num_hash = 0;
                for( int k = 0; k < K; k ++ ) {
                    if( S.at( h ).at( w + k ) == '#' ) {
                        num_hash ++;
                    }
                }
                if( num_hash >= 4 ) {
                    return( true );
                }
            }
            //  check out in the height direction
            if( h <= N - K ) {
                int num_hash = 0;
                for( int k = 0; k < K; k ++ ) {
                    if( S.at( h + k ).at( w ) == '#' ) {
                        num_hash ++;
                    }
                }
                if( num_hash >= 4 ) {
                    return( true );
                }
            }
            //  check out in the diagonal check, positive slope 
            if( h <= N - K && w <= N - K ) {
                int num_hash = 0;
                for( int k = 0; k < K; k ++ ) {
                    if( S.at( h + k ).at( w + k ) == '#' ) {
                        num_hash ++;
                    }
                }
                if( num_hash >= 4 ) {
                    return( true );
                }
            }
            //  check out in the diagonal check, negative slope 
            if( h <= N - K && w <= N - K ) {
                int num_hash = 0;
                for( int k = 0; k < K; k ++ ) {
                    if( S.at( h + k ).at( w + K - 1 - k ) == '#' ) {
                        num_hash ++;
                    }
                }
                if( num_hash >= 4 ) {
                    return( true );
                }
            }
        }
    }
    return( false );
}

int main()
{
    //  Constant
    const int K = 6;

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
    // bool isYes = old_solution( N, K, S );
    bool isYes = new_solution( N, K, S );
    
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
