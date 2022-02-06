/**
* @file abc238-c.cpp
* @brief ABC238 Problem C - digitnum
* @author Keitaro Naruse
* @date 2022-02-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc238/tasks/abc238_c
*/

// # Solution

#include <iostream>
#include <algorithm>

const bool Debug = true;
const long long Large_Prime = 998244353LL; 

int digit_num( long long x )
{
    int digits = 1;
    x /= 10LL;
    while( x != 0LL ) {
        digits ++;
        x /= 10LL;
    }
    return( digits );
}

long long sum_1_to_N_mod( long long n ) 
{
    long long sum = 0LL;
    sum = ( ( ( ( n + 1LL ) % Large_Prime ) * ( n % Large_Prime ) ) % Large_Prime ) / 2LL;
    return( sum );
}

long long sum_m_to_n_mod( long long m, long long n ) 
{
    long long sum = 0LL;
    sum = ( ( ( ( n + m ) % Large_Prime ) * ( ( n - m + 1LL) % Large_Prime ) ) % Large_Prime ) / 2LL;
    return( sum );
}

int main()
{
    //  Read N
    long long N = 0LL;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    } 

    //  Main
    long long ans = 0LL;
    int digits = digit_num( N );
    if( digits == 1 ) {
        ans = sum_m_to_n_mod( 1LL, N ); 
    }
    else {
        long long begin_val = 1LL;
        for( int i = 1; i < digits; i++ ) {
            ans += sum_m_to_n_mod( 1LL, 9 * begin_val + 1LL ); 
            begin_val *= 10LL;
        }
        ans += sum_m_to_n_mod( begin_val, N ); 
    }
    std::cout << ans << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
