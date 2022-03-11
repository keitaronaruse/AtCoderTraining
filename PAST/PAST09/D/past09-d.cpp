/**
* @file past09-d.cpp
* @brief PAST 9 Problem D - 試験
  @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_d
*/

#include <iostream>
#include <vector>
#include <algorithm>

class student {
    public:
        int id, A, B, S;
    public:
        bool operator<( const student& r ) {
            bool is_higher = true;
            if( S == r.S ) {
                if( A == r.A ) {
                    is_higher = ( id < r.id );
                }
                else {
                    is_higher = ( A > r.A );
                }
            }
            else {
                is_higher = ( S > r.S );
            }
            return( is_higher );
        }
};

int main()
{
    //  N = [ 2, 2 * 10^5 ]
    int N;
    std::cin >> N;
    //  Ai, Bi = [ 0, 10^9 ]
    std::vector< int > A( N ), B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
    }

    std::vector< student > students( N );
    for( int i = 0; i < N; i ++ ) {
        students.at( i ).id = i + 1;
        students.at( i ).A = A.at( i );
        students.at( i ).B = B.at( i );
        students.at( i ).S = A.at( i ) + B.at( i );
    }
    
    std::sort( students.begin(), students.end() );
    for( int i = 0; i < N; i ++ ) {
        std::cout << students.at( i ).id << " ";
    } 
    std::cout << std::endl;

    return( 0 );
}
