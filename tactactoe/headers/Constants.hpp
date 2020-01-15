#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

const char EMPTY = '-';
const char O = 'o';
const char X = 'x';
const int MAX = 9;
enum GameState {
  Draw,
  Win,
  Playing
};
enum BP {
  TL,
  T,
  TR,
  ML,
  M,
  MR,
  BL,
  B,
  BR
};

#endif
