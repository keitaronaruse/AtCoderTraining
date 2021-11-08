/*
    Knap Sack problem
        in Knapsack DP: https://qiita.com/drken/items/a5e6fe22863b7992efdb
    Author: Keitaro Naruse
    Date:   2021-11-07
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
    std::cout << N << std::endl;
    
    //  Read W: the weight limit
    size_t W( 0 );
    std::cin >> W;
    std::cout << W << std::endl;

    //  Read w and v: the weight and value
    std::vector<int> w( N, 0 ), v( N, 0 );
    for( size_t i = 0; i != N; ++i ) {
        std::cin >> w.at( i ) >> v.at( i );
        std::cout << w.at( i ) << " " << v.at( i ) << std::endl;
    }

    //  DP table
    std::vector< std::vector<int> > dp( N + 1, std::vector<int>( W + 1, 0 ) );
    //  DP calculation
    for( size_t i = 0; i != N; ++i ) {
        for( size_t j = 0; j != W + 1; ++j ) {
            if( w.at( i ) <= j ) {
                dp.at( i + 1 ).at( j ) = 
                std::max( dp.at( i ).at( j - w.at( i ) ) + v.at( i ), dp.at( i ).at( j ) );
            }
            else {
                dp.at( i + 1 ).at( j ) = dp.at( i ).at( j );
            }
        }
    }
    
    //  Print DP result
    std::cout << dp.at( N ).at( W ) << std::endl;

    //  Finalize
    return( 0 );
}
