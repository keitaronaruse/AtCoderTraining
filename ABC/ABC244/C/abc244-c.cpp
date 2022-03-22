/**
* @file abc244-c.cpp
* @brief ABC244 Problem C - Yamanote Line Game
* @author Keitaro Naruse
* @date 2022-03-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc244/tasks/abc244_c
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read N = [ 1, 10^3 ]
    int N = 0;
    std::cin >> N;


    //  Main
    //  Table of used numbers, 1-index 
    std::vector< bool > used( 2 * N + 1 + 1, false );
    int m = 0;
    do {
        //  Takahashi's turn
        //  Return the minumum unused number and update the table 
        for( int i = 1; i <= 2 * N + 1; i ++ ) {
            if( !used.at( i ) ) {
                used.at( i ) = true;
                std::cout << i << std::endl;
                break;
            }
        }
        //  Opponent's turn
        //  read and update the table
        std::cin >> m;
        used.at( m ) = true; 
    } while( m != 0 );

    //  Finalize
    return( 0 );
}
