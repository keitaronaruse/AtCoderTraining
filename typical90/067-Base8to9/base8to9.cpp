/*
    067 - Base 8 to 9（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bo
        Author: Keitaro Naruse
        Date:   2021-12-01, 2021-12-02
        MIT License
*/

// # Solution

#include <iostream>
#include <string>
#include <algorithm>

/*
    covert_from_8_radix_to_9_radix()
        returns a std::string of 9_radix converted from a given 8-radix string  
*/
std::string covert_from_8_radix_to_9_radix( const std::string& digit_8 )
{
    //  Decode an 8-radix string to a numerical value
    long long value = 0LL;
    long long value_digit_8_radix = 1LL;
    for( int i = digit_8.size() - 1; i != -1; i -- ) {
        value += ( digit_8.at( i ) - '0' ) * value_digit_8_radix;
        value_digit_8_radix *= 8LL;
    }
    //  Debug
    // std::cerr << "value: " << value << std::endl;

    //  Encode a numerical value to a 9-radix string
    std::string digit_9_reversed;
    while( value != 0 ) {
        long long r = value % 9LL;
        digit_9_reversed.push_back( r + '0' );
        value /= 9LL;
    }
    return( std::string( digit_9_reversed.rbegin(), digit_9_reversed.rend() ) );
}

/*
    covert_from_9_radix_to_8_radix()
        returns a std::string of 8_radix converted from a given 9-radix string  
*/
std::string covert_from_9_radix_to_8_radix( const std::string& digit_9 )
{
    //  Decode a 9-radix string to a numerical value
    long long value = 0LL;
    long long value_digit_9_radix = 1LL;
    for( int i = digit_9.size() - 1; i != -1; i -- ) {
        value += ( digit_9.at( i ) - '0' ) * value_digit_9_radix;
        value_digit_9_radix *= 9LL;
    }
    //  Debug
    // std::cerr << "value: " << value << std::endl;

    //  Encode a numerical value to an 8-radix string
    std::string digit_8_reversed;
    while( value != 0 ) {
        long long r = value % 8LL;
        digit_8_reversed.push_back( r + '0' );
        value /= 8LL;
    }
    return( std::string( digit_8_reversed.rbegin(), digit_8_reversed.rend() ) );
}

int main()
{
    //  Read N
    std::string N;
    std::cin >> N;
    //  Debug
    // std::cerr << N << std::endl;

    //  Read K
    int K = 0;
    std::cin >> K;
    //  Debug
    // std::cerr << K << std::endl;
    
    //  Main
    std::string digit_8 = N;
    for( int k = 0; k != K; k ++ ) {
        //  Debug
        // std::cerr << "8-radix string: " << digit_8 << std::endl;

        //  Convert a 8-radix string to a 9-radix string
        std::string digit_9 = covert_from_8_radix_to_9_radix( digit_8 );
        //  Debug
        // std::cerr << "9-radix string: " << digit_9 << std::endl;

        //  Set the 9-radix string to a 8-radix string, changing a digit of 8 to 5
        digit_8 = digit_9;
        for( int i = 0; i != digit_8.size(); i ++ ) {
            if( digit_8.at( i ) == '8' ) {
                digit_8.at( i ) = '5';
            }
        }
        if( digit_8 == "" ) {
            digit_8 = "0";
        }

        //  Debug
        // std::cerr << "new 8-radix string: " << digit_8 << std::endl;
    }

    //  Display the result
    std::cout << digit_8 << std::endl;

    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
