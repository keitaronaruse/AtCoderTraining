/*
    ABC085C - Otoshidama
        https://atcoder.jp/contests/abs/tasks/abc085_c
        Author: Keitaro Naruse
        Date: 2021-11-18
        MIT License
*/

#include <iostream>

int main()
{
    //  Read N
    size_t N( 0 );
    std::cin >> N;
    
    //  Read Y
    size_t Y( 0 );
    std::cin >> Y;

    //  Debug
    std::cerr << N << " " << Y << std::endl;
    
    //  Finding the combination
    for( size_t i = 0; i <= N; i++ ) {
        for( size_t j = 0; j <= N - i; j++ ) {
            for( size_t k = 0; k <= N - i - j; k++ ) {
                size_t price = 10000 * i + 5000 * j + 1000 * k;
                if( (Y == price) and (N == i + j + k) ) {
                    std::cout << i << " " << j << " " << k << std::endl;
                    //  Finalize
                    std::cerr << "Normally teminated as found." << std::endl;
                    return( 0 );
                }
            }
        }
    }
    std::cout << "-1 -1 -1" << std::endl;

    //  Finalize
    std::cerr << "Normally teminated as not found." << std::endl;

    return( 0 );
}
