/*
    064 - Uplift（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_bl
        Author: Keitaro Naruse
        Date:   2021-12-19
        MIT License
*/

// # Solution

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
    //  Read a problem
    //  Read N and Q
    int N = 0, Q = 0;
    std::cin >> N >> Q;
    // std::cerr << N << " "<< Q << std::endl;
    
    //  Read Ai and make Ei
    std::vector< int > A( N, 0 ), E( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        E.at( i ) = A.at( i );
        //  Debug
        // std::cerr << A.at( i ) << " ";
    }
    //  Debug
    // std::cerr << std::endl;

    //  Read Lj, Rj, Vj
    std::vector< int > L( Q, 0 ), R( Q, 0 ), V( Q, 0 );
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> L.at( j ) >> R.at( j ) >> V.at( j );
        //  Debug
        // std::cerr << L.at( j ) << " " << R.at( j ) << " " << V.at( j ) << std::endl;
    }

    //  Main
    //  Calculate the initial inconvenience
    long long SumInconvenie = 0LL;
    std::vector< int > InConvenie( N - 1, 0 );
    for( int i = 0; i < N - 1; i ++ ) {
        InConvenie.at( i ) = inconvenie( E.at( i ), E.at( i + 1 ) );
        SumInconvenie += ( long long ) InConvenie.at( i ) ;
    }
    //  Debug
    // for( int i = 0; i < N; i ++ ) {
    //     std::cerr << E.at( i ) << " ";
    // }
    // std::cerr << std::endl;
    // for( int i = 0; i < N - 1; i ++ ) {
    //     std::cerr << InConvenie.at( i ) << " ";
    // }
    // std::cerr << ": " << SumInconvenie << std::endl;

    //  Main
    for( int j = 0; j < Q; j ++ ) {
        //  Update the elevation Ei
        for( int i = L.at( j ) - 1; i <= R.at( j ) - 1; i ++ ) {
            E.at( i ) += V.at( j );
        }

        //  Update inconveniek
        for( int i = L.at( j ) - 1; i <= R.at( j ) - 1; i ++ ) {
            if( ( i == L.at( j ) - 1 ) && ( i - 1 >= 0 ) ) {
                //  Head and the previous exists
                SumInconvenie -= ( long long ) InConvenie.at( i - 1 ) ;
                InConvenie.at( i - 1 ) = inconvenie( E.at( i - 1 ), E.at( i ) );
                SumInconvenie += ( long long ) InConvenie.at( i - 1 ) ;
            }
            if( i + 1 < N ) {
                //  If the next exsits
                SumInconvenie -= ( long long ) InConvenie.at( i ) ;
                InConvenie.at( i ) = inconvenie( E.at( i ), E.at( i + 1 ) );
                SumInconvenie += ( long long ) InConvenie.at( i ) ;
            }
        }

        //  Debug
        // for( int i = 0; i < N; i ++ ) {
        //     std::cerr << E.at( i ) << " ";
        // }
        // std::cerr << std::endl;
        // for( int i = 0; i < N - 1; i ++ ) {
        //     std::cerr << InConvenie.at( i ) << " ";
        // }
        // std::cerr << ": " << SumInconvenie << std::endl;

        //  Display result
        std::cout << SumInconvenie << std::endl;
    }
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
