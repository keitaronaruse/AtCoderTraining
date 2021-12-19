/*
    064 - Uplift（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bl
        Author: Keitaro Naruse
        Date:   2021-12-19
        MIT License
*/

// # Solution
// - The Uplift does no chage the incovenience in the middle points. 
// - The inconvenience between Li - 1 and Li, and 
// - The inconvenience between Ri and Ri + 1
// - B_L  = E_{ L - 1 } - E_L 
// - B_L' = E_{ L - 1}  - ( E_L + V_j ) = B_L - V_j
// - B_R  = E_R - E_{ R + 1 }
// - B_R' = E_R + V_j - E_{ R + 1 } - E_{ R + 1 }  = B_R + V_j


#include <iostream>
#include <vector>

/*
    inconv()
        returns the inconvenience of the arguments
*/
int inconvenie( int a, int b )
{
    return( ( a > b )? a - b : b - a ); 
}

int main()
{
    //  Initialize
    //  Read N and Q
    int N = 0, Q = 0;
    std::cin >> N >> Q;
    
    //  Read Ai and make Ei
    std::vector< int > A( N, 0 ), E( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        E.at( i ) = A.at( i );
    }
    //  Calculate the initial inconvenience
    long long SumInconvenience = 0LL;
    for( int i = 0; i < N - 1; i ++ ) {
        SumInconvenience += ( long long ) inconvenie( E.at( i ), E.at( i + 1 ) );
    }

    //  Main
    std::vector< int > L( Q, 0 ), R( Q, 0 ), V( Q, 0 );
    for( int j = 0; j < Q; j ++ ) {
        //  Read Lj, Rj, Vj
        std::cin >> L.at( j ) >> R.at( j ) >> V.at( j );

        //  Changes of the inconveniences apper at (L-1, L) and (R, R+1)
        
        //  L = 1
        //  E1'=E1 + V, E2'=E2+V, E1'-E2'=E1-E2
        //  L = 2
        //  E1'=E1, E_2'=E2+V, E_1'-E2' = E1-E2-V
        
        //  R = N
        //  EN-1'=EN-1+V, EN'=EN+V, EN-1'-EN'=EN-1-EN 
        //  R = N-1
        //  EN-1'=EN-1+V, EN'=EN, EN-1'-EN'=EN-1-EN+V 
        
        if( L.at( j ) - 2 >=  0) {
            SumInconvenience 
            -= ( long long ) inconvenie( E.at( L.at( j ) - 2 ), E.at( L.at( j ) - 1 ) );
        }
        if( R.at( j ) < N ) {
            SumInconvenience 
            -= ( long long ) inconvenie( E.at( R.at( j ) - 1 ), E.at( R.at( j ) ) );
        }

        //  Update the elevation Ei
        for( int i = L.at( j ) - 1; i <= R.at( j ) - 1; i ++ ) {
            E.at( i ) += V.at( j );
        }

        if( L.at( j ) - 2 >=  0) {
            SumInconvenience 
            += ( long long ) inconvenie( E.at( L.at( j ) - 2 ), E.at( L.at( j ) - 1 ) );
        }
        if( R.at( j ) < N ) {
            SumInconvenience 
            += ( long long ) inconvenie( E.at( R.at( j ) - 1 ), E.at( R.at( j ) ) );
        }

        //  Display result
        std::cout << SumInconvenience << std::endl;
    }
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
