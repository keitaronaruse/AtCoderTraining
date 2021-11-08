/*
    ABC087B Coins
        Author: Keitaro Naruse
        Date:   2021-11-08
        MIT License
*/

#include <iostream>
#include <vector>

int main()
{
    int A( 0 ), B( 0 ), C( 0 ), X( 0 );

    //  Read A, B, C, X
    std::cin >> A >> B >> C >> X;
    std::cout << A << " " << B << " " << C << " " << X << std::endl;

    //  Solve this problem by dynamic programming
    //  The number of coins
    int N( A + B + C ); 
    std::cout << N << std::endl;
    //  The total ammount of money scaled by 50-yen
    int W( X / 50 ); 
    std::cout << W << std::endl;
    //  The ammount of money of each of the coins scaled by 50-yen
    std::vector<int> w( N );
    for( size_t i = 0; i != A; ++i ) {
        w.push_back( 10 );
        std::cout << "10 ";
    }
    for( size_t i = 0; i != B; ++i ) {
        w.push_back( 2 );
        std::cout << "2 ";
    }
    for( size_t i = 0; i != C; ++i ) {
        w.push_back( 1 );
        std::cout << "1 ";
    }
    std::cout << std::endl;

    //  DP table
    std::vector< std::vector< int > > dp( N + 1, std::vector<int>( W + 1, 0 ) );
    dp.at( 0 ).at( 0 ) = 1;
    //  DP calculation
    for( size_t i = 0; i != N; ++i ) {
        for( size_t j = 0; j != W + 1; ++j ) {
            if( w.at( i ) <= j ) {
                dp.at( i + 1 ).at( j ) = dp.at( i ).at( j - w.at( i ) ) + dp.at( i ).at( j );
            }
            else {
                dp.at( i + 1 ).at( j ) = dp.at( i ).at( j );
            }
        }
    }

    std::cout << dp.at( N ).at( W ) << std::endl;
    return( 0 );
}
