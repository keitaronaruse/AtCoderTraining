/**
 * @file abc260-b.cpp
 * @brief ABC260 Problem B - Better Students Are Needed!
 * @author Keitaro Naruse
 * @date 2022-07-17
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
    //  top X by A
    std::sort( P.begin( ), P.end( ), []( const IAB& a, const IAB& b ) {
        if( a.A == b.A ) {
            return ( a.I < b.I );
        } else {
            return ( a.A > b.A );
        }
    } );
    for( int i = 0; i < X; i++ ) {
        Q.at( P.at( i ).I ) = true;
        P.at( i ).A = -100;
        P.at( i ).B = -100;
    }
    //  top Y by B
    std::sort( P.begin( ), P.end( ), []( const IAB& a, const IAB& b ) {
        if( a.B == b.B ) {
            return ( a.I < b.I );
        } else {
            return ( a.B > b.B );
        }
    } );
    for( int i = 0; i < Y; i++ ) {
        Q.at( P.at( i ).I ) = true;
        P.at( i ).A = -100;
        P.at( i ).B = -100;
    }
    //  top Y by A + B
    std::sort( P.begin( ), P.end( ), []( const IAB& a, const IAB& b ) {
        if( a.A + a.B == b.A + b.B ) {
            return ( a.I < b.I );
        } else {
            return ( a.A + a.B > b.A + b.B );
        }
    } );
    for( int i = 0; i < Z; i++ ) {
        Q.at( P.at( i ).I ) = true;
        P.at( i ).A = -100;
        P.at( i ).B = -100;
    }
    for( int i = 0; i < N; i++ ) {
        if( Q.at( i ) ) {
            std::cout << i + 1 << std::endl;
        }
    }
    //  Finalize
    return ( 0 );
}
