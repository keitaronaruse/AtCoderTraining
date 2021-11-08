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
    std::vector< std::vector<int> > dp_table( N + 1, std::vector<int>( W, 0 ) );
    // //  DP calculation
    // for( size_t i = 0; i != N; ++i ) {
    //     dp_table.at( i + 1 ) = std::max( dp_table.at( i ), dp_table.at( i ) + A.at( i ) );
    // }
    
    // //  Print DP result
    // std::cout << dp_table.at( N ) << std::endl;

    //  Finalize
    return( 0 );
}
