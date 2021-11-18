/*
    ABC081A Placing Marbles
        https://atcoder.jp/contests/abs/tasks/abc081_a
        Author: Keitaro Naruse
        Date:   2021-11-08
        MIT License
*/

#include <iostream>
#include <string>

int main()
{
    std::string s;
    size_t i( 0 ), n( 0 );

    //  Read string   
    std::cin >> s;
    //  Debug routine
    std::cerr << s << std::endl;

    //  For all the characters
    for( i = 0; i != s.size(); ++i ) {
        //  Count the appearance of '1'
        if( '1' == s.at ( i ) ) {
            ++ n;
        }
    }

    //  Print the appearance
    std::cout << n << std::endl;
    
    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
