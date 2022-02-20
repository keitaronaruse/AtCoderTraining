/**
* @file abc240-d.cpp
* @brief ABC240 Problem D
* @author Keitaro Naruse
* @date 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc240/tasks/abc240_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <utility>
#include <stack>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 2 * 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read ai = [ 2, 2 * 10^5 ]
    std::vector< int > a( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> a.at( i );
    }
    if( Debug ) {
        std::cerr << a << std::endl;
    }

    //  Main
    std::stack< std::pair< int, int > > cylinder;
    int value = 0;
    int count = 0;
    int num_balls = 0;
    for( int i = 0; i < N; i ++ ) {
        //  When empty 
        if( value == 0 ) {
            value = a.at( i );
            count = 1;
            num_balls ++;
        }
        else {
            //  The same type of ball comes in
            if( a.at( i ) == value ) {
                count ++;
                num_balls ++;
                //  Balls disapper
                if( count == a.at( i ) ) {
                    num_balls -= count;
                    //  Update the stack
                    if( cylinder.empty() ) {
                        value = 0;
                        count = 0;
                    }
                    else {
                        auto p = cylinder.top(); 
                        cylinder.pop();
                        value = p.first;
                        count = p.second;
                    }
                }
            }
            //  The different type of ball comes in
            else {
                cylinder.push( std::make_pair( value, count ) );
                value = a.at( i );
                count = 1;
                num_balls ++;
            }
        }
        std::cout << num_balls << std::endl; 
        if( Debug ) {
            std::cerr << "( " << value << ", " << count << " )" << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
