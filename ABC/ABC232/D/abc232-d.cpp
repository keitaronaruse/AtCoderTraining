/*
    ABC232 Problem D - Weak Takahashi
        https://atcoder.jp/contests/abc232/tasks/abc232_d
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-11
        MIT License
*/

// # Solution
// - 

#include <iostream>
#include <string>
#include <vector>

const bool Debug = false;

int main()
{
    //  Read H and W
    int H = 0, W = 0;
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read C
    std::vector< std::vector< char > > C( H, std::vector< char >( W, ' ' ) );
    for( int i = 0; i < H; i ++ ) {
        std::string s;
        std::cin >> s;
        for( int j = 0; j < W; j ++ ) {
            C.at( i ).at( j ) = s.at( j );
        }
    }
    if( Debug ) {
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                std::cerr << C.at( i ).at( j );
            }
            std::cerr << std::endl;
        }
    }

    //  Main
    std::vector< std::vector< int > > dist( H, std::vector< int >( W, 0 ) );
    //  Boundary h = H - 1, w = W - 1
    int h = H - 1, w = W - 1;
    dist.at( h ).at( w ) = 1;
    //   Boundary: h = H - 1, w = *
    for( w = W - 1; w > 0; w -- ) {
        h = H - 1;
        if( C.at( h ).at( w - 1 ) == '.' ) {
            dist.at( h ).at( w - 1 ) = dist.at( h ).at( w ) + 1;
        }
        else {
            dist.at( h ).at( w - 1 ) = 0;
        }
    }
    //  Boundary: h = *, w = W - 1
    for( h = H - 1; h > 0; h -- ) {
        w = W - 1;
        if( C.at( h - 1 ).at( w ) == '.' ) {
            dist.at( h - 1 ).at( w ) = dist.at( h ).at( w ) + 1;
        }
        else {
            dist.at( h - 1 ).at( w ) = 0;
        }
    }
    //  Regular cases
    for( h = H - 1; h > 0; h -- ) {
        for( w = W - 1; w > 0; w -- ) {
            if( C.at( h - 1 ).at( w - 1 ) == '.' ) {
                dist.at( h - 1 ).at( w - 1 ) 
                = std::max( dist.at( h - 1 ).at( w ), dist.at( h ).at( w - 1 ) ) + 1;
            }
            else {
                dist.at( h - 1 ).at( w - 1 ) = 0;
            }
        }
    }
    if( Debug ) {
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                std::cerr << dist.at( h ).at( w ) << " ";
            }
            std::cerr << std::endl;
        }
    }

    //  Display result
    h = 0; w = 0;
    std::cout << dist.at( h ).at( w ) << std::endl;

    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
