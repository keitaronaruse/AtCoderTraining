/*
    034 - There are few types of elements（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_ah
        Author: Keitaro Naruse
        Date:   2022-01-07, 2022-01-09
        MIT License
*/

// # Solution
// - Make Ci: a table of the length of intervals of K different values starting at i
// - Find the length by the two pointer method

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const bool Debug = false;

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
    std::map< int, int > counter;
    //  The length of intervals
    std::vector< int > C( N );

    int tail = 0;
    int kinds = 0;
    int max_length = 0;
    //  Head moves
    for( int head = 0; head < N; head ++ ) {
        //  Finad the tail
        while( tail < N ) {
            //  If Ai is a new number 
            if( counter[ A.at( tail ) ] == 0 ) {
                //  And if it reaches at K kinds
                if( kinds == K ) {
                    //  Update
                    break;
                }
                else {
                    kinds ++;
                    counter[ A.at( tail ) ] ++;
                    tail ++;
                }
            }
            //  If Ai is in the existing numbers
            else {
                counter[ A.at( tail ) ] ++;
                tail ++;
            }
        }
        //  Update
        C.at( head ) = tail - head;
        max_length = std::max( max_length, C.at( head ) );

        if( Debug ) {
            std::cerr << head << " " << tail << std::endl;
        }
        //  Post process
        counter[ A.at( head ) ] --;
        if( counter[ A.at(head) ] == 0 ) {
            kinds --;
        }
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << i << ": " << C.at( i ) << std::endl;
        }
    }
    
    //  Display result
    std::cout << max_length << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
