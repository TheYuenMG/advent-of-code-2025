// Day 2
// Name: Otis Yuen

#include "utils.h"

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

using advent::read_lines;
using std::cout;
using std::ostream;
using std::string;
using std::vector;

// load the raw puzzle input from the default data file
// preconditions:
//     data.txt is present in the working directory
// postconditions:
//     returns the contents of data.txt as an ordered list of strings
vector<string> parse_input()
{
    return read_lines();
}

// compute the answer for Day 2 Part 1 based on the parsed input
// preconditions:
//     lines contains the puzzle input returned from parse_input()
// postconditions:
//     returns the computed Part 1 result as a 64-bit integer
long long part1(const vector<string>& lines)
{
    long long result = 0;
    string input = lines[0];
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '-' || input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    long long lower, upper;
    std::stringstream ranges(input);
    while (ranges >> lower >> upper)
    {
        for (long long i = lower; i <= upper; i++)
        {
            int digits = std::to_string(i).size();
            if (!(digits % 2))
            {
                long long factor = 1;
                for (int j = 0; j < digits / 2; j++)
                {
                    factor *= 10;
                }
                factor++;
                if (!(i % factor))
                {
                    result += i;
                }
            }
        }
    }
    return result;
}

// compute the answer for Day 2 Part 2 based on the parsed input
// preconditions:
//     lines contains the puzzle input returned from parse_input()
// postconditions:
//     returns the computed Part 2 result as a 64-bit integer
long long part2(const vector<string>& lines)
{
    return 0;
}

// orchestrate input parsing and rendering of both part results
// preconditions:
//     out is a valid output stream ready for writing
// postconditions:
//     writes both Advent of Code Day 2 answers to the stream
void solve(ostream& out)
{
    const vector<string> lines = parse_input();
    out << "Day 02 - Part 1: " << part1(lines) << '\n';
    out << "Day 02 - Part 2: " << part2(lines) << '\n';
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
