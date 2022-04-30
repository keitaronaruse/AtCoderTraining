/**
* @file arc131-b.cpp
* @brief ARC131 Problem B - Grid Repainting 4
* @author Keitaro Naruse
* @date 2022-05-01
* @copyright MIT License
* @details https://atcoder.jp/contests/arc131/tasks/arc131_b
*/

// # Solution

#include <iostream>
#include <vector>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k;
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
    //  Read H, W = [ 1, 700 ]
    int H, W;
    std::cin >> H >> W;

    //  Read cij = [ '1', '2', '3', '4', '5', '.' ]
    std::vector< std::vector< int > > c( H, std::vector< int >( W ) );
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            char ch;
            std::cin >> ch;
            c.at( h ).at( w ) = ( ch == '.' ) ? 9 : ( int )( ch - '0' );
        }
    }

    //  Main
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            if( c.at( h ).at( w ) == 9 ) {
                const int K = 4;
                std::vector< int > dh = {  0, -1,  0,  1 };
                std::vector< int > dw = {  1,  0, -1,  0 };

                const int Z = 5;
                std::vector< bool > used( Z + 1, false );
                for( int k = 0; k < K; k ++ ) {
                    int v = h + dh.at( k ), u = w + dw.at( k );
                    if( 0 <= v && v < H && 0 <= u && u < W ) {
                        int color = c.at( v ).at( u );
                        if( color != 9 ) {
                            used.at( color ) = true;
                        }
                    }
                }
                for( int k = 1; k <= Z; k ++ ) {
                    if( !used.at( k ) ) {
                        c.at( h ).at( w ) = k;
                        break;
                    }
                }
            }
        }
    }

    std::cout << c;

    //  Finalize
    return( 0 );
}
