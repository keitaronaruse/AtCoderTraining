/**
* @file past09-j.cpp
* @brief PAST 9 Problem J - 回転と反転
  @author Keitaro Naruse
* @date 2022-03-17
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_j
*/

#include <iostream>
#include <vector>
#include <algorithm>

void convert_position( int& h, int& w, int x, int y, int N,  int mode )
{
    switch( mode ) {
        case 0: h = x;         w = y; break;
        case 1: h = y;         w = N - 1 - x; break;
        case 2: h = N - 1 - x; w = N - 1 - y; break;
        case 3: h = N - 1 - y; w = x; break;
        case 4: h = N - 1 - x; w = y; break;
        case 5: h = N - 1 - y; w = N - 1 - x; break;
        case 6: h = x;         w = N - 1 - y; break;
        case 7: h = y;         w = x; break;
        default: break;
    }
}

int main()
{
    //  N = [ 1, 300 ]
    int N;
    //  Q = [ 1, 2 * 10^5 ]
    int Q;
    std::cin >> N >> Q;

    //  Main
    int mode = 0;
    std::vector< std::vector< int > > board( N, std::vector< int >( N, 0 ) );

    for( int i = 0; i < Q; i ++ ) {
        int q;
        std::cin >> q;
        if( q == 1 ) {
            int x, y, h, w;
            std::cin >> x >> y;
            convert_position( h, w, x - 1, y - 1, N, mode );
            board.at( h ).at( w ) = ( board.at( h ).at( w ) + 1 ) % 2;
        }
        else if( q == 2 ) {
            char c;
            std::cin >> c;
            if( c == 'A' ) {
                switch( mode ) {
                    case 0: mode = 1; break;
                    case 1: mode = 2; break;
                    case 2: mode = 3; break;
                    case 3: mode = 0; break;
                    case 4: mode = 7; break;
                    case 5: mode = 4; break;
                    case 6: mode = 5; break;
                    case 7: mode = 6; break;
                    default: break;
                }
            }
            else if( c == 'B' ) {
                switch( mode ) {
                    case 0: mode = 3; break;
                    case 1: mode = 0; break;
                    case 2: mode = 1; break;
                    case 3: mode = 2; break;
                    case 4: mode = 5; break;
                    case 5: mode = 6; break;
                    case 6: mode = 7; break;
                    case 7: mode = 4; break;
                    default: break;
                }
            }
        }
        else if( q == 3 ) {
            char c;
            std::cin >> c;
            if( c == 'A' ) {
                switch( mode ) {
                    case 0: mode = 4; break;
                    case 1: mode = 5; break;
                    case 2: mode = 6; break;
                    case 3: mode = 7; break;
                    case 4: mode = 0; break;
                    case 5: mode = 1; break;
                    case 6: mode = 2; break;
                    case 7: mode = 3; break;
                    default: break;
                }
            }
            else if( c == 'B' ) {
                switch( mode ) {
                    case 0: mode = 6; break;
                    case 1: mode = 7; break;
                    case 2: mode = 4; break;
                    case 3: mode = 5; break;
                    case 4: mode = 2; break;
                    case 5: mode = 3; break;
                    case 6: mode = 0; break;
                    case 7: mode = 1; break;
                    default: break;
                }
            }
        }
        std::cout << mode << std::endl;
        for( int h = 0; h < N; h ++ ) {
            for( int w = 0; w < N; w ++ ) {
                std::cout << board.at( h ).at( w );
            }
            std::cout << std::endl;
        }
    }
    std::vector< std::vector< int > > screen = board;
    for( int h = 0; h < N; h ++ ) {
        for( int w = 0; w < N; w ++ ) {
            int v, u;
            convert_position( v, u, h, w, N, mode );
            screen.at( v ).at( u ) = board.at( h ).at( w );
        }
    }


    return( 0 );
}
