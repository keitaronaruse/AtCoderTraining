/*
    ABC233 Problem B - A Reverse
        https://atcoder.jp/contests/abc233/tasks/abc233_b
        Author: Keitaro Naruse
        Date:   2021-12-25
        MIT License
*/

// # Solution
// - std::reverse

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    //  Read L, R, and S
    int L = 0, R = 0; 
    std::string S;
    std::cin >> L >> R >> S;
    L --;
    R --;

    std::reverse( S.begin() + L, S.begin() + R + 1);

    //  Display result
    std::cout << S << std::endl;
    
    return( 0 );
}
