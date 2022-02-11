/*
* @file 085-Multiplication085.cpp
* @brief 085 - Multiplication 085（★4）
* @author Keitaro Naruse
* @date 2022-02-08
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_cg
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = true;

int main()
{
    //  Read K = [ 1,10^12 ]
    long long K = 0LL;
    std::cin >> K;
    if( Debug ) {
        std::cerr << K << std::endl;
    }

    //  Main
    std::vector< long long > divisors;
    for( long long i = 1LL; i * i <= K; i ++ ) {
        if( K % i == 0LL )  {
            divisors.push_back( i );
            if( K / i != i ) {
                divisors.push_back( K / i );
            }
        }
    }
    std::sort( divisors.begin(), divisors.end() );
    
    if( Debug ) {
        for( auto d : divisors ) {
            std::cerr << d << " ";
        }
        std::cerr << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
