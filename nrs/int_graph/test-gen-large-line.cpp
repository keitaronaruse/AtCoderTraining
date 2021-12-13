/*
    Test case generater 01
        large line case 
        Author: Keitaro Naruse
        Date:   2021-12-13
        MIT License
*/

#include <iostream>

int main()
{
    //  Initialize
    const int N = 10000;
    const int M =  9999;

    //  Main
    std::cout << N << " " << M << std::endl;
    for( int i = 1; i < N; i ++ ) {
        std::cout << i << " " << i + 1 << std::endl;
    }

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
