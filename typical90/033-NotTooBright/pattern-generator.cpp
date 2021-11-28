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

int main()
{
    //  Initialize
    //  Read H and W
    int H = 0, W = 0;
    std::cin >> H >> W;
    //  Debug
    // std::cerr << H << " " << W << std::endl;

    //  Main
    //  Make and disply all possible patterns
    std::vector< std::vector<char> > pattern( H, std::vector<char>( W, '.') );
    for( int i = 0; i != H; i++ ) {
        for( int j = 0; j != W; j++ ) {
            ;
        }
    } 

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}