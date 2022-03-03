/**
* @file arc135-b.cpp
* @brief ARC135 Problem B - Sum of Three Terms
* @author Keitaro Naruse
* @date 2022-02-15, 2022-03-03
* @copyright MIT License
* @details https://atcoder.jp/contests/arc135/tasks/arc135_b
*/

// # Solution
// - S_i = A_i + A_{i+1} + A_{i+2}
// - A_{i+2} = S_i - A_{i+1} - A_i
//   - A1 = a
//   - A2 = b
//   - A3 = S1 - A2 - A1 = S1 - b - a
//   - A4 = S2 - A3 - A2 = S2 - (S1 - A2 - A1 ) - A2 = S2 - S1 + A1 
//   - A5 = S3 - A4 - A3 = S3 - (S2 - S1 + A1 ) - (S1 - A2 - A1) = S3 - S2 + A2 
//   - A6 = S4 - A5 - A4 = S4 - (S3 - S2 + A2 ) - (S2 - A3 - A2) = S4 - S3 + A3 
// - X_{i+3} = S_{i+1} - X_{i+2} - X_{i+1}
//           = S_{i+1} - ( S_i - X_{i+1} - X_i ) - X_{i+1}
//           = S_{i+1} - S_i + X_i

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 3 * 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read Si
    std::vector< long long > S( N, 0 );
    // std::vector< int > S( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> S.at( i );
    }
    if( Debug ) {
        std::cerr << S << std::endl;
    }

    //  Main
    //  Make Xi
    std::vector< long long > X( N + 2, 0 );
    X.at( 0 ) = 0;
    X.at( 1 ) = 0;
    for( int i = 2; i < N + 2; i ++ ) {
        X.at( i ) = S.at( i - 2 ) - X.at( i - 1 ) - X.at( i - 2 );
    }
    if( Debug ) {
        std::cerr << X << std::endl;
    }
    //  Find the solution 
    long long c1 = -X.at( 0 ), c2 = -X.at( 1 ), c3 = X.at( 2 );
    for( int i = 0; i < N + 2; i ++ ) {
        switch( i % 3 ) {
            case 0: c1 = std::max( c1, -X.at( i ) ); break;
            case 1: c2 = std::max( c2, -X.at( i ) ); break;
            case 2: c3 = std::min( c3,  X.at( i ) ); break;
            default: break;
        }
    }
    if( Debug ) {
        std::cerr << c1 << " " << c2 << " " << c3 << std::endl;
    }

    //  Judge
    std::vector< long long > A( N + 2, 0 );
    if( ( c1 + c2 ) <= c3 ) {
        std::cout << "Yes" << std::endl;
        for( int i = 0; i < N + 2; i ++ ) {
            switch( i % 3 ) {
                case 0: A.at( i ) = X.at( i ) + c1; break;
                case 1: A.at( i ) = X.at( i ) + c2; break;
                case 2: A.at( i ) = X.at( i ) - c1 - c2; break;
                default: break;
            }
        }
        std::cout << A << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }


    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
