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
    std::vector< std::vector< int > > ply( X + 1, std::vector< int >( Y + 1, 0 ) );

    //  Read lx, ly and rx, ry
    for( int i = 0; i < N; i ++ ) {
        int lx = 0, ly = 0, rx = 0, ry = 0;
        std::cin >> lx >> ly >> rx >> ry;
        if( Debug ) {
            std::cerr << lx << " " << ly << " " << rx << " " << ry << std::endl;
        }
        for( int x = lx; x <= rx; x ++ ) {
            for( int y = ly; y <= ly; y ++ ) {
                ply.at( x ).at( y ) ++;
            }
        }
    }

    std::vector< int > A( N + 1, 0 );
    for( int x = 0; x <= X; x ++ ) {
        for( int y = 0; y <= Y; y ++ ) {
            A.at( ply.at( x ).at( y ) ) ++;
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
