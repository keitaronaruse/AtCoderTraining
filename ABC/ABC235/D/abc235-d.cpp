/*
    ABC235 Problem D
        https://atcoder.jp/contests/abc235/tasks/abc235_d
        Author: Keitaro Naruse
        Date:   2022-01-15, 2022-01-16
        MIT License
*/

// # Solution: Inverse operation of mutiple and rotate
// - N / A % == 0
// - rotate N 
// - 1 (*5) 5 (*5) 25 (rot) 52 (*5) 260 (!rot) X602
// - 260 cannot be ratated to 602 due to the constraints ( 0!= mod 10 )
// - a = 5, N = 602

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Read A and N
    int A = 0, N = 0;
    std::cin >> A >> N;
    if( Debug ) {
        std::cerr << A << " " << N << std::endl;
    }
   
    //  Make depth table
    const int M = 1000000;
    std::vector< int > depth( M + 1, -1 );

    //  Start value
    //  Main
    std::queue< int > q;
    int n = 1;
    depth.at( n ) = 0;
    q.push( n );
    while( !q.empty() ) {
        n = q.front();
        q.pop();
        long long nA = ( long long ) n * ( long long ) A;
        //  Multiple
        if( nA <= ( long long ) M ) {
            int m = n * A;
            if( depth.at( m ) == -1 ) {
                depth.at( m ) = depth.at( n ) + 1;
                // Anwer check
                if( m == N ) {
                    break;
                }
                else {
                    q.push( m );
                }
            } 
        }
        //  Rotate
        if( n >= 10 && n % 10 != 0 ) {
            const std::string s = std::to_string( n );
            const int len = s.size(); 
            std::string t = s.substr( len - 1, 1 ) + s.substr( 0, len - 1 );
            int m = std::stoi( t );
            if( depth.at( m ) == -1 ) {
                depth.at( m ) = depth.at( n ) + 1;
                // Anwer check
                if( m == N ) {
                    break;
                }
                else {
                    q.push( m );
                }
            }
        }
    }
    std::cout << depth.at( N ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
