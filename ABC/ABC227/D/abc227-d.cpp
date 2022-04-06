/**
* @file abc227-d.cpp
* @brief ABC227 Problem D - Project Planning
* @author Keitaro Naruse
* @date 2022-04-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc227/tasks/abc227_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N = [ K, 2*10^5 ], K = [ 1 , N ]
    int N, K;
    std::cin >> N >> K;
    //  Read Ai = [ 1, 10^12 ]
    std::vector< long long > A( N );
    for( auto& a : A ) {
        std::cin >> a;       
    }
    
    //  Main
    long long ok = 0L, ng = 1000000000000000000L / ( long long ) K;
    while( ng - ok > 1L ) {
        long long md = ( ok + ng ) / 2L;
        long long sum = 0L;
        for( auto a : A ) {
            sum += std::min( a, md );
        }
        if( K * md <= sum ) {
            ok = md;
        }
        else {
            ng = md;
        }
    }
    std::cout << ok << std::endl;

    //  Finalize
    return( 0 );
}
