/*
    ABC086C - Traveling
        https://atcoder.jp/contests/abs/tasks/arc089_a
        Author: Keitaro Naruse
        Date:   2021-11-23
        MIT License
*/

#include <iostream>
#include <vector>
int main()
{
    //  Read N
    int N( 0 );
    std::cin >> N;
    //  Debug
    std::cerr << N << std::endl;

    //  Read (ti, xi, ni)
    std::vector< int > t( N, 0 );
    std::vector< int > x( N, 0 );
    std::vector< int > y( N, 0 );
    for( size_t i = 0; i != N; i++ ) {
        std::cin >> t.at( i ) >> x.at( i ) >> y.at( i );
        //  Debug
        std::cerr << t.at( i ) << " " << x.at( i ) << " " << y.at( i )<< std::endl;
    }

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}