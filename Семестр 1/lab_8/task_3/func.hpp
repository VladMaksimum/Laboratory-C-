#pragma once

const int n_max=2000;
const int p_max = 4;

void read(int& cnt, std::string words[n_max]);
void write(int cnt, std::string words[n_max]);

void find_popular_letters(int cnt, std::string words[n_max], char popular_letters[p_max]);
void two_popular_in_row(int cnt, std::string words[n_max], char popular_letters[p_max]);

