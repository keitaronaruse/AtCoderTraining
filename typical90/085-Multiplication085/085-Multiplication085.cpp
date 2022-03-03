/*
* @file 085-Multiplication085.cpp
* @brief 085 - Multiplication 085（★4）
* @author Keitaro Naruse
* @date 2022-02-08, 2022-03-02
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_cg
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Read K = [ 1,10^12 ]
    long long K = 0LL;
    std::cin >> K;
    if( Debug ) {
        std::cerr << K << std::endl;
    }

    //  Main
    //  Diviors of K, not including K itself
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

    //  Find solution
    long long num_comb = 0LL;
    for( size_t i = 0; i < divisors.size(); i ++ ) {
        long long a = divisors.at( i );
        for( size_t j = 0; j < divisors.size(); j ++ ) {
            long long b = divisors.at( j );
            if( K % a == 0LL && ( K / a ) % b == 0LL ) {
                long long c = K / a / b;
                if( a<= b && b <= c ) {
                    num_comb ++;
                    if( Debug ) {
                        std::cerr << a << " " << b << " " << c << std::endl;
                    }
                }
            }
        }
    }
    std::cout << num_comb << std::endl;
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
