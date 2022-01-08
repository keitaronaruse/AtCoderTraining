/*
    ABC234 Problem B - Longest Segment
        https://atcoder.jp/contests/abc234/tasks/abc234_b
        Author: Keitaro Naruse
        Date:   2022-01-08
        MIT License
*/

// # Solution
// - Define a function of the distance
// - Apply all the coombination of points

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

const bool Debug = false;

double dinstance( double xa, double ya, double xb, double yb )
{
    return( std::sqrt( std::pow( xa - xb, 2.0 ) + std::pow( ya - yb, 2.0 ) ) );
}

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read Ai
    std::vector< int > X( N, 0 ), Y(N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> X.at( i ) >> Y.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << X.at( i ) << " " << Y.at( i ) << std::endl;
        }
    }

    double max_dist = 0.0;
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            max_dist = std::max( 
                max_dist, 
                dinstance( X.at( i ), Y.at( i ), X.at( j ), Y.at( j ) )
            );
        }
    }
    //  Display result
    std::cout << std::fixed << std::setprecision( 10 ) << max_dist << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
