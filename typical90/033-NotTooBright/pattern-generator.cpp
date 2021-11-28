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
    //  Make and disply all possible patterns
    int num_good = 0;
    for( int k = 0; k != ( 1 << H + W ); k ++ ) {
        std::bitset< ( H + W ) > b( k );
        if( ( b.count() == 0 ) || ( b.count() == 1 ) ) {
            num_good ++;
            //  Debug
            std::cerr << b << std::endl;
            //  Debug
            //  b[0] b[1]
            //  b[2] b[3]
            // ( b[0] == true ) ? std::cerr << "#" : std::cerr << "."; 
            // ( b[1] == true ) ? std::cerr << "#" : std::cerr << ".";
            // std::cerr << std::endl; 
            // ( b[2] == true ) ? std::cerr << "#" : std::cerr << "."; 
            // ( b[3] == true ) ? std::cerr << "#" : std::cerr << ".";
            // std::cerr << std::endl; 
        }
    }

    //  Display result
    std::cout << num_good << std::endl;

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
