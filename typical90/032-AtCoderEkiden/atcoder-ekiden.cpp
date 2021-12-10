/*
    032 - AtCoder Ekiden（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_af
        Author: Keitaro Naruse
        Date:   2021-12-10
        MIT License
*/

// # Solution
// - Couting up all the combinations

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N and Aij
    int N = 0;
    std::cin >> N;
    //  Debug
    std::cerr << N << std::endl;
    //  Read Aij
    std::vector< std::vector<int> > A( N, std::vector<int>(N) );
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            std::cin >> A.at( i ).at( j );
            //  Debug
            std::cerr << A.at( i ).at( j ) << " ";
        }
        //  Debug
        std::cerr << std::endl;
    } 

    //  Read M and Xi Yi
    int M = 0;
    std::cin >> M;
    //  Debug
    std::cerr << M << std::endl;
    //  Read Xi, Yi
    std::vector<int> X( M ), Y( M );
    for( int i = 0; i < M; i ++ ) {
        std::cin >> X.at( i ) >> Y.at( i );
        //  Debug
        std::cerr << X.at( i ) << " " << Y.at( i ) << std::endl;
    }

    //  Main
    std::vector< int > assign( N );
    for( int i = 0; i < N; i ++) {
        assign.at( i ) = i;
    }
    do {
        int time = 0;
        for( int i = 0; i < N; i ++) {
            time += A.at( i ).at( assign.at( i ) );
        }
        //  Debug
        std::cerr << time << std::endl;
    } while( std::next_permutation( assign.begin(), assign.end() ) );

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
