/*
    064 - Uplift（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bl
        Author: Keitaro Naruse
        Date:   2021-12-19, 2021-12-21 
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>

long long my_abs( long long a )
{
    return( ( a > 0 )? a : -a );
}

int main()
{
    //  Initialize
    //  Read N and Q
    int N = 0, Q = 0;
    std::cin >> N >> Q;
    
    //  Read Ai and put to Ei
    std::vector< long long > E( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> E.at( i );
    }
    //  Calculate Bi, the difference of Ei
    //  Calculate the initial inconvenience
    long long SumInconvenience = 0LL;
    std::vector< long long > B( N - 1, 0 );
    for( int i = 0; i < N - 1; i ++ ) {
        B.at( i ) = E.at( i ) - E.at( i + 1 );
        SumInconvenience += my_abs( B.at( i ) );
    }

    //  Debug
    for( int i = 0; i < N; i ++ ) {
        std::cerr << E.at( i ) << " ";
    }
    std::cerr << std::endl;
    for( int i = 0; i < N - 1; i ++ ) {
        std::cerr << B.at( i ) << " ";
    }
    std::cerr << std::endl;

    //  Main
    for( int j = 0; j < Q; j ++ ) {
        int L = 0, R = 0, V = 0;
        //  Read Lj, Rj, Vj
        std::cin >> L >> R >> V;
        L --; 
        R --;
        //  Debug
        // std::cerr << L << " " << R << " " << V << std::endl;
        //  The changes of the inconveniences apper at ( L-1, L ) and ( R, R+1 )
        if( L - 1 >= 0 ) {
            SumInconvenience -= my_abs( B.at( L - 1 ) );
        }
        if( R + 1 < N ) {
            SumInconvenience -= my_abs( B.at( R ) );
        }
        
        //  Update the elevation Ei
        for( int i = L; i <= R; i ++ ) {
            E.at( i ) += V;
        }
        //  Update the difference of the elevation
        int b =  L - 1, e = R;

        if( b < 0 ) {
            b = 0;
        }
        if( e > N - 2 ) {
            e = N - 2;
        }
        for( int i = b; i <= e; i ++ ) {
            B.at( i ) = E.at( i ) - E.at( i + 1 );
        }

        //  Changes of the inconveniences apper at ( L-1, L ) and ( R, R+1 )
        if( L - 1 >= 0 ) {
            SumInconvenience += my_abs( B.at( L - 1 ) );
        }
        if( R + 1 < N ) {
            SumInconvenience += my_abs( B.at( R ) );
        }
        
        //  Display result
        // std::cout << SumInconvenience << std::endl;
        //  Debug
        for( int i = 0; i < N; i ++ ) {
            std::cerr << E.at( i ) << " ";
        }
        std::cerr << std::endl;
        for( int i = 0; i < N - 1; i ++ ) {
            std::cerr << B.at( i ) << " ";
        }
        std::cerr << std::endl;
    }
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
