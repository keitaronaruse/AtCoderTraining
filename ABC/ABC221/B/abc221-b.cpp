/**
* @file abc221-b.cpp
* @brief ABC221 Problem B - typo
* @author Keitaro Naruse
* @date 2022-04-11
* @copyright MIT License
* @details https://atcoder.jp/contests/abc221/tasks/abc221_b
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>

int main()
{
    //  Read S, T
    std::string S, T;
    std::cin >> S >> T;

    //  Main
    //  Preprocess
    std::vector< bool > same( S.size(), true );
    size_t num_diff = 0;
    for( size_t i = 0; i < S.size(); i ++ ) {
        same.at( i ) = ( S.at( i ) == T.at( i ) );
        if( !same.at( i ) ) {
            num_diff ++;
        }
    }
    //  Find solution
    bool isYes = true;
    if( num_diff == 0 ) {
        isYes = true;
    }
    else if( num_diff == 1 ) {
        isYes = false;
    }
    else if( num_diff == 2 ) {
        for( size_t i = 0; i < S.size(); i ++ ) {
            if( !same.at( i ) ) {
                if( S.at( i ) == T.at( i + 1 ) && S.at( i + 1 ) == T.at( i ) ) {
                    isYes = true;
                }
                else {
                    isYes = false;
                }
                break;
            }
        }
    }
    else if( num_diff > 2 ) {
        isYes = false;
    }

    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
