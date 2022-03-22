/**
* @file past09-j.cpp
* @brief PAST 9 Problem J - 回転と反転
  @author Keitaro Naruse
* @date 2022-03-18
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_j
*/

//  m0  m1  m2  m3  m4  m5  m6  m7
//  43  14  21  32  34  41  12  23
//  12  23  34  41  21  32  43  14

#include <iostream>
#include <vector>
#include <algorithm>

void convert_to_board( int& h, int& w, int x, int y, int N, int mode )
{
    switch( mode ) {
        case 0: h = x;         w = y;         break;
        case 1: h = N - 1 - y; w = x;         break;
        case 2: h = N - 1 - x; w = N - 1 - y; break;
        case 3: h = y;         w = N - 1 - x; break;
        case 4: h = N - 1 - x; w = y;         break;
        case 5: h = N - 1 - y; w = N - 1 - x; break;
        case 6: h = x;         w = N - 1 - y; break;
        case 7: h = y;         w = x;         break;
        default: break;
    }
}

void convert_to_screen( int& h, int& w, int x, int y, int N, int mode )
{
    switch( mode ) {
        case 0: h = x;         w = y;         break;
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

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > >& vv ) 
{
    for( const auto& v : vv ) {
        for( auto k : v ) {
            os << k;
        }
        os << std::endl;
    }
    return( os );
}

int main()
{
    //  N = [ 1, 300 ]
    int N;
    //  Q = [ 1, 2 * 10^5 ]
    int Q;
    std::cin >> N >> Q;

    //  Main
<<<<<<< HEAD
    std::vector< std::vector< int > > board( N, std::vector< int > ( N, 0 ) );
    //  Modes
    int m = 0;
    //  r == 0 if nothing, 1 if A or BBB, 2 if AA or BB, 3 if AAA or B
    int r = 0;
    //  ud == 0 if normal, 1 == up-down flipped
    int ud = 0;
    //  lr == 0 if normal, 1 == left-right flipped
    int lr = 0;
=======
    int mode = 0;
    std::vector< std::vector< int > > board( N, std::vector< int >( N, 0 ) );

>>>>>>> ca412ff228b385b9d07c93d59d6d8ba2e532c805
    for( int i = 0; i < Q; i ++ ) {
        int q;
        std::cin >> q;
        if( q == 1 ) {
            int x, y, h, w;
            std::cin >> x >> y;
            convert_to_board( h, w, x - 1, y - 1, N, mode );
            board.at( h ).at( w ) = ( board.at( h ).at( w ) + 1 ) % 2;
        }
        else if( q == 2 ) {
            char c;
            std::cin >> c;
            if( c == 'A' ) {
<<<<<<< HEAD
                switch( m ) {
                    case 0: m = 1; break;
                    case 1: m = 2; break;
                    case 2: m = 3; break;
                    case 3: m = 0; break;
                    case 4: m = 7; break;
                    case 5: m = 4; break;
                    case 6: m = 5; break;
                    case 7: m = 6; break;
=======
                switch( mode ) {
                    case 0: mode = 1; break;
                    case 1: mode = 2; break;
                    case 2: mode = 3; break;
                    case 3: mode = 0; break;
                    case 4: mode = 7; break;
                    case 5: mode = 4; break;
                    case 6: mode = 5; break;
                    case 7: mode = 6; break;
>>>>>>> ca412ff228b385b9d07c93d59d6d8ba2e532c805
                    default: break;
                }
            }
            else if( c == 'B' ) {
<<<<<<< HEAD
                switch( m ) {
                    case 0: m = 3; break;
                    case 1: m = 0; break;
                    case 2: m = 1; break;
                    case 3: m = 2; break;
                    case 4: m = 5; break;
                    case 5: m = 6; break;
                    case 6: m = 7; break;
                    case 7: m = 4; break;
=======
                switch( mode ) {
                    case 0: mode = 3; break;
                    case 1: mode = 0; break;
                    case 2: mode = 1; break;
                    case 3: mode = 2; break;
                    case 4: mode = 5; break;
                    case 5: mode = 6; break;
                    case 6: mode = 7; break;
                    case 7: mode = 4; break;
>>>>>>> ca412ff228b385b9d07c93d59d6d8ba2e532c805
                    default: break;
                }
            }
        }
        //  q == 3, next
        else if( q == 3 ) {
            char c;
            std::cin >> c;
            if( c == 'A' ) {
<<<<<<< HEAD
                switch( m ) {
                    case 0: m = 4; break;
                    case 1: m = 5; break;
                    case 2: m = 6; break;
                    case 3: m = 7; break;
                    case 4: m = 0; break;
                    case 5: m = 1; break;
                    case 6: m = 2; break;
                    case 7: m = 3; break;
=======
                switch( mode ) {
                    case 0: mode = 4; break;
                    case 1: mode = 5; break;
                    case 2: mode = 6; break;
                    case 3: mode = 7; break;
                    case 4: mode = 0; break;
                    case 5: mode = 1; break;
                    case 6: mode = 2; break;
                    case 7: mode = 3; break;
>>>>>>> ca412ff228b385b9d07c93d59d6d8ba2e532c805
                    default: break;
                }
            }
            else if( c == 'B' ) {
<<<<<<< HEAD
                switch( m ) {
                    case 0: m = 6; break;
                    case 1: m = 7; break;
                    case 2: m = 4; break;
                    case 3: m = 5; break;
                    case 4: m = 1; break;
                    case 5: m = 3; break;
                    case 6: m = 0; break;
                    case 7: m = 1; break;
=======
                switch( mode ) {
                    case 0: mode = 6; break;
                    case 1: mode = 7; break;
                    case 2: mode = 4; break;
                    case 3: mode = 5; break;
                    case 4: mode = 2; break;
                    case 5: mode = 3; break;
                    case 6: mode = 0; break;
                    case 7: mode = 1; break;
>>>>>>> ca412ff228b385b9d07c93d59d6d8ba2e532c805
                    default: break;
                }
            }
        }
    }

    //  Output
    std::vector< std::vector< int > > screen = board;
    for( int h = 0; h < N; h ++ ) {
        for( int w = 0; w < N; w ++ ) {
            int v, u;
            convert_to_screen( v, u, h, w, N, mode );
            screen.at( v ).at( u ) = board.at( h ).at( w );
        }
    }
    std::cout << screen;

    return( 0 );
}
