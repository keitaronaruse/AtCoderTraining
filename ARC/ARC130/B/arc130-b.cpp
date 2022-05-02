/**
 * @file arc130-b.cpp
 * @brief ARC131 Problem B - Colorful Lines
 * @author Keitaro Naruse
 * @date 2022-05-03
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc130/tasks/arc130_b
 */

// # Solution

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <functional>

int main( ) {
    //  Read H, W = [ 2, 10^9 ], C, Q = [ 1, 3*10^5 ]
    int H, W, C, Q;
    std::cin >> H >> W >> C >> Q;

    //  Read t = [ 1, 2 ], n = [1, H( W )], c = [ 1, C ]
    std::vector< int > t( Q ), n( Q ), c( Q );
    for( int i = 0; i < Q; i++ ) {
        std::cin >> t.at( i ) >> n.at( i ) >> c.at( i );
    }

    //  Main
    //  Preprocess
    //  row_color[ n ] = ( c, i ), col_color[ n ] = ( c, i )
    std::map< int, std::pair< int, int > > row_color, col_color;
    for( int i = 0; i < Q; i++ ) {
        if( t.at( i ) == 1 ) {
            row_color[ n.at( i ) ] = std::make_pair( c.at( i ), i );
        } else {
            col_color[ n.at( i ) ] = std::make_pair( c.at( i ), i );
        }
    }
    //  op[ i ] = ( row = 1/col = 2, c );
    std::map< int, std::pair< int, int >, std::greater< int > > ops;
    for( const auto& p : row_color ) {
        ops[ p.second.second ] = std::make_pair( 1, p.second.first );
    }
    for( const auto& p : col_color ) {
        ops[ p.second.second ] = std::make_pair( 2, p.second.first );
    }

    //  Find the solution
    std::vector< long long > num_cells( C + 1, 0LL );
    int num_rows = 0, num_cols = 0;
    for( const auto& p : ops ) {
        if( p.second.first == 1 ) {
            num_cells.at( p.second.second ) += ( long long ) ( W - num_cols );
            num_rows++;
        } else {
            num_cells.at( p.second.second ) += ( long long ) ( H - num_rows );
            num_cols++;
        }
    }
    //  Display the answers
    for( int i = 1; i <= C; i++ ) {
        std::cout << num_cells.at( i ) << " ";
    }
    std::cout << std::endl;

    //  Finalize
    return ( 0 );
}
