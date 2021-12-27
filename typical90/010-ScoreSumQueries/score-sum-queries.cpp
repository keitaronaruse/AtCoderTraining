/*
    010 - Score Sum Queries（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_j
        Author: Keitaro Naruse
        Date:   2021-11-27, 2021-12-27
        MIT License
*/

//  Solution: Memorization strategy of making a cumulation table for each of i

#include <iostream>
#include <vector>

//  Debug flag
const bool Debug = false;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Read Ci and Ni
    std::vector<int> C( N, 0 ), P( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> C.at( i ) >> P.at( i );
        C.at( i ) --;
        if( Debug ) {
            std::cerr << C.at( i ) + 1 << " " << P.at( i ) << std::endl;
        }
    }
    //  Memorization strategy: Make a cumulative sum table up to i
    const int K = 2;
    std::vector< std::vector< int > > cumulation( K, std::vector< int >( N + 1, 0 ) );
    for( int i = 1; i <= N; i ++ ) {
        //  Make a cumulation sum table
        for( int k = 0; k < K; k ++ ) {
            cumulation.at( k ).at( i ) = cumulation.at( k ).at( i - 1 ) ;
        }
        cumulation.at( C.at( i - 1 ) ).at( i ) += P.at( i - 1 );
        //  Debug
        if( Debug ) {
            std::cerr << cumulation.at( 0 ).at( i ) << " " << cumulation.at( 1 ).at( i ) << std::endl;
        }
    }

    //  Read Q
    int Q = 0;
    std::cin >> Q;
    if( Debug ) {
        std::cerr << Q << std::endl;
    }
    //  Read Lj and Rj
    std::vector<int> L( Q, 0 ), R( Q, 0 ); 
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> L.at( j ) >> R.at( j );
        if( Debug ) {
            std::cerr << L.at( j ) << " " << R.at( j ) << std::endl;
        }
    }

    //  Main
    //  Calculate a sum from L to R by cumulation(R) - cumulation(L)
    for( int j = 0; j < Q; j ++ ) {
        //  Calulate and display the sum 
        std::cout
        << cumulation.at( 0 ).at( R.at( j ) ) - cumulation.at( 0 ).at( L.at( j ) - 1 ) 
        << " " 
        << cumulation.at( 1 ).at( R.at( j ) ) - cumulation.at( 1 ).at( L.at( j ) - 1 ) 
        << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
