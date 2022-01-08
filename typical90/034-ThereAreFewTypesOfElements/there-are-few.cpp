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
    std::vector< bool > visited( N, false );
    std::map< int, int > counter;
    int head = 0, tail = 0;
    while( tail < N ) {
        //  Move the tail
        while( counter.size() <= K ) {
            if( !visited.at( tail ) ) {
                visited.at( tail ) = true;
                counter[ A.at( tail ) ] ++;
            }
            //  The case to break
            if( counter.size() == K + 1 ) {
                break;
            }
            else {
                tail ++;
                if( tail >= K ) {
                    break;
                }
            }
        }

        //  Update interval
        C.at( head ) = tail - 1;
        //  Update the counter for the head
        counter[ A.at( head ) ] --;
        if( counter[ A.at( head ) ] == 0 ) {
            counter.erase( A.at( head ) );
        }

        //  Move the head
        head ++;
    }
    for( ; head < N; head ++ ) {
        C.at( head ) = tail - 1;
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
