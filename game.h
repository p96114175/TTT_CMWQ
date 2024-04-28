#pragma once

#define BOARD_SIZE 4
#define GOAL 3
#define ALLOW_EXCEED 1
#define N_GRIDS (BOARD_SIZE * BOARD_SIZE)
#define GET_INDEX(i, j) ((i) * (BOARD_SIZE) + (j))
#define GET_COL(x) ((x) % BOARD_SIZE)
#define GET_ROW(x) ((x) / BOARD_SIZE)

#define for_each_empty_grid(i, table) \
    for (int i = 0; i < N_GRIDS; i++) \
        if (table[i] == ' ')

typedef struct {
    int i_shift, j_shift;
    int i_lower_bound, j_lower_bound, i_upper_bound, j_upper_bound;
} line_t;

extern const line_t lines[4];

#define BOARD_BUFFER_SIZE                                               \
    ((BOARD_SIZE * (BOARD_SIZE + 1) << 1) + (BOARD_SIZE * BOARD_SIZE) + \
     ((BOARD_SIZE << 1) + 1) + 1)

int *available_moves(char *table);
char check_win(char *t);
double calculate_win_value(char win, char player);
// static int draw_board(char *t);
