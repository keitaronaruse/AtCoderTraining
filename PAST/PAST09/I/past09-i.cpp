/**
* @file past09-i.cpp
* @brief PAST 9 Problem I - 直通エレベーター
  @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_i
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const bool Debug = true;

int main()
{
    //  | S |, | T | = [ 1, 5 * 10^3 ]
    std::string S, T;
    std::cin >> S >> T;

    //  Main
    int n = S.size(), m = T.size();
    std::vector< std::vector< int > > dp( n + 1, std::vector< int >( m + 1, 0 ) );
    for( int i = 1; i <= n; i ++ ) {
        for( int j = 1; j <= m; j ++ ) {
            dp.at( i ).at( j ) = std::max( 
                dp.at( i - 1 ).at( j - 1 ) + ( ( S.at( i - 1 ) == T.at( j - 1 ) ) ? 0 : 1), 
                std::max( dp.at( i ).at( j - 1 ), dp.at( i - 1 ).at( j ) )
            );
        }
    }
    std::cout << dp.at( n ).at( m ) << std::endl;

    return( 0 );
}
