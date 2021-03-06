/*
    ABC083B - Some Sums
        https://atcoder.jp/contests/abs/tasks/abc083_b
        Author: Keitaro Naruse
        Date:   2021-11-17
        MIT License
*/

#include <iostream>
#include <cstdio>

int main()
{
    size_t N( 0 ), A( 0 ), B( 0 );
    //  Read N, A, B
    std::cin >> N >> A >> B;
    //  Debug
    std::cerr << N << " " << A << " " << B << std::endl;

    //  Assume we have five digits number
    const size_t M = 5;
    char buf[ M+1 ];
    size_t total( 0 );
    for( size_t i = 1; i != N+1; i++ ) {
        //  Make five digits as characters
        std::sprintf( buf, "%05lu", i );

        //  Calculate the sum of each of the digits 
        size_t small_sum( 0 );
        for( size_t j = 0; j != M ; j++ ) {
           small_sum += buf[ j ] - '0';
        }

        //  Sum it up if it meets the conditions
        if( ( A<= small_sum ) && ( small_sum <= B ) ) {
            total += i ;
        }
    }
    //  Finalize
    std::cout << total << std::endl;

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;

    return( 0 );
}
