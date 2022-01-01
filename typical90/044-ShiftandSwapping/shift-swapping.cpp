/*
    044 - Shift and Swapping（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_ar
        Author: Keitaro Naruse
        Date:   2021-12-11, 2022-01-01
        MIT License
*/

// # Solution
// - Impliment by the ring buffer

const bool Debug = false;

#include <iostream>
#include <vector>
#include <utility>

int main()
{
    //  Read N and Q
    int N = 0, Q = 0;
    std::cin >> N >> Q;
    if( Debug ) {
        std::cerr << N << " " << Q << std::endl;
    }

    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        if( Debug ) {
            std::cerr << A.at( i ) << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    //  Read Tj, Xj, Yj
    std::vector< int > T( Q ), X( Q ), Y( Q );
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> T.at( j ) >> X.at( j ) >> Y.at( j );
        if( Debug ) {
            std::cerr << T.at( j ) << " " << X.at( j ) << " " << Y.at( j ) << std::endl;
        }
        X.at( j ) --;
        Y.at( j ) --;
    }

    //  Main
    int offset = 0;
    for( int j = 0; j < Q; j ++ ) {
        if( Debug ) {
            for( int i = 0; i < N; i ++  ) {
                std::cerr << A.at( ( i + offset ) % N ) << " ";
            }
            std::cerr << std::endl;
        }
        if( T.at( j ) == 1 ) {
            //  Swap
            std::swap( 
                A.at( ( X.at( j ) + offset ) % N ), 
                A.at( ( Y.at( j ) + offset ) % N ) 
            );
        }
        else if( T.at( j ) == 2 ) {
            //  Shift
            if( offset == 0 ) {
                offset = N - 1;
            }
            else {
                offset --;
            }
        }
        else if( T.at( j ) == 3 ) {
            //  Display
            std::cout << A.at( ( X.at( j ) + offset ) % N ) << std::endl;
        }
        else {
            std::cerr << "This should not be happend." << std::endl;
        }
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
