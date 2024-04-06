#include <iostream>
#include <math.h>
#include <vector>
#include <map>
using std::string;
using std::pair;
using std::vector;
using var = long double;
using std::map;

bool isoperator(char in) {
  if ( in == '+' || in == '-' || in == '*' || in == '/' ||
      in == '(' || in == ')' || in == '!' || in == '^' ||
      in == '=' || in == '<' || in == '>' || in == '%' ) {
    return true;
  }
  return false;
}
bool isletter(char in) {
  /*65-90 or 97-122*/
  if ( (65 <= in && in <= 90) || (97 <= in && in <= 122) ) {
    return true;
  }
  return false;
}
string fromto(string input, int from, int to) {
  if ( from != 0 ) {
    input.erase(0, from);
  }
  if ( to - from != input.size() ) {
    input.erase(to - from, input.size());
  }
  return input;
}
vector<string> breaker(string in) {
  vector<string> blocks;

  for ( int i = 0; i <= in.length(); i++ ) {

    /*if it is a letter, append. if it is an opperator, append. if it is a number, continue.*/
    
    if ( isdigit(in[i]) ) {
      for ( int j = i; j <= in.length(); j++ ) {
        if ( isdigit(in[j]) ) {
          continue;
        }
        else {
          blocks.push_back(fromto(in, i, j));
          in.erase(i, j);
          break;
        }
      }
      i = 0;
    }
    if ( isletter(in[i]) ) {
      blocks.push_back(string(1, in[i]));
      in.erase(0, i);
      i = 0;
    }
    if ( isoperator(in[i]) ) {
      blocks.push_back(string(1, in[i]));
      in.erase(0, i);
      i = 0;
    }
  }

  for ( auto block : blocks ) {
    std::cout << "{" << block << "}, ";
  }
  return blocks;
}

var parser(string in) {
  for ( char c : in ) {
    if ( isspace(c) ) {
      in.erase(c);
    }
  }

  vector<string> blocks = breaker(in);
  return 0;
}

int main() {
  string temp;
  while ( 1 ) {
    std::cin >> temp;
    breaker(temp);
    std::cout << std::endl << std::endl;
  }
  return 0;
}