/*
    ABC087B Coins
        Author: Keitaro Naruse
        Date:   2021-11-16
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
    std::cout << A << " " << B << " " << C << " " << X << std::endl;

    //  Look-up table of prices by the number of 500 coins
    std::vector< size_t > price_table_500_coins( A+1 );
    for(size_t i = 0; i != A+1; i++) {
        price_table_500_coins.at( i ) = 500 * i;
        std::cerr << price_table_500_coins.at( i ) << " ";
    }
    std::cerr << std::endl;
    //  Look-up table of prices by the number of 100 coins
    std::vector< size_t > price_table_100_coins( B+1 );
    for(size_t i = 0; i != B+1; i++) {
        price_table_100_coins.at( i ) = 100 * i;
        std::cerr << price_table_100_coins.at( i ) << " ";
    }
    std::cerr << std::endl;
    //  Look-up table of prices by the number of 50 coins
    std::vector< size_t > price_table_50_coins( C+1 );
    for(size_t i = 0; i != C+1; i++) {
        price_table_50_coins.at( i ) = 50 * i;
        std::cerr << price_table_50_coins.at( i ) << " ";
    }
    std::cerr << std::endl;

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
