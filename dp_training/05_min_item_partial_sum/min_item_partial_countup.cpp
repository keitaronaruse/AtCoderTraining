/*
    Minimum item partial countup problem
        in Knapsack DP: https://qiita.com/drken/items/a5e6fe22863b7992efdb
    Author: Keitaro Naruse
    Date:   2021-11-08
    MIT License
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N: the number of items
    size_t N( 0 );
    std::cin >> N;
    
    //  Read A: the target number
    size_t A( 0 );
    std::cin >> A;

    //  Read ai's: the values
    std::vector<int> a( N, 0 );
    for( size_t i = 0; i != N; ++i ) {
        std::cin >> a.at( i );
    }

    //  DP table
    std::vector< std::vector<size_t> > dp( N + 1, std::vector<size_t>( A + 1, 0 ) );
    dp.at( 0 ).at( 0 ) = true;
    //  DP calculation
    for( size_t i = 0; i != N; ++i ) {
        for( size_t j = 0; j != A + 1; ++j ) {
            if( a.at( i ) <= j ) {
                dp.at( i + 1 ).at( j ) = dp.at( i ).at( j - a.at( i ) ) + dp.at( i ).at( j );
            }
            else {
                dp.at( i + 1 ).at( j ) = dp.at( i ).at( j );
            }
        }
    }
    
    //  Print DP result
    std::cout << dp.at( N ).at( A ) << std::endl;

    //  Finalize
    return( 0 );
}
