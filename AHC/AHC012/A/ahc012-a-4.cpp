/**
 * @file ahc012-a-3.cpp
 * @brief AHC012 Problem A - AtCoder 10th Anniversary
 * @author Keitaro Naruse
 * @date 2022-07-03
 * @copyright MIT License
 * @details https://atcoder.jp/contests/ahc012/tasks/ahc012_a
 */
#include <iostream>
#include <vector>
#include <algorithm>

class Line {
   public:
    int px, py, qx, qy;
};

int hamming( const std::vector< int >& a, const std::vector< int >& b ) {
    int dist = 0;
    for( int i = 1; i <= 10; i++ ) {
        if( a.at( i ) >= b.at( i ) ) {
            dist += a.at( i ) - b.at( i );
        } else {
            dist += b.at( i ) - a.at( i );
        }
    }
    return ( dist );
}

std::vector< int > analyze( const std::vector< int >& tx,
                            const std::vector< int >& ty,
                            const std::vector< int >& X,
                            const std::vector< int >& Y, int N ) {
    std::vector< int > A( 12, 0 );

    int N_tx = tx.size( ) - 1;
    int N_ty = ty.size( ) - 1;
    std::vector< std::vector< int > > num_points(
        N_tx, std::vector< int >( N_ty, 0 ) );
    for( int i = 0; i < N; i++ ) {
        int ix = std::lower_bound( tx.begin( ), tx.end( ), X.at( i ) ) -
                 tx.begin( ) - 1;
        int iy = std::lower_bound( ty.begin( ), ty.end( ), Y.at( i ) ) -
                 ty.begin( ) - 1;
        num_points.at( ix ).at( iy )++;
    }

    for( int ix = 0; ix < N_tx; ix++ ) {
        for( int iy = 0; iy < N_ty; iy++ ) {
            if( 10 < num_points.at( ix ).at( iy ) ) {
                A.at( 11 )++;
            } else {
                A.at( num_points.at( ix ).at( iy ) )++;
            }
        }
    }
    return ( A );
}

int main( ) {
    //  Read N = [ 55, 5500 ], K = 1003
    int N, K;
    std::cin >> N >> K;

    //  Read ai
    const int D = 10;
    std::vector< int > A( D + 1, 0 );
    for( int j = 1; j <= D; j++ ) {
        std::cin >> A.at( j );
    }

    //  Read x, y
    std::vector< int > X( N, 0 ), Y( N, 0 );
    for( int i = 0; i < N; i++ ) {
        std::cin >> X.at( i ) >> Y.at( i );
    }

    //  Main
    std::vector< Line > lines( K );
    int tmin = -10000, tmax = 10000;
    std::vector< int > tx_org = {
        -10000, -9875, -9750, -9500, -9250, -9000, -8750, -8500, -8000, -7500,
        -7000,  -6500, -6000, -5500, -5000, -4500, -4000, -3500, -3000, -2500,
        -2000,  -1500, -1000, -500,  0,     500,   1000,  1500,  2000,  2500,
        3000,   3500,  4000,  4500,  5000,  5500,  6000,  6500,  7000,  7500,
        8000,   8500,  8750,  9000,  9500,  9750,  9875,  10000 };
    std::vector< int > ty_org = {
        -10000, -9875, -9750, -9500, -9250, -9000, -8750, -8500, -8000, -7500,
        -7000,  -6500, -6000, -5500, -5000, -4500, -4000, -3500, -3000, -2500,
        -2000,  -1500, -1000, -500,  0,     500,   1000,  1500,  2000,  2500,
        3000,   3500,  4000,  4500,  5000,  5500,  6000,  6500,  7000,  7500,
        8000,   8500,  8750,  9000,  9250,  9500,  9750,  9875,  10000 };

    //  Analysis
    std::vector< int > As = analyze( tx_org, ty_org, X, Y, N );

    //  X-Y
    int min_dist_XY = hamming( A, As );
    std::vector< int > tx_XY = tx_org, ty_XY = ty_org;
    //  X, first
    bool updated = true;
    while( updated ) {
        std::vector< int > min_tx;
        std::vector< int > tx2;
        std::vector< int > As2;
        updated = false;
        for( int i = 1; i < tx_XY.size( ) - 1; i++ ) {
            tx2 = tx_XY;
            tx2.erase( tx2.begin( ) + i );
            As2 = analyze( tx2, ty_XY, X, Y, N );
            int dist = hamming( A, As2 );
            if( dist < min_dist_XY ) {
                min_dist_XY = dist;
                min_tx = tx2;
                updated = true;
            }
        }
        if( updated ) {
            tx_XY = min_tx;
        }
    }

    //  Y, second
    updated = true;
    while( updated ) {
        std::vector< int > min_ty;
        std::vector< int > ty2;
        std::vector< int > As2;
        updated = false;
        for( int i = 1; i < ty_XY.size( ) - 1; i++ ) {
            ty2 = ty_XY;
            ty2.erase( ty2.begin( ) + i );
            As2 = analyze( tx_XY, ty2, X, Y, N );
            int dist = hamming( A, As2 );
            if( dist < min_dist_XY ) {
                min_dist_XY = dist;
                min_ty = ty2;
                updated = true;
            }
        }
        if( updated ) {
            ty_XY = min_ty;
        }
    }

    //  Y-X
    int min_dist_YX = hamming( A, As );
    tx_YX = tx_org;
    ty_YX = ty_org;
    //  X, second
    updated = true;
    while( updated ) {
        std::vector< int > min_tx;
        std::vector< int > tx2;
        std::vector< int > As2;
        updated = false;
        for( int i = 1; i < tx_YX.size( ) - 1; i++ ) {
            tx2 = tx;
            tx2.erase( tx2.begin( ) + i );
            As2 = analyze( tx2, ty_YX, X, Y, N );
            int dist = hamming( A, As2 );
            if( dist < min_dist_YX ) {
                min_dist_YX = dist;
                min_tx = tx2;
                updated = true;
            }
        }
        if( updated ) {
            tx_YX = min_tx;
        }
    }

    //  Y, second
    updated = true;
    while( updated ) {
        std::vector< int > min_ty;
        std::vector< int > ty2;
        std::vector< int > As2;
        updated = false;
        for( int i = 1; i < ty_YX.size( ) - 1; i++ ) {
            ty2 = ty_YX;
            ty2.erase( ty2.begin( ) + i );
            As2 = analyze( tx_YX, ty2, X, Y, N );
            int dist = hamming( A, As2 );
            if( dist < min_dist_YX ) {
                min_dist_YX = dist;
                min_ty = ty2;
                updated = true;
            }
        }
        if( updated ) {
            ty_YX = min_ty;
        }
    }

    if()
    //  Write the solution
    std::cout << tx.size( ) + ty.size( ) << std::endl;
    for( auto x : tx ) {
        std::cout << x << " " << tmin << " " << x << " " << tmax << std::endl;
    }
    for( auto y : ty ) {
        std::cout << tmin << " " << y << " " << tmax << " " << y << std::endl;
    }

    //  Finalize
    return ( 0 );
}
