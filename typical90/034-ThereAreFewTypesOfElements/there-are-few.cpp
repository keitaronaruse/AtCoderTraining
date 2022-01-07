/*
    034 - There are few types of elements（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_ah
        Author: Keitaro Naruse
        Date:   2022-01-07, 2022-01-01
        MIT License
*/

// # Solution
// - Make Ci: a table of the length of intervals of K different values starting at i
// - Find the length by the two pointer method

#include <iostream>
#include <vector>
#include <map>
#include <utility>

const bool Debug = true;

int main()
{
    //  Read N and K
    int N = 0, K = 0;
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }

    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        if( Debug ) {
            std::cerr << A.at( i ) << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    //  Main
    //  Make Ci
    std::vector< int > C( N );
    //  A counter of the number and the appearance time 
    std::map< int, int > counter;
    int tail = 0;
    for( int head = 0; head < N; head ++ ) {
        //  Add the value to the counter
        if( Debug ) {
            std::cerr << "Add: " << A.at( tail ) << std::endl;
        }
        counter[ A.at( tail ) ] ++;
        if( tail < N - 1 ) {
            tail ++;
        }
        //  When it is out of the interval
        if( counter.size() >= K ) {
            //  Update Ci
            C.at( head ) = tail;
            if( Debug ) {
                std::cerr << "Erase: " << A.at( head ) << std::endl;
            }
            //  Decrease the head element and erase it if necesarry 
            counter[ A.at( head ) ] --;
            if( counter[ A.at( head ) ] == 0 ) {
                counter.erase( A.at( head ) );
            }
        }

        if( Debug ) {
            for( auto c: counter ) {
                std::cerr << head << ": " << c.first << ", " << c.second << std::endl;
            }
        }
    }
    
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << i << ": " << C.at( i ) << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
