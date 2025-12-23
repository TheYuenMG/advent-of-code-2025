// Day 1
// Name: Otis Yuen

#include "utils.h"

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using advent::read_lines;
using std::cout;
using std::ostream;
using std::string;
using std::vector;

const int DIAL_SIZE = 100;
const char LEFT = 'L';
const char RIGHT = 'R';

// load the raw puzzle input from the default data file
// preconditions:
//    data.txt is present in the working directory
// postconditions:
//    returns the contents of data.txt as an ordered list of strings
vector<string> parse_input()
{
    return read_lines();
}

// compute the answer for Day 1 Part 1 based on the parsed input
// preconditions:
//    lines contains the puzzle input returned from parse_input()
// postconditions:
//    returns the computed Part 1 result as a 64-bit integer
long long part1(const vector<string>& lines)
{
    int dial = 50;
    long long zeroes = 0;
    for (const std::string& current : lines)
    {
        char direction = current[0];
        int value = std::stoi(current.substr(1));
        switch (direction)
        {
        case LEFT:
            dial -= value;
            break;
        case RIGHT:
            dial += value;
            break;
        default:
            std::cout << "Invalid direction: " << direction << std::endl;
            break;
        }
        dial = (dial % DIAL_SIZE + DIAL_SIZE) % DIAL_SIZE;
        if (dial == 0)
        {
            zeroes++;
        }
    }
    return zeroes;
}

// compute the answer for Day 1 Part 2 based on the parsed input
// preconditions:
//    lines contains the puzzle input returned from parse_input()
// postconditions:
//    returns the computed Part 2 result as a 64-bit integer
long long part2(const vector<string>& lines)
{
    int dial = 50;
    long long zeroes = 0;
    for (const std::string& current : lines)
    {
        char direction = current[0];
        int value = std::stoi(current.substr(1));
        int dial_start = dial;
        zeroes += value / DIAL_SIZE;
        value %= DIAL_SIZE;
        switch (direction)
        {
        case LEFT:
            dial -= value;
            if (dial <= 0 && dial_start)
            {
                zeroes++;
            }
            break;
        case RIGHT:
            dial += value;
            if (dial >= DIAL_SIZE)
            {
                zeroes++;
            }
            break;
        default:
            std::cout << "Invalid direction: " << direction << std::endl;
            break;
        }
        dial = (dial % DIAL_SIZE + DIAL_SIZE) % DIAL_SIZE;
    }
    return zeroes;
}

// orchestrate input parsing and rendering of both part results
// preconditions:
//    out is a valid output stream ready for writing
// postconditions:
//    writes both Advent of Code Day 1 answers to the stream
void solve(ostream& out)
{
    const vector<string> lines = parse_input();
    out << "Day 01 - Part 1: " << part1(lines) << '\n'; // Answer: 1150
    out << "Day 01 - Part 2: " << part2(lines) << '\n'; // Answer: 6738
}

// program entry point delegating to solve using standard output
// preconditions:
//    standard output stream is available
// postconditions:
//    returns 0 after solve completes
int main()
{
    solve(cout);
    return 0;
}
