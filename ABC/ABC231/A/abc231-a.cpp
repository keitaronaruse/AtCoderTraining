/*
    ABC231 Problem A
        Author: Keitaro Naruse
        Date:   2021-12-11
        MIT License
*/

#include <iostream>
#include <vector>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
        //  Debug
        std::cout << A.at( i ) << " ";
    }
    //  Debug
    std::cout << std::endl;
    
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
