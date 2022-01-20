/**
* @file 009-BruteForce2.cpp 
* @brief 009 - Brute Force 2
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
*/

#include <iostream>
#include <vector>

const bool Debug = false; 

int main()
{
    //  Read N = [ 1, 60 ] and S = [ 1, 10000 ]
    int N = 0, S = 0;
    std::cin >> N >> S;
    if( Debug ) {
        std::cerr << N << " " << S << std::endl;
    }

    //  Read Ai = [ 1, 10000 ]
    std::vector< int > A( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    if( Debug ) {
        for( int i = 0; i <= N; i ++ ) {
            std::cerr << A.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main: Solution by DP
    //  dp.at( i = [ 1, N ] ).at( k = [ 1, S ] )
    //  i: the items up to i, k: the sum is k 
    //  dp.size: N * S = 60 * 10000 = 600,000
    std::vector< std::vector< bool > > dp( N + 1, std::vector< bool >( S + 1, false ) ); 
    //  Initial value: The sum of no item ( i = 0 ) is k = 0 
    dp.at( 0 ).at( 0 ) = true;
    //  Loop
    for( int i = 0; i < N; i ++ ) {
        for( int k = 0; k <= S; k ++ ) {
            //  If we do not take Ai, the possibility follows the precious one
            dp.at( i + 1 ).at( k ) = dp.at( i ).at( k );
            //  If we do take Ai, the possibility follows the precious one
            if( k - A.at( i ) >= 0 ) {
                if( dp.at( i ).at( k - A.at( i ) ) ) {
                    dp.at( i + 1 ).at( k ) = true;
                }
            }
        }
    }

    //  Display the result
    if( dp.at( N ).at( S ) ) {
        std::cout << "Yes" << std::endl;
    } 
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
