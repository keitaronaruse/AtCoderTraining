/*
    DP Matching
        Author: Keitaro Naruse
        Date:   2021-12-16
        MIT License
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

float distance(float px, float py, float qx, float qy)
{
    return( std::sqrt( std::pow( px - qx, 2.0 ) + std::pow( py - qy, 2.0) ) ); 
}

int main()
{
    //  Trajectory of Robot A, N points
    //  Read N, Px, Py
    int N; 
    std::cin >> N;
    // std::cerr << N << std::endl;
    std::vector< float > Px( N ), Py( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> Px[ i ] >> Py[ i ];
        // std::cerr << Px[ i ] << " " << Py[ i ] << std::endl;
    }

    //  Trajectory of Robot B, M points
    //  Read M, Qx, Qy
    int M; 
    std::cin >> M;
    // std::cerr << M << std::endl;
    std::vector< float > Qx( N ), Qy( N );
    for( int j = 0; j < M; j ++ ) {
        std::cin >> Qx[ j ] >> Qy[ j ];
        // std::cerr << Qx[ j ] << " " << Qy[ j ] << std::endl;
    }

    //  DP matching table
    const float large = (float)1e9;
    std::vector< std::vector<float> > dp( N, std::vector<float>( M, large ) );
 
    // Main
    // Dp initailization
    // i = 0 and j = 0 are always matched
    dp[ 0 ][ 0 ] = distance( Px[0], Py[0], Qx[0], Qy[0] );

    //  Main
    for( int i = 1; i < N; i ++ ) {
        for( int j = 1; j < M; j ++ ) {
            dp[ i ][ j ] = std::min( std::min( dp[ i - 1 ][ j - 1 ], dp[ i ][ j - 1 ]), dp[ i - 1 ][ j ])
            + distance( Px[ i ], Py[ i ], Qx[ j ], Qy[ j ] ); 
        }
    }

    //  Display dp table
    for( int j = 0; j < M; j ++ ) {
        for( int i = 0; i < N; i++ ) {
            if( dp[ i ][ j ] == large ) {
                std::cout << "INF   ";
            }
            else {
                std::cout << std::fixed << std::setprecision(3) << dp[ i ][ j ] << " ";
            }
        }
        std::cout << std::endl;
    }

    return( 0 ); 
}
