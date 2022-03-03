/*
    008 - AtCounter（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_h
        Author: Keitaro Naruse
        Date:   2022-01-04
        MIT License
*/

// # Solution
// - DP

#include <iostream>
#include <vector>
#include <string>

const long long Large_Prime = 1000000007LL;
const bool Debug = false;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read S
    std::string S;
    std::cin >> S;
    if( Debug ) {
        std::cerr << S << std::endl;
    }
    
    //  Main
    const int K = 7;
    std::vector< std::vector< long long > > dp( K, std::vector< long long >( N + 1, 0LL ) );
    for( int i = 0; i < N; i ++ ) {
        //  Basic update
        for( int k = 0; k < K; k ++ ) {
            dp.at( k ).at( i + 1 ) = dp.at( k ).at( i );
        }
        //  Update by characters
        int k = 0;
        switch( S.at( i ) ) {
            case 'a': k = 0; dp.at( k ).at( i + 1 ) ++; break;
            case 't': k = 1; dp.at( k ).at( i + 1 ) = ( dp.at( k ).at( i ) + dp.at( k - 1 ).at( i ) ) % Large_Prime; break;
            case 'c': k = 2; dp.at( k ).at( i + 1 ) = ( dp.at( k ).at( i ) + dp.at( k - 1 ).at( i ) ) % Large_Prime; break;
            case 'o': k = 3; dp.at( k ).at( i + 1 ) = ( dp.at( k ).at( i ) + dp.at( k - 1 ).at( i ) ) % Large_Prime; break;
            case 'd': k = 4; dp.at( k ).at( i + 1 ) = ( dp.at( k ).at( i ) + dp.at( k - 1 ).at( i ) ) % Large_Prime; break;
            case 'e': k = 5; dp.at( k ).at( i + 1 ) = ( dp.at( k ).at( i ) + dp.at( k - 1 ).at( i ) ) % Large_Prime; break;
            case 'r': k = 6; dp.at( k ).at( i + 1 ) = ( dp.at( k ).at( i ) + dp.at( k - 1 ).at( i ) ) % Large_Prime; break;
            default: break;
        }
    } 
    if( Debug ) {
        for( int k = 0; k < K; k ++ ) {
            for( int i = 0; i <= N; i ++ ) {
                std::cerr << dp.at( k ).at( i ) << " ";
            }
            std::cerr << std::endl;
        }
    }

    //  Display result
    std::cout << dp.at( K - 1 ).at( N ) << std::endl; 

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
