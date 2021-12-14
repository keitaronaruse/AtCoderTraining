/*
    Test file generator for line pattern
        Author: Keitaro Naruse
        Date:   2021-12-14
        MIT License
*/

#include <iostream>
#include <string>

int main( int argc, char* argv[] )
{
    int N = 0, M = 0;
    
    if( argc == 2 ) {
        N = std::stoi( std::string( argv[1] ) );
        M = N - 1;
        std::cout << N << " " << M << std::endl;
        for( int i = 1; i < N; i ++ ) {
            std::cout << i << " " << i + 1 << std::endl;
        }
    }
    else {
        std::cerr << "usage: test-gen-line N" << std::endl;
        return( -1 );
    }

    return( 0 );
}
