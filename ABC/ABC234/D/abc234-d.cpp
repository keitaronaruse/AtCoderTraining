/*
    ABC234 Problem D - Prefix K-th Max
        https://atcoder.jp/contests/abc234/tasks/abc234_d
        Author: Keitaro Naruse
        Date:   2022-01-08, 2022-01-09
        MIT License
*/

// # Solution: Introduce the priority queue for reducing the computation time
// - Principle
//   - Store the largerst K elements in Q and output x,the minimum in Q
//   - Add a new element of Pi to Q, erase an element out of Q if x < Pi
//   - Do nothing otherwise (x >= Pi)
//   - Maintain K elements elements, and the target is always at the minimum in Q  
// - Implementation
//   - Introduce the priority queue in the ascending order 

#include <iostream>
#include <vector>
#include <queue>

const bool Debug = true;

int main()
{
    //  Read N and K
    int N = 0, K = 0;
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }
    //  Read Pi
    std::vector< int > P( N, 0 );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> P.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << P.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    //  Take the first K elements out of P and store them in the priority queue
    std::priority_queue< int, std::vector< int >, std::greater< int > > Q;
    for( int i = 0; i < K; i ++ ) {
        Q.push( P.at( i ) );
    }
    if( Debug ) {
        std::priority_queue< int, std::vector< int >, std::greater< int > > R = Q;
        while( !R.empty() ) {
            int r = R.top(); 
            std::cerr << r << " ";
            R.pop(); 
        }
        std::cerr << std::endl;
    }
    ;
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
