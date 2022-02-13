/**
* @file arc135-a.cpp
* @brief ARC135 Problem A
* @author Keitaro Naruse
* @date 2022-02-13
* @copyright MIT License
* @details https://atcoder.jp/contests/arc135/tasks/arc135_a
*/

// # Solution

#include <iostream>
#include <map>

const bool Debug = false;

const long long Prime = 998244353LL;
std::map< long long , long long > lut;

long long floor_ceil_decomp( long long x )
{
    long long fx = ( x / 2LL );
    // long long fx = ( x / 2LL ) % Prime;
    if( lut[ fx ] == 0LL ) {
        lut[ fx ] = floor_ceil_decomp( fx );
    }

    long long cx;
    if( x % 2LL == 0LL ) {
        cx = fx;
    }
    else {
        // cx = (fx + 1LL) % Prime;
        cx = ( ( x + 1LL ) / 2LL );
        if( lut[ cx ] == 0LL ) {
            lut[ cx ] = floor_ceil_decomp( cx );
        } 
    }

    return( ( ( lut[ fx ] % Prime ) * ( lut[ cx ] % Prime ) ) % Prime );
}

int main()
{
    //  Read X = [ 1, 10^18 ]
    long long X = 0LL;
    std::cin >> X;
    if( Debug ) {
        std::cerr << X <<  std::endl;
    }

    //  Main
    lut[ 1LL ] = 1LL;
    lut[ 2LL ] = 2LL;
    lut[ 3LL ] = 3LL;
    lut[ 4LL ] = 4LL;

    long long prod = 1LL;
    // std::stack< long long > factors;
    if( X > 4LL ) {
        prod = floor_ceil_decomp( X );
    }
    else {
        prod = X;
    }

    if( Debug ) {
        for( auto p : lut ) {
            std::cerr << "( " << p.first << ", " << p.second << " ) ";
        }
        std::cerr << std::endl;
    }
    std::cout << prod << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
