/*
    ABC235 Problem D - Multiply and Rotate
        https://atcoder.jp/contests/abc235/tasks/abc235_d
        Author: Keitaro Naruse
        Date:   2022-01-15, 2022-01-17
        MIT License
*/

// # Solution: Inverse operation of mutiple and rotate
// - Apply the breadth first search to make new numbers
// - Make each of the new numbers by the two operations of multiplication and rotation

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
                q.push( m );
                // Anwer check
                if( m == N ) {
                    break;
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
                q.push( m );
                // Anwer check
                if( m == N ) {
                    break;
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
