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

const int POW10_MAXIMUM = 20;
const char WHITESPACE = ' ';
const char COMMA = ',';
const char HYPHEN_MINUS = '-';

// load the raw puzzle input from the default data file
// preconditions:
//    data.txt is present in the working directory
// postconditions:
//    returns the contents of data.txt as an ordered list of strings
vector<string> parse_input()
{
    return read_lines();
}

// compute the answer for Day 2 Part 1 based on the parsed input
// preconditions:
//    lines contains the puzzle input returned from parse_input()
// postconditions:
//    returns the computed Part 1 result as a 64-bit integer
long long part1(const vector<string>& lines)
{
    long long result = 0;
    string input = lines[0];
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == COMMA || input[i] == HYPHEN_MINUS)
        {
            input[i] = WHITESPACE;
        }
    }
    long long lower, upper;
    std::stringstream ranges(input);
    vector<long long> pow10(POW10_MAXIMUM, 1);
    for (int i = 1; i < POW10_MAXIMUM; i++)
    {
        pow10[i] = pow10[i - 1] * 10;
    }
    while (ranges >> lower >> upper)
    {
        for (long long i = lower; i <= upper; i++)
        {
            int digits = std::to_string(i).size();
            if (digits > POW10_MAXIMUM)
            {
                std::cout << "ID too large: " << digits << " digits, maximum 20" << std::endl;
                continue;
            }
            if (!(digits % 2))
            {
                long long factor = pow10[digits / 2] + 1;
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
//    lines contains the puzzle input returned from parse_input()
// postconditions:
//    returns the computed Part 2 result as a 64-bit integer
long long part2(const vector<string>& lines)
{
    long long result = 0;
    string input = lines[0];
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == COMMA || input[i] == HYPHEN_MINUS)
        {
            input[i] = WHITESPACE;
        }
    }
    long long lower, upper;
    std::stringstream ranges(input);
    vector<long long> pow10(POW10_MAXIMUM, 1);
    for (int i = 1; i < POW10_MAXIMUM; i++)
    {
        pow10[i] = pow10[i - 1] * 10;
    }
    while (ranges >> lower >> upper)
    {
        for (long long i = lower; i <= upper; i++)
        {
            int digits = std::to_string(i).size();
            if (digits > POW10_MAXIMUM)
            {
                std::cout << "ID too large: " << digits << " digits, maximum 20" << std::endl;
                continue;
            }
            for (int j = 1; j <= digits / 2; j++)
            {
                if (!(digits % j) && digits / j >= 2)
                {
                    long long numerator = pow10[digits] - 1;
                    long long denominator = pow10[j] - 1;
                    long long factor = numerator / denominator;
                    if (!(i % factor) && int(std::to_string(i / factor).size()) == j)
                    {
                        result += i;
                        break;
                    }
                }
            }
        }
    }
    return result;
}

// orchestrate input parsing and rendering of both part results
// preconditions:
//    out is a valid output stream ready for writing
// postconditions:
//    writes both Advent of Code Day 2 answers to the stream
void solve(ostream& out)
{
    const vector<string> lines = parse_input();
    out << "Day 02 - Part 1: " << part1(lines) << '\n'; // Answer: 16793817782
    out << "Day 02 - Part 2: " << part2(lines) << '\n'; // Answer: 27469417404
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
