#pragma once

const int n_max=2000;

void read(int& cnt, std::string words[n_max]);
void write(int cnt, std::string words[n_max], int vowel_counter[n_max]);

void clean_words(int cnt, std::string words[n_max]);
void lower_case(int cnt, std::string words[n_max]);
bool find_palindrome(int cnt, std::string words[n_max]);
void count_letters(int cnt, std::string words[n_max], int vowel_counter[n_max]);
void sort_vowels(int cnt, std::string words[n_max], int vowel_counter[n_max]);
void sort_alphabet(int cnt, std::string words[n_max], int vowel_counter[n_max]);
void duplicate(int cnt, std::string words[n_max]);

