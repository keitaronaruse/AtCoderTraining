/**
* @file abc220-b.cpp
* @brief ABC220 Problem B - Base K
* @author Keitaro Naruse
* @date 2022-04-08
* @copyright MIT License
* @details https://atcoder.jp/contests/abc220/tasks/abc220_b
*/

// # Solution

#include <iostream>
#include <string>

int main()
{
    //  Read K = [ 2, 10 ], A, B = [ 1, 10^5 ]
    long long K;
    std::string A, B;
    std::cin >> K >> A >> B;
    
    //  Main
    long long a = 0L;
    for( int i = 0; i < A.size(); i ++ ) {
        a *= K;
        a += ( long long )( A.at( i ) - '0' );
    }

    long long b = 0L;
    for( int i = 0; i < B.size(); i ++ ) {
        b *= K;
        b += ( long long )( B.at( i ) - '0' );
    }

    std::cout << a * b << std::endl;

    //  Finalize
    return( 0 );
}
