#pragma once

const int n_max=2000;
const int l_max=2000;


bool read(int& n, int& cnt, std::string words[n_max]);

void max_letters(int cnt, std::string words[n_max], int counter_letters[n_max]);
void clean_words(int cnt, std::string words[n_max]);
void sort(int cnt, std::string words[n_max], int counter_letters[n_max]);
void delete_unsuitable_words(int& cnt, std::string words[n_max], int counter_letters[n_max]);


void final_write(int n, int cnt, std::string words[n_max], int counter_letters[n_max]);
void full_write(int n, int cnt, std::string words[n_max], int counter_letters[n_max]);
