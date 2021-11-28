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
    const size_t H = 2, W = 2;

    //  Main
    int max_ones = 0;
    //  Make and disply all possible patterns
    for( int k = ( 1 << H * W ) - 1; k != -1; k -- ) {
        bool isGood = true;
        std::bitset< ( H * W ) > b( k );
        for( int i = 0; isGood && ( i != H - 1 ); i ++ ) {
            for( int j = 0; isGood && j != W - 1; j ++ ) {
                int num_bit = 
                b[ W * i + j ] + b[ W * i + j + 1 ] 
                + b[ W * (i + 1) + j ] + b[ W * (i + 1) + j + 1 ];
                if( num_bit >= 2 ) {
                    isGood = false;
                }
            }
        }
        if( isGood ) {
            if( max_ones < b.count() ) {
                max_ones = b.count();
                std::cout << b << " " << max_ones << std::endl;
            }
        }
    }

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
