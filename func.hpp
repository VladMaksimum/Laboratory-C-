#pragma once

const int n_max = 100;

void read(char map[n_max][n_max],int& n, int& m);
void find_end_start(int& is, int& js, int& ie, int& je, char map[n_max][n_max], int n, int m,int table[n_max][n_max]);
void search(char map[n_max][n_max], int i, int j, int steps, int n, int m, int table[n_max][n_max]);
void write(int table[n_max][n_max], int n ,int m);