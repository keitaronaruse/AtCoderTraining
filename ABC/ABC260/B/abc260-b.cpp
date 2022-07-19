/**
 * @file abc260-b.cpp
 * @brief ABC260 Problem B - Better Students Are Needed!
 * @author Keitaro Naruse
 * @date 2022-07-17, 2022-07-19
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc260/tasks/abc260_b
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

class IAB {
   public:
    int I, A, B;
};

int main( ) {
    //  Read N = [ 1, 10^3 ], X, Y, Z = [ 0, N ]
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;
    //  Read Ai = [ 0, 100 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }
    //  Read Bi = [ 0, 100 ]
    std::vector< int > B( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> B.at( i );
    }

    //  Main
    //  Preprocess
    std::vector< bool > Q( N, false );
    std::vector< IAB > P( N );
    for( int i = 0; i < N; i++ ) {
        P.at( i ).I = i;
        P.at( i ).A = A.at( i );
        P.at( i ).B = B.at( i );
    }
    //  sort by A
    std::sort( P.begin( ), P.end( ), []( const IAB& a, const IAB& b ) {
        if( a.A == b.A ) {
            return ( a.I < b.I );
        } else {
            return ( a.A > b.A );
        }
    } );
    //  Take top X
    int k = 0;
    for( int i = 0; i < N; i++ ) {
        if( k < X ) {
            if( !Q.at( P.at( i ).I ) ) {
                Q.at( P.at( i ).I ) = true;
                k++;
            }
        }
    }
    //  sort by B
    std::sort( P.begin( ), P.end( ), []( const IAB& a, const IAB& b ) {
        if( a.B == b.B ) {
            return ( a.I < b.I );
        } else {
            return ( a.B > b.B );
        }
    } );
    //  Take top Y
    k = 0;
    for( int i = 0; i < N; i++ ) {
        if( k < Y ) {
            if( !Q.at( P.at( i ).I ) ) {
                Q.at( P.at( i ).I ) = true;
                k++;
            }
        }
    }
    //  sort by A + B
    std::sort( P.begin( ), P.end( ), []( const IAB& a, const IAB& b ) {
        if( a.A + a.B == b.A + b.B ) {
            return ( a.I < b.I );
        } else {
            return ( a.A + a.B > b.A + b.B );
        }
    } );
    //  Take top Z
    k = 0;
    for( int i = 0; i < N; i++ ) {
        if( k < Z ) {
            if( !Q.at( P.at( i ).I ) ) {
                Q.at( P.at( i ).I ) = true;
                k++;
            }
        }
    }
    //  Display the solution
    for( int i = 0; i < N; i++ ) {
        if( Q.at( i ) ) {
            std::cout << i + 1 << std::endl;
        }
    }
    //  Finalize
    return ( 0 );
}
