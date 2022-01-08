/*
    ABC234 Problem C - Happy New Year!
        https://atcoder.jp/contests/abc234/tasks/abc234_c
        Author: Keitaro Naruse
        Date:   2022-01-08
        MIT License
*/

// # Solution
// - Consider a two-digit value of 0 and 2 as a a bit string
// - Replace 1 in the bit string as 2

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Read K
    long long K = 0LL;
    std::cin >> K;
    if( Debug ) {
        std::cerr << K << std::endl;
    }

    //  Main
    const int B = 64; 
    std::bitset< B > b( K );
    std::string S = b.to_string();
    if( Debug ) {
        std::cerr << S << std::endl;
    }

    std::string::iterator it = std::find( S.begin(), S.end(), '1' );
    std::string T = std::string( it, S.end() );
    if( Debug ) {
        std::cerr << T << std::endl;
    }
    for( it = T.begin(); it < T.end(); it ++ ) {
        if( *it == '1' ) {
            *it = '2';
        }
    }
    
    //  Display result
    std::cout << T << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
