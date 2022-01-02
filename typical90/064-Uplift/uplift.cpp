/*
    064 - Uplift（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bl
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-02 
        MIT License
*/

// # Solution
// - Store Bi = A(i) - A(i+1)
// - The sum of inconvenience changes at the two points of B(L-1) and B(R) 
//  - B(L-1) -= V, R(R) += V
// - Before update: Sum -= B(L-1), Sum -= B(R)
// - After update:  Sum += B(L-1), Sum -+ B(R)

#include <iostream>
#include <vector>

const bool Debug = false;

namespace nrs {
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 )? a : -a );
    }
}

int main()
{
    //  Initialize
    //  Read N and Q
    int N = 0, Q = 0;
    std::cin >> N >> Q;
    if( Debug ) {
        std::cerr << N << " " << Q << std::endl;
    }
    
    //  Read Ai and put to Ei
    std::vector< long long > E( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        int A = 0;
        std::cin >> A;
        E.at( i ) = A;
        if( Debug ) {
            std::cerr << A << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    //  Calculate Bi, the difference of Ei
    //  Calculate the initial inconvenience
    long long SumInconvenience = 0LL;
    std::vector< long long > B( N - 1, 0 );
    for( int i = 0; i < N - 1; i ++ ) {
        B.at( i ) = E.at( i ) - E.at( i + 1 );
        SumInconvenience += nrs::abs( B.at( i ) );
    }

    //  Main
    for( int j = 0; j < Q; j ++ ) {
        //  Read Lj, Rj, Vj
        int L = 0, R = 0, V = 0;
        std::cin >> L >> R >> V;
        if( Debug ) {
            std::cerr << L << " " << R << " " << V << std::endl;
        }
        L --; 
        R --;

        //  Main
        //  The changes of the inconveniences apper at B[L-1] and B[R]
        if( L - 1 >= 0 ) {
            SumInconvenience -= nrs::abs( B.at( L - 1 ) );
            B.at( L - 1 ) -= ( long long ) V;
            SumInconvenience += nrs::abs( B.at( L - 1 ) );
        }
        if( R + 1 < N ) {
            SumInconvenience -= nrs::abs( B.at( R ) );
            B.at( R ) += ( long long ) V;
            SumInconvenience += nrs::abs( B.at( R ) );
        }
        
        //  Display result
        std::cout << SumInconvenience << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
