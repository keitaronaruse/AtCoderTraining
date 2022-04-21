/**
* @file abc218-c.cpp
* @brief ABC218 Problem C - Shapes
* @author Keitaro Naruse
* @date 2022-04-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc218/tasks/abc218_c
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::ostream& operator<<( std::ostream& os, const std::vector< std::string >& v )
{
    for( const auto& e : v ) {
        os << e << std::endl;
    }
    return( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector < T > >& vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

bool match( const std::vector< std::string >& T, const std::vector< std::string >& P )
{
    const int N = T.size();
    const int H = P.size();
    const int W = P.at( 0 ).size();
    bool is_match = false;
    for( int v = 0; v <= N - H; v ++ ) {
        for( int u = 0; u <= N - W; u ++ ) {
            bool is_same = true;
            for( int i = 0; is_same && i < H; i ++ ) {
                for( int j = 0; j < W; j ++ ) {
                    if( T.at( i + v ).at( j + u ) != P.at( i ).at( j ) ) {
                        is_same = false;
                        break;
                    }
                }
            }
            if( is_same ) {
                is_match = true;
                break;
            }
        }
    }

    return( is_match );
}

int main()
{
    //  Read N = [ 1, 200 ]
    int N;
    std::cin >> N;
    //  Read S, T
    std::vector< std::string > S( N ), T( N );
    for( int i = 0; i < N; i ++  ) {
        std::cin >> S.at( i );
    }
    for( int i = 0; i < N; i ++  ) {
        std::cin >> T.at( i );
    }

    //  Main
    //  Preprocess
    int num_S = 0, num_T = 0;
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            if( S.at( i ).at( j ) == '#' ) {
                num_S ++;
            }
            if( T.at( i ).at( j ) == '#' ) {
                num_T ++;
            }
        }
    }
    if( num_S != num_T ) {
        std::cout << "No" << std::endl;
        return( 0 );
    }

    std::vector< int > S_row( N, 0 ), S_col( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            if( S.at( i ).at( j ) == '#' ) {
                S_row.at( i ) ++;
                S_col.at( j ) ++;
            }
        }
    }
    int L = 0, R = 0, U = 0, D = 0;
    for( int j = 0; j < N; j ++ ) {
        if( S_col.at( j ) != 0 ) {
            L = j; break;
        }
    } 
    for( int j = N - 1; j >= 0; j -- ) {
        if( S_col.at( j ) != 0 ) {
            R = j; break;
        }
    } 
    for( int i = 0; i < N; i ++ ) {
        if( S_row.at( i ) != 0 ) {
            U = i; break;
        }
    } 
    for( int i = N - 1; i >= 0; i -- ) {
        if( S_row.at( i ) != 0 ) {
            D = i; break;
        }
    } 

    //  Make patters
    bool isYes = false;
    for( int k = 0; k < 4; k ++ ) {
        if( k == 0 ) {
            std::vector< std::string > P( D - U + 1, std::string( R - L + 1, '.' ) );
            for( int i = 0; i <= D - U; i ++ ) {
                for( int j = 0; j <= R - L; j ++ ) {
                    P.at( i ).at( j ) = S.at( i + U ).at( j + L );
                }
            }
            if( ( isYes = match( T, P ) ) ) {
                break;
            }
        }
        else if( k == 1 ) {
            std::vector< std::string > P( R - L + 1, std::string( D - U + 1, '.' ) );
            for( int i = 0; i <= D - U; i ++ ) {
                for( int j = 0; j <= R - L; j ++ ) {
                    P.at( R - L - j ).at( i ) = S.at( i + U ).at( j + L );
                }
            }
            if( ( isYes = match( T, P ) ) ) {
                break;
            }
        }
        else if( k == 2 ) {
            std::vector< std::string > P( D - U + 1, std::string( R - L + 1, '.' ) );
            for( int i = 0; i <= D - U; i ++ ) {
                for( int j = 0; j <= R - L; j ++ ) {
                    P.at( D - U - i ).at( R - L - j ) = S.at( i + U ).at( j + L );
                }
            }
            if( ( isYes = match( T, P ) ) ) {
                break;
            }
        }
        else {
            std::vector< std::string > P( R - L + 1, std::string( D - U + 1, '.' ) );
            for( int i = 0; i <= D - U; i ++ ) {
                for( int j = 0; j <= R - L; j ++ ) {
                    P.at( j ).at( D - U - i ) = S.at( i + U ).at( j + L );
                }
            }
            if( ( isYes = match( T, P ) ) ) {
                break;
            }
        }
    } 

    //  Find the solution
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
