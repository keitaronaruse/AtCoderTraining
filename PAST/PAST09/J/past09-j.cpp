/**
* @file past09-j.cpp
* @brief PAST 9 Problem J - 回転と反転
  @author Keitaro Naruse
* @date 2022-03-17
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_j
*/

//  m0  m1  m2  m3  m4  m5  m6  m7
//  43  14  21  32  34  41  12  23
//  12  23  34  41  21  32  43  14

#include <iostream>
#include <vector>
#include <algorithm>

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& e : v ) {
        os << e << " ";
    }
    return( os );
}

void paint_point( std::vector< std::vector< int > >& board, int x, int y, int r, int ud, int lr ) 
{
    int N = board.size();
    int h, w;
    if( r == 0 ) {
        h = x; 
        w = y;
    }
    else if( r == 1 ) {
        h = N - 1 - y; 
        w = x;
    }
    else if( r == 2 ) {
        h = N - 1 - x; 
        w = N - 1 - y; 
    }
    else if( r == 3 ) {
        h = y; 
        w = N - 1 - x; 
    }

    if( ud == 1 ) {
        h = N - 1 - h;
    }

    if( lr == 1 ) {
        w = N - 1 - w;
    }

    board.at( h ).at( w ) = ( board.at( h ).at( w ) + 1 ) % 2;
}

std::vector< std::vector< int > > rotate_board( const std::vector< std::vector< int > >& board, int r, int ud, int lr )
{
    int N = board.size();
    std::vector< std::vector< int > > screen = board;
    for( int x = 0; x < N; x ++ ) {
        for( int y = 0; y < N; y ++ ) {
            int h, w;
            if( r == 0 ) {
                h = x; 
                w = y;
            }
            else if( r == 1 ) {
                h = y; 
                w = N - 1 - x; 
            }
            else if( r == 2 ) {
                h = N - 1 - x; 
                w = N - 1 - y; 
            }
            else if( r == 3 ) {
                h = N - 1 - y; 
                w = x;
            }

            if( ud == 1 ) {
                h = N - 1 - h;
            }
            if( lr == 1 ) {
                w = N - 1 - w;
            }
            screen.at( h ).at( w ) = board.at( x ).at( y ) ;
        }
    }
    return( screen );
}

int main()
{
    //  N = [ 1, 300 ]
    int N;
    //  Q = [ 1, 2 * 10^5 ]
    int Q;
    std::cin >> N >> Q;

    //  Main
    std::vector< std::vector< int > > board( N, std::vector< int > ( N, 0 ) );
    //  Modes
    int m = 0;
    //  r == 0 if nothing, 1 if A or BBB, 2 if AA or BB, 3 if AAA or B
    int r = 0;
    //  ud == 0 if normal, 1 == up-down flipped
    int ud = 0;
    //  lr == 0 if normal, 1 == left-right flipped
    int lr = 0;
    for( int i = 0; i < Q; i ++ ) {
        int q;
        std::cin >> q;
        if( q == 1 ) {
            int x, y;
            std::cin >> x >> y;
            paint_point( board, x - 1, y - 1, r, ud, lr );
        }
        else if( q == 2 ) {
            char c;
            std::cin >> c;
            if( c == 'A' ) {
                switch( m ) {
                    case 0: m = 1; break;
                    case 1: m = 2; break;
                    case 2: m = 3; break;
                    case 3: m = 0; break;
                    case 4: m = 7; break;
                    case 5: m = 4; break;
                    case 6: m = 5; break;
                    case 7: m = 6; break;
                    default: break;
                }
            }
            else if( c == 'B' ) {
                switch( m ) {
                    case 0: m = 3; break;
                    case 1: m = 0; break;
                    case 2: m = 1; break;
                    case 3: m = 2; break;
                    case 4: m = 5; break;
                    case 5: m = 6; break;
                    case 6: m = 7; break;
                    case 7: m = 4; break;
                    default: break;
                }
            }
        }
        //  q == 3, next
        else if( q == 3 ) {
            char c;
            std::cin >> c;
            if( c == 'A' ) {
                switch( m ) {
                    case 0: m = 4; break;
                    case 1: m = 5; break;
                    case 2: m = 6; break;
                    case 3: m = 7; break;
                    case 4: m = 0; break;
                    case 5: m = 1; break;
                    case 6: m = 2; break;
                    case 7: m = 3; break;
                    default: break;
                }
            }
            else if( c == 'B' ) {
                switch( m ) {
                    case 0: m = 6; break;
                    case 1: m = 7; break;
                    case 2: m = 4; break;
                    case 3: m = 5; break;
                    case 4: m = 1; break;
                    case 5: m = 3; break;
                    case 6: m = 0; break;
                    case 7: m = 1; break;
                    default: break;
                }
            }
        }
    }

    //  Output
    board = rotate_board( board, r, ud, lr );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            std::cout << board.at( i ).at( j );
        }
        std::cout << std::endl;
    }
    std::cout << r << " " << ud << " " << lr << std::endl;

    return( 0 );
}
