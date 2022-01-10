/*
    ABC232 Problem B - Caesar Cipher
        https://atcoder.jp/contests/abc232/tasks/abc232_b
        Author: Keitaro Naruse
        Date:   2021-12-19, 2022-01-10
        MIT License
*/

// # Solution
// - Try all the offest of 26 characters

#include <iostream>
#include <string>

const bool Debug = false;

int main()
{
    //  Constannt
    const int K = 26;

    //  Read S and T
    std::string S, T; 
    std::cin >> S >> T;
    if( Debug ) {
        std::cerr << S << std::endl << T << std::endl; 
    }

    for( int k = 0; k < K; k++ ) {
        int isYesK = true;
        for( int i = 0; i < S.size(); i ++ ) {
            int s = ( ( S.at( i ) - 'a' ) + k ) % K;
            int t = T.at( i ) - 'a';
            if( s != t ) {
                isYesK = false;
                break;
            }
        }
        if( isYesK ) {
            std::cout << "Yes" << std::endl;
            return( 0 );
        }
    }

    //  Display result
    std::cout << "No" << std::endl;
    
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
