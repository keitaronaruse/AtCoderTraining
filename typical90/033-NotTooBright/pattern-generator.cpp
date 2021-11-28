/*
    Patter generator
    033 - Not Too Bright
        https://atcoder.jp/contests/typical90/tasks/typical90_ag
        Author: Keitaro Naruse
        Date:   2021-11-28
        MIT License
*/

#include <iostream>
#include <vector>
#include <bitset>

int main()
{
    //  Initialize
    const size_t H = 5, W = 5;

    //  Main
    //  Make and disply all possible patterns
    for( int i = 0; i != ( 1 << H + W ); i ++ ) {
        std::bitset< ( H + W ) > b( i );
        std::cout << b << std::endl;
    }

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}