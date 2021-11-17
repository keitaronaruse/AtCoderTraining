/*
    ABC087B Coins
        https://atcoder.jp/contests/abs/tasks/abc087_b
        Author: Keitaro Naruse
        Date:   2021-11-17
        MIT License
*/

#include <iostream>
#include <vector>

int main()
{
    size_t A( 0 ), B( 0 ), C( 0 ), X( 0 );

    //  Read A, B, C, X
    //  A: the number of 500 coins
    //  B: the number of 100 coins
    //  C: the number of  50 coins
    //  X: a target price
    std::cin >> A >> B >> C >> X;
    // std::cout << A << " " << B << " " << C << " " << X << std::endl;

    //  Look-up table of prices by the number of 500 coins
    std::vector< size_t > price_table_500_coins( A+1 );
    for( size_t i = 0; i != A+1; ++i ) {
        price_table_500_coins.at( i ) = 500 * i;
        // std::cerr << price_table_500_coins.at( i ) << " ";
    }
    // std::cerr << std::endl;

    //  Look-up table of prices by the number of 100 coins
    std::vector< size_t > price_table_100_coins( B+1 );
    for( size_t j = 0; j != B+1; ++j ) {
        price_table_100_coins.at( j ) = 100 * j;
        // std::cerr << price_table_100_coins.at( j ) << " ";
    }
    // std::cerr << std::endl;

    //  Look-up table of prices by the number of 50 coins
    std::vector< size_t > price_table_50_coins( C+1 );
    for( size_t k = 0; k != C+1; ++k ) {
        price_table_50_coins.at( k ) = 50 * k;
        // std::cerr << price_table_50_coins.at( k ) << " ";
    }
    // std::cerr << std::endl;

    //  Couting up
    int combinations( 0 );
    for( size_t i = 0; i != A+1; ++i ) {
        if( X >= price_table_500_coins.at( i ) ) {
            for( size_t j = 0; j != B+1; ++j ) {
                if( X >= price_table_500_coins.at( i ) + price_table_100_coins.at( j ) ) {
                    for( size_t k = 0; k != C+1; ++k ) {
                        if( X == price_table_500_coins.at( i ) + price_table_100_coins.at( j ) + price_table_50_coins.at( k ) ) {
                            ++combinations;
                        }
                    }
                }
            }
        }
    }

    //  Results
    std::cout << combinations << std::endl;

    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
