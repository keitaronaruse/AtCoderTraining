/*
    ABC231 Problem B - Election
        https://atcoder.jp/contests/abc231/tasks/abc231_b
        Author: Keitaro Naruse
        Date:   2021-12-11
        MIT License
*/

// # Solution
// - Use name as key and the number of votes as value

#include <iostream>
#include <string>
#include <map>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;

    //  Read Si and store in map
    std::map< std::string, int > votes;
    for( int i = 0; i < N; i++ ) {
        std::string name;
        std::cin >> name;
        votes[ name ] ++;
    }
    //  Find max vote
    int max_vote = 0;
    std::string max_name;
    for( const auto& v : votes ) {
        if( v.second > max_vote ) {
            max_vote = v.second;
            max_name = v.first;
        }
    }
    //  Display result
    std::cout << max_name << std::endl;
    
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
