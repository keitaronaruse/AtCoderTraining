/*
    018 - Statue of Chokudai（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_r
        Author: Keitaro Naruse
        Date:   2021-12-08, 2022-01-01
        MIT License
*/

// # Solution
// - x = 0
// - y = - L/2 * sin( 2*pi*Ei / T )
// - z = - L/2 * cos( 2*pi*Ei / T ) + L/2
// - P = (0, y, z)
// - Q = (X, Y, 0)
// - P-Q = (-X, y-Y, z)
// - h = dist(-X, y-Y ) 
// - v = z
// - deg = rad2deg( atn2( v, h ) )

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

const bool Debug = false;

int main()
{
    //  Read T, L, X, Y
    int T = 0, L = 0, X = 0, Y = 0;
    std::cin >> T >> L >> X >> Y;
    if( Debug ) {
        std::cerr << T << std::endl << L << " " << X << " " << Y << std::endl;
    }
    //  Read Q and Ei
    int Q = 0;
    std::cin >> Q;
    if( Debug ) {
        std::cerr << Q << std::endl;
    }
    std::vector< int > E( Q );
    for( int i = 0; i < Q; i ++ ) {
        std::cin >> E.at( i );
        if( Debug ) {
            std::cerr << E.at( i ) << std::endl;
        }
    }

    //  Main
    for( int i = 0; i < Q; i++ ) {
        double y = - (double)L / 2.0 * std::sin( 2.0 * M_PI * (double)E.at( i ) / (double)T );
        double z = - (double)L / 2.0 * std::cos( 2.0 * M_PI * (double)E.at( i ) / (double)T ) + (double)L / 2.0;
        double h = std::sqrt( std::pow( - X, 2.0 ) + std::pow( y - Y, 2.0 ) ); 
        double v = z; 
        if( Debug ) {
            std::cerr << E.at( i ) << ": " << y << ", " << z << ", " << h << ", " << v << ", " << std::endl; 
        }
        std::cout << std::fixed << std::setprecision(12) << atan2(v, h) / M_PI * 180.0 << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
