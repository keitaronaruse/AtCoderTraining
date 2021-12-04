/*
    ABC230 Problem B
    B - Triple Metre
        https://atcoder.jp/contests/abc230/tasks/abc230_b
        Author: Keitaro Naruse
        Date:   2021-12-03
        MIT License
*/

// # Solution
// - oxxoxxoxxoxx
// - If it starts with 'o',  then 'x', 'x', 'o',
// - If it starts with 'x' and 'x',  then 'o', 'x', 'x', 'o',
// - If it starts with 'x' and 'o',  then 'x', 'x', 'o',

#include <iostream>
#include <string>

int main()
{
    //  Constant  
    std::string oxx = "oxx";

    //  Read S
    std::string S; 
    std::cin >> S;

    //  Main
    bool isYes = true;
    if( S.at( 0 ) == 'o' ) {
        for( size_t i = 1; i != S.size(); i++ ) {
            if( S.at( i ) != oxx.at( i % 3 ) ) {
                //  'x'[1]
                isYes = false;
                break;
            }
        }
    }
    else if( S.at( 0 ) == 'x' ) {
        if( S.size() != 1 ) {
            //  "xxoxx" pattern
            if( S.at( 1 ) == 'x' ) {
                for( size_t i = 2; i != S.size(); i++ ) {
                    //  i == 2 should match with 'o' == 0
                    if( S.at( i ) != oxx.at( ( i + 1 ) % 3 ) ) {
                        isYes = false;
                        break;
                    }
                }
            }
            //  "xoxxoxx" pattern
            else if( S.at( 1 )  == 'o' ) {
                for( size_t i = 2; i != S.size(); i++ ) {
                    //  i == 2 should match with 'x' == 1
                    if( S.at( i ) != oxx.at( ( i + 2 ) % 3 ) ) {
                        isYes = false;
                        break;
                    }
                }
            }
            else {
                isYes = false;
            }
        }
    }
    else {
        isYes = false;
    }

    //  Display result
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
