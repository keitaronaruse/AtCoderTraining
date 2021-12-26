/*
    list_comb()
        returns all the enumeration of the combination
        Author: Keitaro Naruse
        Date:   2021-12-26
        MIT License
*/

#include <iostream>
#include <vector>

namespace nrs {
    bool list_comb( std::vector< int >& comb, const std::vector< int >& len ) 
    {
        int n = comb.size();
        bool next_exist = true;
        
        for( int i = n - 1; i >= 0; i -- ) {
            comb.at( i ) ++;
            if( comb.at( i ) < len.at( i ) ) {
                break;
            }
            else {
                comb.at( i ) = 0;
                if( i == 0) {
                    next_exist = false;
                }
            } 
        }
        return( next_exist );
    }
}

//  Test driver
int main()
{
    //  Constants
    const int N = 4;
    const std::vector< std::vector< int > > A = {
        { 1 }, 
        { 2, 3 }, 
        { 4, 5, 6 }, 
        { 7, 8, 9, 10 } 
    };

    std::vector< int > L( N );
    for( int i = 0; i < N; i ++ ) {
        L.at( i ) = A.at( i ).size();
    }

    //  Main
    std::vector< int > comb( N, 0 );
    do {
        for( int i = 0; i < comb.size(); i ++ ) {
            std::cout << comb.at( i ) << " ";
        }
        std::cout << std::endl;
    } while( nrs::list_comb( comb, L ) );
    
    return( 0 );
}
