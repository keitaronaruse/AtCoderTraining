/*
    078 - Easy Graph Problem（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_bz
        Author: Keitaro Naruse
        Date:   2021-12-02
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read N, M
    int N = 0, M = 0;
    std::cin >> N >> M;
    //  Debug
    std::cerr << N << " " << M << std::endl;

    //  Read ai and bi
    std::vector<int> a( M, 0 ), b( M, 0 );
    for( size_t i = 0; i != M; i ++ ) {
        std::cin >> a.at( i ) >> b.at( i );
        //  Debug
        std::cerr << a.at( i ) << " " << b.at( i ) << std::endl;
    }
    
    //  Main

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
