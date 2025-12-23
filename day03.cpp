// Day 3
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

const int BASE = 10;
const int BATTERY_COUNT = 12;
const char ZERO = '0';

// load the raw puzzle input from the default data file
// preconditions:
//     data.txt is present in the working directory
// postconditions:
//     returns the contents of data.txt as an ordered list of strings
vector<string> parse_input()
{
    return read_lines();
}

// compute the answer for Day 3 Part 1 based on the parsed input
// preconditions:
//     lines contains the puzzle input returned from parse_input()
// postconditions:
//     returns the computed Part 1 result as a 64-bit integer
long long part1(const vector<string>& lines)
{
    long long joltage = 0;
    for (const auto& current : lines)
    {
        int tens = 0;
        int units = 0;
        for (int i = 0; i < current.length() - 1; i++)
        {
            if (current[i] - ZERO > tens)
            {
                tens = current[i] - ZERO;
                units = 0;
                for (int j = i + 1; j < current.length(); j++)
                {
                    if (current[j] - ZERO > units)
                    {
                        units = current[j] - ZERO;
                    }
                }
            }
        }
        joltage += tens * BASE + units;
    }
    return joltage;
}

// compute the answer for Day 3 Part 2 based on the parsed input
// preconditions:
//     lines contains the puzzle input returned from parse_input()
// postconditions:
//     returns the computed Part 2 result as a 64-bit integer
long long part2(const vector<string>& lines)
{
    long long joltage = 0;
    for (const auto& current : lines)
    {
        long long bank = 0;
        int position = -1;
        for (int i = 1; i <= BATTERY_COUNT; i++)
        {
            bank *= BASE;
            int largest = 0;
            for (int j = position + 1; j < current.length() - BATTERY_COUNT + i; j++)
            {
                if (current[j] - ZERO > largest)
                {
                    largest = current[j] - ZERO;
                    position = j;
                }
            }
            bank += largest;
        }
        joltage += bank;
    }
    return joltage;
}

// orchestrate input parsing and rendering of both part results
// preconditions:
//     out is a valid output stream ready for writing
// postconditions:
//     writes both Advent of Code Day 3 answers to the stream
void solve(ostream& out)
{
    const vector<string> lines = parse_input();
    out << "Day 03 - Part 1: " << part1(lines) << '\n'; // Answer: 17432
    out << "Day 03 - Part 2: " << part2(lines) << '\n'; // Answer: 173065202451341
}

// program entry point delegating to solve using standard output
// preconditions:
//     standard output stream is available
// postconditions:
//     returns 0 after solve completes
int main()
{
    solve(cout);
    return 0;
}
