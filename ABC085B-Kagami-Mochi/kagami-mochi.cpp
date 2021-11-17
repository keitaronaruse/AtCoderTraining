/*
    ABC085B - Kagami Mochi 
        https://atcoder.jp/contests/abs/tasks/abc085_b
        Author: Keitaro Naruse
        Date:   2021-11-17
        MIT License
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N
    size_t N( 0 );
    std::cin >> N;
    std::cerr << N << std::endl;

    //  Read d
    std::vector< size_t > d( N );
    for( size_t i = 0; i != N; i++ ) {
        std::cin >> d.at( i );
        std::cerr << d.at( i ) << " ";
    }
    std::cerr << std::endl;

    //  Sort
    std::vector< size_t > sorted_d( d );
    std::sort( sorted_d.begin(), sorted_d.end() );
    for( size_t i = 0; i != N; i++ ) {
        std::cerr << sorted_d.at( i ) << " ";
    }
    std::cerr << std::endl;
    
    //  Count
    size_t steps( 1 ), prev_d = sorted_d.at( 0 );
    for( size_t i = 1; i != N; i++ ) {
        if( sorted_d.at( i ) != prev_d ) {
            steps ++;
        }
        prev_d = sorted_d.at( i );
    }
    
    //  Print the result
    std::cout << steps << std::endl;

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;

    return( 0 );
}
