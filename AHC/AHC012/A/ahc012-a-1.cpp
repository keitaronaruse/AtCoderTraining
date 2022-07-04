/**
 * @file ahc012-a-1.cpp
 * @brief AHC012 Problem A - AtCoder 10th Anniversary
 * @author Keitaro Naruse
 * @date 2022-07-03
 * @copyright MIT License
 * @details https://atcoder.jp/contests/ahc012/tasks/ahc012_a
 */

// # Solution

#include <iostream>
#include <vector>

class Line {
   public:
    int px, py, qx, qy;
};

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
    std::vector< int > tx = { -10000, -9500, -9000, -8500, -8000, -7500, -7000,
                              -6500,  -6000, -5500, -5000, -4500, -4000, -3500,
                              -3000,  -2500, -2000, -1500, -1000, -500,  0,
                              500,    1000,  1500,  2000,  2500,  3000,  3500,
                              4000,   4500,  5000,  5500,  6000,  6500,  7000,
                              7500,   8000,  8500,  9000,  9500,  10000 };
    std::vector< int > ty = { -10000, -9500, -9000, -8500, -8000, -7500, -7000,
                              -6500,  -6000, -5500, -5000, -4500, -4000, -3500,
                              -3000,  -2500, -2000, -1500, -1000, -500,  0,
                              500,    1000,  1500,  2000,  2500,  3000,  3500,
                              4000,   4500,  5000,  5500,  6000,  6500,  7000,
                              7500,   8000,  8500,  9000,  9500,  10000 };
    std::vector< int > px( K ), py( K ), qx( K ), qy( K );
    int k = 0;
    for( auto x : tx ) {
        px.at( k ) = qx.at( k ) = x;
        py.at( k ) = tmin;
        qy.at( k ) = tmax;
        k++;
    }
    for( auto y : ty ) {
        px.at( k ) = tmin;
        qx.at( k ) = tmax;
        py.at( k ) = qy.at( k ) = y;
        k++;
    }
    std::cout << k << std::endl;
    for( int j = 0; j < k; j++ ) {
        std::cout << px.at( j ) << " " << py.at( j ) << " ";
        std::cout << qx.at( j ) << " " << qy.at( j ) << std::endl;
    }

    //  Finalize
    return ( 0 );
}
