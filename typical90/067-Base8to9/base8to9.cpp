/*
    067 - Base 8 to 9（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bo
        Author: Keitaro Naruse
        Date:   2021-12-01
        MIT License
*/

// # Solution

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    //  Read N
    std::string N;
    std::cin >> N;
    //  Debug
    std::cerr << N << std::endl;

    //  Read K
    int K = 0;
    std::cin >> K;
    //  Debug
    std::cerr << K << std::endl;
    
    //  Main
    std::string digit8 = N;
    for( int k = 0; k != K; k ++ ) {
        //  Decode an 8-radix string to a numerical value
        long long value = 0LL, value_of_radix = 1LL;
        for( int i = digit8.size() - 1; i != -1; i -- ) {
            value += ( digit8.at( i ) - '0' ) * value_of_radix;
            value_of_radix *= 8LL;
        }
        //  Debug
        // std::cerr << value << std::endl;
        //  Encode a numerical value to a 9-radix string
        //  If a digit is 8, change it to 5 
        std::string digit9_reversed;
        while( value != 0 ) {
            long long r = value % 9LL;
            if( r == 8LL ) {
                r = 5LL;
            }
            digit9_reversed.push_back( r + '0' );
            value /= 9LL;
        }
        std::string digit9( digit9_reversed.rbegin(), digit9_reversed.rend() );
        //  Debug
        std::cerr << digit9 << std::endl;

        //  Conver it to 8-radix string
        ;
    }

    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
