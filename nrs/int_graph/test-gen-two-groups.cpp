/*
    Test case generater 03
        Two groups
        Author: Keitaro Naruse
        Date:   2021-12-13
        MIT License
*/

#include <iostream>

int main()
{
    //  Initialize
    const int N = 10000;
    const int M =  5000;

    //  Main
    std::cout << N << " " << M << std::endl;
    for( int i = 1; i < N; i += 4 ) {
        std::cout << i     << " " << i + 2 << std::endl;
        std::cout << i + 1 << " " << i + 3 << std::endl;
    }

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
