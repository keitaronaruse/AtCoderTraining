/**
* @file arc132-b.cpp
* @brief ARC132 Problem B - Shift and Reverse
* @author Keitaro Naruse
* @date 2022-03-28, 2022-03-29
* @copyright MIT License
* @details https://atcoder.jp/contests/arc132/tasks/arc132_b
*/

// # Solution

#include <iostream>
#include <vector>

int main()
{
    //  Read n = [ 2, 10^5 ]
    int n;
    std::cin >> n;
    //  Read pi = [ 1, n ]
    std::vector< int > p( n, 0 );
    for( int i = 0; i < n; i ++ ) {
        std::cin >> p.at( i );
    }

    //  Main
    //  Judge if we should reverse it
    int pos_one = 0;
    bool ascending = true;
    if( p.at( n - 1 ) == 1 ) {
        pos_one = n - 1;
        ascending = ( p.at( 0 ) == 2 ) ? true : false;
    }
    else {
        for( int i = 0; i < n - 1; i ++ ) {
            if( p.at( i ) == 1 ) {
                pos_one = i;
                ascending = ( p.at( i + 1 ) == 2 ) ? true : false;
                break;
            }
        }
    }

    //  Find the number of operations
    int num_operations = 0;
    if( n == 2 ) {
        //  Bounrady case
        num_operations = ( pos_one == 0 ) ? 0 : 1; 
    }
    else if( n == 3 ) {
        //  Another bounrady case
        if( ascending ) {
            num_operations = pos_one;
        }
        else {
            num_operations = ( pos_one == 2 ) ? 1 : 2;
        }
    }
    if( n % 2 == 0 ) {
        //  Even cases
        if( ascending ) {
            if( pos_one <= n / 2 ) {
                //  R...R case
                num_operations = pos_one;
            }
            else {
                //  FR...RF case
                num_operations =  1 + ( n - pos_one ) + 1;
            }
        }
        else {
            if( pos_one < n / 2 ) {
                //  R...RF case
                num_operations = ( pos_one + 1 ) + 1;
            }
            else {
                //  FR...R case
                num_operations =  1 + ( n - 1 - pos_one );
            }
        }
    }
    else {
        //  Odd cases
        if( ascending ) {
            if( pos_one <= n / 2 + 1 ) {
                //  R...R case
                num_operations = pos_one;
            }
            else {
                //  FR...RF case
                num_operations =  1 + ( n - pos_one ) + 1;
            }
        }
        else {
            if( pos_one < n / 2 ) {
                //  R...RF case
                num_operations = ( pos_one + 1 ) + 1;
            }
            else {
                //  FR...R case
                num_operations =  1 + ( n - 1 - pos_one );
            }
        }
    }
    std::cout << num_operations << std::endl;

    //  Finalize
    return( 0 );
}
