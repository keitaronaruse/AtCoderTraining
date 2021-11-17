/*
    ABC088B - Card Game for Two
        https://atcoder.jp/contests/abs/tasks/abc088_b
        Author: Keitaro Naruse
        Date:   2021-11-17
        MIT License
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool compare( const size_t& a, const size_t& b)
{
    return( a > b );
}

int main()
{
    //  Read N
    size_t N( 0 );
    std::cin >> N;
    // std::cerr << N << std::endl;

    //  Read ai's
    std::vector< size_t > cards( N );
    for( size_t i = 0; i != N; i++ ) {
        std::cin >> cards.at( i );
        // std::cerr << cards.at( i ) << " ";
    }
    // std::cerr << std::endl;

    //  Sort cards
    std::vector< size_t > sorted_card( cards );
    std::sort( sorted_card.begin(), sorted_card.end(), compare );

    //  Max point calculation
    size_t A( 0 ), B( 0 );
    for( size_t i = 0; i < N; i+=2 ) {
        A += sorted_card.at( i );
        if( i != N - 1) {
            B += sorted_card.at( i+1 );
        }
    }

    //  Print the result
    std::cout << A - B << std::endl;

    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;

    return( 0 );
}
