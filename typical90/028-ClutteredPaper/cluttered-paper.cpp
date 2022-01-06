/*
    028 - Cluttered Paper（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_ab
        Author: Keitaro Naruse
        Date:   2022-01-06
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>

const bool Debug = false;

int main()
{
    //  Constants
    const int X = 1000, Y = 1000;

    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Main
    std::vector< std::vector< int > > ply( Y + 2, std::vector< int >( X + 2, 0 ) );

    //  Read lx, ly and rx, ry
    for( int i = 0; i < N; i ++ ) {
        int lx = 0, ly = 0, rx = 0, ry = 0;
        std::cin >> lx >> ly >> rx >> ry;
        if( Debug ) {
            std::cerr << lx << " " << ly << " " << rx << " " << ry << std::endl;
        }
        //  imos method
        ply.at( ly + 1 ).at( lx + 1 ) ++;
        ply.at( ly + 1 ).at( rx + 1 ) --;
        ply.at( ry + 1 ).at( lx + 1 ) --;
        ply.at( ry + 1 ).at( rx + 1 ) ++;
        //  Naive method
        // for( int y = ly; y < ry; y ++ ) {
        //     for( int x = lx; x < rx; x ++ ) {
        //         ply.at( y ).at( x ) ++;
        //     }
        // }
    }
    if( Debug ) {
        for( int y = 0; y < 6; y ++ ) {
            for( int x = 0; x < 6; x ++) {
                std::cerr << ply.at( y ).at( x ) << " ";
            }
            std::cerr << std::endl;
        }
    }
    //  Update imos
    for( int y = 0; y < Y; y ++ ) {
        for( int x = 0; x < X; x ++) {
            ply.at( y + 1 ).at( x + 2 ) += ply.at( y + 1 ).at( x + 1 );
        }
    }
    for( int x = 0; x < X; x ++ ) {
        for( int y = 0; y < Y; y ++) {
            ply.at( y + 2 ).at( x + 1 ) += ply.at( y + 1 ).at( x + 1 );
        }
    }

    std::vector< int > A( N + 1, 0 );
    for( int y = 1; y < Y + 2; y ++ ) {
        for( int x = 1; x < X + 2; x ++ ) {
            A.at( ply.at( y ).at( x ) ) ++;
        }
    }
    for( int i = 0; i < N; i ++ ) {
        std::cout << A.at( i + 1 ) << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
