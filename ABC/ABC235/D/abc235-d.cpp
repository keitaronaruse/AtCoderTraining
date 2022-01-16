/*
    ABC235 Problem D
        https://atcoder.jp/contests/abc235/tasks/abc235_d
        Author: Keitaro Naruse
        Date:   2022-01-15
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

    std::vector< int > dp( 10 * N + 1, -1 );
    dp.at( N ) = 0;
    //  Main
    std::queue< int > q;
    q.push( N );
    while( !q.empty() ) {
        int n = q.front();
        q.pop();
        //  Multiple Divide
        if( n % A == 0 ) {
            int m = n / A;
            if( dp.at( m ) == -1 ) {
                dp.at( m ) = dp.at( n ) + 1;
                q.push( m );                ;
            } 
        }
        //  Rotate
        // if( n > 10 && n % 10 != 0 ) {
        if( n > 10 ) {
            const std::string s = std::to_string( n );
            std::string t = s;
            // if( s.size() > 1 ) {
                for( int i = 0; i < s.size(); i ++ ) {
                    t.at( i ) = s.at( ( i + 1 ) % s.size() );
                }
                int m = std::stoi( t );
                if( m % 10 != 0) {
                    if( dp.at( m ) == -1 ) {
                        dp.at( m ) = dp.at( n ) + 1;
                        q.push( m );
                    }
                }
            // }
        }
    }
    std::cout << dp.at( 1 ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
