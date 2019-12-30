#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <map>
#include <iostream> 
#include <sstream> 
#include <string> 


const std::string FILE_PATH = "./the-king-james-bible.txt";
typedef std::pair<char, int> charCountPair;
typedef std::pair<std::string, int> wordCountPair;

void writeFileToVector(std::vector<std::string> & vector) {
  std::ifstream stream(FILE_PATH);
  if (stream.is_open()) {
    std::string line;
    while(std::getline(stream, line)) {
      vector.push_back(line);
    }
    stream.close();
  }
}

void addWordsToWordCounter(std::string & line, std::map<std::string, int> & wordCounter) {
  std::basic_istringstream iss(line);
  do { 
      std::string subs; 
      iss >> subs;
      subs.erase(std::remove_if(subs.begin(), subs.end(), [](char & c){
        return !isalpha(c);
      }), subs.end());
      if (subs != "") wordCounter[subs]++;
  } while (iss);
}

int main() {
  std::vector<std::string> lines;
  writeFileToVector(lines);

  int amountOfCharacters = 0;
  int amountOfAlphabeticCharacters = 0;

  std::map<char, int> charCounter;
  std::map<std::string, int> wordCounter;

  std::for_each(lines.begin(), lines.end(), [&amountOfCharacters, &amountOfAlphabeticCharacters, &charCounter, &wordCounter](std::string & line) {
    amountOfCharacters += line.size();
    std::transform(line.begin(), line.end(), line.begin(), [](unsigned char c){
      return std::tolower(c);
    });
    addWordsToWordCounter(line, wordCounter);
    std::for_each(line.begin(), line.end(), [&amountOfAlphabeticCharacters, &charCounter](char & a){
      if (isalpha(a)) {
        amountOfAlphabeticCharacters += 1;
        charCounter[a]++;
      }
    });
  });
  
  std::vector<charCountPair> charCountVector;
  std::vector<wordCountPair> wordCountVector;

  std::copy(charCounter.begin(), charCounter.end(), std::back_inserter<std::vector<charCountPair>>(charCountVector));
  std::copy(wordCounter.begin(), wordCounter.end(), std::back_inserter<std::vector<wordCountPair>>(wordCountVector));

  std::sort(charCountVector.begin(), charCountVector.end(), [](const charCountPair & a, const charCountPair & b) {
    return b.second < a.second;
  });

  std::sort(wordCountVector.begin(), wordCountVector.end(), [](const wordCountPair & a, const wordCountPair & b) {
    return b.second < a.second;
  });

  std::cout << "Amount of characters: " << amountOfCharacters << std::endl;
  std::cout << "Amount of letters [a-zA-Z]: " << amountOfAlphabeticCharacters << std::endl;
  std::cout << "Amount of lines: " << lines.size() << std::endl << std::endl;;

  std::cout << "Five most common letters" << std::endl;
  std::for_each(charCountVector.begin(), charCountVector.end(), [](charCountPair & pair) {
    std::cout << pair.first << " " << pair.second << std::endl;
  });
  std::cout << std::endl;

  std::cout << "Five most common words" << std::endl;
  std::for_each(wordCountVector.begin(), wordCountVector.begin() + 10, [](wordCountPair & pair) {
    std::cout << pair.first << " " << pair.second << std::endl;
  });

  return 0;
}