// Day 4
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

const int ADJACENT_LIMIT = 4;
const int ADJACENT_COUNT = 8;
const char PAPER_ROLL = '@';

// load the raw puzzle input from the default data file
// preconditions:
//    data.txt is present in the working directory
// postconditions:
//    returns the contents of data.txt as an ordered list of strings
vector<string> parse_input()
{
    return read_lines();
}

int adjacent(const vector<string>& lines, int y, int x)
{
    int result = 0;
    const int dy[ADJACENT_COUNT] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dx[ADJACENT_COUNT] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < ADJACENT_COUNT; i++)
    {
        int y_adj = y + dy[i];
        int x_adj = x + dx[i];
        if (y_adj < 0 || y_adj >= lines.size() ||
            x_adj < 0 || x_adj >= lines[y_adj].size())
        {
            continue;
        }
        if (lines[y_adj][x_adj] == PAPER_ROLL)
        {
            result++;
        }
    }
    return result;
}

// compute the answer for Day 4 Part 1 based on the parsed input
// preconditions:
//    lines contains the puzzle input returned from parse_input()
// postconditions:
//    returns the computed Part 1 result as a 64-bit integer
long long part1(const vector<string>& lines)
{
    long long accessible = 0;
    for (int y = 0; y < lines.size(); y++)
    {
        for (int x = 0; x < lines[y].size(); x++)
        {
            if (lines[y][x] == PAPER_ROLL && adjacent(lines, y, x) < ADJACENT_LIMIT)
            {
                accessible++;
            }
        }
    }
    return accessible;
}

// compute the answer for Day 4 Part 2 based on the parsed input
// preconditions:
//    lines contains the puzzle input returned from parse_input()
// postconditions:
//    returns the computed Part 2 result as a 64-bit integer
long long part2(const vector<string>& lines)
{
    return 0;
}

// orchestrate input parsing and rendering of both part results
// preconditions:
//    out is a valid output stream ready for writing
// postconditions:
//    writes both Advent of Code Day 4 answers to the stream
void solve(ostream& out)
{
    const vector<string> lines = parse_input();
    out << "Day 04 - Part 1: " << part1(lines) << '\n'; // Answer: 1602
    out << "Day 04 - Part 2: " << part2(lines) << '\n';
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
