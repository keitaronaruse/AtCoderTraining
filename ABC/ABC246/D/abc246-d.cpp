/**
* @file abc246-d.cpp
* @brief ABC246 Problem D - 2-variable Function
* @author Keitaro Naruse
* @date 2022-04-02
* @copyright MIT License
* @details https://atcoder.jp/contests/abc246/tasks/abc246_d
*/

// # Solution

#include <iostream>
#include <algorithm>

int main()
{
    //  Read N = [ 0, 10^18 ]
    long long N;
    std::cin >> N;

    //  Main
    long long K = 0L;
    for( K = 0L; K * K * K <= N; K ++ ) {
        ;
    }
    std::cerr << K << std::endl;
    long long D = K * K * K - N;
    std::cerr << D << std::endl;
    for( long long a = 0L; a <= K / 2; a ++ ) {
        if( 2*K*a*a - 2*K*K*a + D > 0L ) {
            long long b = K - a;
            long long X = a*a*a + a*a*b + a*b*b + b*b*b;
            std::cerr << X << std::endl;
            break; 
        }
    }

    //  Finalize
    return( 0 );
}
