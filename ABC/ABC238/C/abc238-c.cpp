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

const bool Debug = false;
const long long Prime = 998244353LL; 
long long Inv2 = 499122177LL;

long long modinv( long long a, long long m ) {
    long long b = m, u = 1LL, v = 0LL;
    while( b ) {
        long long t = a / b;
        a -= t * b; 
        std::swap( a, b );
        u -= t * v; 
        std::swap( u, v );
    }
    u %= m; 
    if( u < 0 ) {
        u += m;
    }
    return( u );
}

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

long long offset_sum_mod( long long begin_val, long long end_val )
{
    long long n = ( end_val - ( begin_val - 1LL ) ) % Prime;
    long long sum = ( ( ( n * ( n + 1LL ) ) % Prime ) * Inv2 ) % Prime;

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
    //  Preprocess
    Inv2 = modinv( 2LL, Prime );
    
    //  Main
    int digits = digit_num( N );
    long long ans = 0LL;
    long long min_val = 1LL, max_val = 10LL;
    if( digits == 1 ) {
        ans += offset_sum_mod( 1LL, N );
    }
    else {
        long long min_val = 1LL, max_val = 10LL;
        for( int i = 1; i < digits; i ++ ) {
            ans += offset_sum_mod( min_val, max_val - 1LL );
            ans %= Prime;
            min_val *= 10LL;
            max_val *= 10LL;
        } 
        ans += offset_sum_mod( min_val, N );
        ans %= Prime;
    }
    std::cout << ans << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
