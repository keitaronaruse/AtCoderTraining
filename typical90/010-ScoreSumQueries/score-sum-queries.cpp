/*
    010 - Score Sum Queries（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_j
        Author: Keitaro Naruse
        Date:   2021-11-27
        MIT License
*/

//  Solution: Memorization strategy of making a cumulation table for each of i

#include <iostream>
#include <vector>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    //  Debug
    // std::cerr << N << std::endl;

    //  Read Ci and Ni
    std::vector<int> C( N + 1, 0 ), P( N + 1, 0 );
    for( int i = 1; i != N + 1; i ++ ) {
        std::cin >> C.at( i ) >> P.at( i );
        //  Debug
        // std::cerr << C.at( i ) << " " << P.at( i ) << std::endl;
    }
    //  Memorization strategy: Make a cumulation table up to i
    std::vector< std::vector< int > > cumulation( 3, std::vector< int >( N + 1, 0 ) );
    for( int i = 1; i != N + 1; i ++ ) {
        //  Make a cumulation table up to i
        for( int k = 1; k != 3; k ++ ) {
            cumulation.at( k ).at( i ) = cumulation.at( k ).at( i - 1 ) ;
        }
        cumulation.at( C.at( i ) ).at( i ) += P.at( i );
        //  Debug
        // std::cerr << cumulation.at( 1 ).at( i ) << " " << cumulation.at( 2 ).at( i ) << std::endl;
    }

    //  Read Q
    int Q = 0;
    std::cin >> Q;
    //  Debug
    // std::cerr << Q << std::endl;
    //  Read Lj and Rj
    std::vector<int> L( Q + 1, 0 ), R( Q + 1, 0 ); 
    for( int j = 1; j != Q + 1; j ++ ) {
        std::cin >> L.at( j ) >> R.at( j );
        //  Debug
        // std::cerr << L.at( j ) << " " << R.at( j ) << std::endl;
    }

    //  Main
    //  Calculate a sum from L to R by cumulation(R) - cumulation(L)
    for( int j = 1; j != Q + 1; j ++ ) {
        //  Output
        std::cout
        << cumulation.at( 1 ).at( R.at( j ) ) - cumulation.at( 1 ).at( L.at( j ) - 1 ) 
        << " " 
        << cumulation.at( 2 ).at( R.at( j ) ) - cumulation.at( 2 ).at( L.at( j ) - 1 ) 
        << std::endl;
        // std::vector<int> sum( 3, 0 );
        // for( int i = L.at( j ); i != R.at( j ) + 1; i ++ ) {
        //     sum.at( C.at( i ) ) += P.at( i );
        // }
        //  Output
        // std::cout << sum.at( 1 ) << " " << sum.at( 2 ) << std::endl;
    }

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
