/*
    Maximum sum problem
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
    
    //  Read Ai: the number of values and store in vector
    std::vector<int> A( N, 0 );
    for( size_t i = 0; i != N; ++i ) {
        std::cin >> A.at( i ) ;
    }

    //  DP table
    std::vector<int> dp( N + 1, 0 );
    //  Initial value
    dp.at( 0 ) = 0;
    //  DP calculation
    for( size_t i = 0; i != N; ++i ) {
        dp.at( i + 1 ) = std::max( dp.at( i ), dp.at( i ) + A.at( i ) );
    }
    
    //  Print DP result
    std::cout << dp.at( N ) << std::endl;

    //  Finalize
    return( 0 );
}
