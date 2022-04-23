/**
* @file abc249-b.cpp
* @brief ABC249 Problem B - Perfect String
* @author Keitaro Naruse
* @date 2022-04-23, 2022-04-24
* @copyright MIT License
* @details https://atcoder.jp/contests/abc249/tasks/abc249_b
*/

// # Solution

#include <iostream>
#include <string>
#include <set>

int main()
{
    //  Read | S | = [ 1, 10^2 ]
    std::string S;
    std::cin >> S;

    //  Main
    bool isIncludeLarge = false, isIncludeSmall = false, isDuplicate = false;
    std::set< char > table;
    for( int i = 0; i < S.size(); i ++ ) {
        if( 'A' <= S.at( i ) && S.at( i ) <= 'Z' ) {
            isIncludeLarge = true;
        }
        if( 'a' <= S.at( i ) && S.at( i ) <= 'z' ) {
            isIncludeSmall = true;
        }
        if( table.find( S.at( i ) ) == table.end() ) {
            table.insert( S.at( i ) );
        }
        else {
            isDuplicate = true;
            break;
        }
    }

    if( isIncludeLarge && isIncludeSmall && !isDuplicate ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
