#pragma once

const int n_max = 100;

void read(int& n, int matrix[n_max][n_max]);
void write(int n, int matrix[n_max][n_max]);

bool same_row(int n, int matrix[n_max][n_max]);
int min_in_column(int n, int j, int matrix[n_max][n_max]);

