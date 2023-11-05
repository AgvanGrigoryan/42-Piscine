#ifndef MAIN_C_VALIDATE_H
#define MAIN_C_VALIDATE_H
#include <stdbool.h>

bool is_dubl(int **map, int i, int j);
bool seems_horizontal(int *line, int cnt_arr[2], int vis_builds[16]);
bool seems_vertical(int j, int **map, int cnt_arr[2], int vis_builds[16]);

#endif //MAIN_C_SOLVING_H
