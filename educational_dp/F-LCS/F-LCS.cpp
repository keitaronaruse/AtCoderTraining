/**
* @file F-LCS.cpp
* @brief F - LCS
* @author Keitaro Naruse
* @date 2022-01-22
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_f
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const bool Debug = false; 

int main()
{
    //  Read s and t
    std::string s, t;
    std::cin >> s >> t;
    if( Debug ) {
        std::cerr << s << std::endl;
        std::cerr << t << std::endl;
    }
    //  Read N = [ 1, 3000 ] and M = [ 1, 3000 ]
    const int M = s.size(), N = t.size();

    //  Main
    //  DP principle: DP matching
    //  DP example: agcat and gac -> ga or gc
    //     -  a  g  c  a  t
    //  -  0  0  0  0  0  0
    //  g  0  0 *1  1  1  1
    //  a  0 *1  1  1 *2  2
    //  c  0  1  1 *2  2  2
    //  DP table: 
    //  - size: M * N = 3*10^3 * 3*10^3 = 9*10^6
    //  - value: min( N, M ) = 3*10^3 -> int
    
    //  Main::Initialize
    //  DP table: 
    std::vector< std::vector< int > > dp_length( M + 1, std::vector< int >( N + 1, 0 ) ); 

    //  Initial boundary condition

    //  Main::Loop
    for( int i = 0; i < M; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            //  If the characers are not matched
            dp_length.at( i + 1 ).at( j + 1 ) = std::max(
                dp_length.at( i + 1 ).at( j ), 
                dp_length.at( i ).at( j + 1 ) 
            );
            //  If the characers are matched
            if( s.at( i ) == t.at( j ) ) {
                dp_length.at( i + 1 ).at( j + 1 ) = std::max(
                    dp_length.at( i + 1 ).at( j + 1 ), 
                    dp_length.at( i ).at( j ) + 1
                );
            }
        }
    }

    if( Debug ) {
        for( int i = 0; i <= M; i ++ ) {
            for( int j = 0; j <= N; j ++ ) {
                std::cerr << dp_length.at( i ).at( j ) << " ";
            }
            std::cerr << std::endl;
        }
    }
    //  Main::Finalize
    //  Trace back
    std::string matched_str;
    int i = M, j = N;
    while( i >= 1 && j >= 1 ) {
        if( dp_length.at( i ).at( j - 1 ) == dp_length.at( i ).at( j ) ) {
            j --;
        }
        else if( dp_length.at( i - 1 ).at( j ) == dp_length.at( i ).at( j ) ) {
            i --;
        }
        else {
            matched_str = s.at( i - 1 ) + matched_str;
            i --;
            j --;
        }
    }
    //  Display the result
    std::cout << matched_str << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
