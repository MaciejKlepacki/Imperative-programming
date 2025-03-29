#include <stdio.h>
#include <stdlib.h>
#define N 20

int cnt[2];
char filler = '_';

int rnd(const int min, const int max) {
    return (rand() % (max - min)) + min;
}

void print(char board[][N], const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// void start(char board[][N], const int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             board[i][j] = filler; // Puste pole
//         }
//     }
//     for (int i = 0; i < n; i += 2) {
//         board[0][i] = board[2][i] = board[1][i+1] = board[3][i+1] = '1';
//         board[n-1][i+1] = board[n-3][i+1] = board[n-2][i] = board[n-4][i] = '2';
//     }
// }

void start(char board[][N], const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = filler; // Puste pole
        }
    }

    // Ustawianie bierek gracza 1
    for (int i = 0; i < 4; i++) { // Pierwsze 4 rzędy
        for (int j = (i % 2); j < n; j += 2) { // Ciemne pola
            board[i][j] = '1';
        }
    }

    // Ustawianie bierek gracza 2
    for (int i = n - 4; i < n; i++) { // Ostatnie 4 rzędy
        for (int j = (i % 2); j < n; j += 2) { // Ciemne pola
            board[i][j] = '2';
        }
    }
}

int move(char board[][N], const int i, const int j, const int n) {
    if (board[i][j] == '1') { // Gracz 1
        if (i + 1 < n && j + 1 < n && board[i+1][j+1] == filler) {
            board[i+1][j+1] = '1';
            board[i][j] = filler;
            return 1;
        }
        if (i + 1 < n && j - 1 >= 0 && board[i+1][j-1] == filler) {
            board[i+1][j-1] = '1';
            board[i][j] = filler;
            return 1;
        }
    } else if (board[i][j] == '2') { // Gracz 2
        if (i - 1 >= 0 && j + 1 < n && board[i-1][j+1] == filler) {
            board[i-1][j+1] = '2';
            board[i][j] = filler;
            return 1;
        }
        if (i - 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] == filler) {
            board[i-1][j-1] = '2';
            board[i][j] = filler;
            return 1;
        }
    }
    return 0; // Ruch niemożliwy
}

// int move(char board[][N], const int i, const int j, const int n) {
//     if (board[i][j] == '1') {
//         if (j<n-1 && i<n-1 && board[i+1][j+1]==filler) {
//             board[i+1][j+1] = '1';
//         } else if (j>0 && i<n-1 && board[i+1][j-1]==filler) {
//             board[i+1][j-1] = '1';
//         } else {
//             return 0;
//         }
//         board[i][j] = filler;
//         return 1;
//     } else if (board[i][j] == '2') {
//         if (j<n-1 && i>0 && board[i-1][j+1]==filler) {
//             board[i-1][j+1] = '2';
//         } else if (j>0 && i>0 && board[i-1][j-1]==filler) {
//             board[i-1][j-1] = '2';
//         } else {
//             return 0;
//         }
//         board[i][j] = filler;
//         return 1;
//     } else {
//         return 0;
//     }
// }

int capture(char board[][N], const int i, const int j, const int n) {
    if (board[i][j] == '1') { // Gracz 1
        if (i + 2 < n && j + 2 < n && board[i+1][j+1] == '2' && board[i+2][j+2] == filler) {
            board[i+1][j+1] = filler;
            board[i+2][j+2] = '1';
            board[i][j] = filler;
            cnt[1]--;
            return 1;
        }
        if (i + 2 < n && j - 2 >= 0 && board[i+1][j-1] == '2' && board[i+2][j-2] == filler) {
            board[i+1][j-1] = filler;
            board[i+2][j-2] = '1';
            board[i][j] = filler;
            cnt[1]--;
            return 1;
        }
    } else if (board[i][j] == '2') { // Gracz 2
        if (i - 2 >= 0 && j + 2 < n && board[i-1][j+1] == '1' && board[i-2][j+2] == filler) {
            board[i-1][j+1] = filler;
            board[i-2][j+2] = '2';
            board[i][j] = filler;
            cnt[0]--;
            return 1;
        }
        if (i - 2 >= 0 && j - 2 >= 0 && board[i-1][j-1] == '1' && board[i-2][j-2] == filler) {
            board[i-1][j-1] = filler;
            board[i-2][j-2] = '2';
            board[i][j] = filler;
            cnt[0]--;
            return 1;
        }
    }
    return 0; // Bicie niemożliwe
}

// int capture(char board[][N], const int i, const int j, const int n) {
//     if (board[i][j]=='1') {
//         if (j<n-2 && i<n-2 && board[i+1][j+1]=='2' && board[i+2][j+2]==filler) {
//             board[i+1][j+1] = filler;
//             board[i+2][j+2] = '1';
//         } else if (j>1 && i<n-2 && board[i+1][j-1]=='2' && board[i+2][j-2]==filler) {
//             board[i+1][j-1] = filler;
//             board[i+2][j-2] = '1';
//         } else {
//             return 0;
//         }
//         board[i][j] = filler;
//         cnt[1]--;
//         return 1;
//     } else if (board[i][j]=='2') {
//         if (j<n-2 && i>1 && board[i-1][j+1]=='1' && board[i-2][j+2]==filler) {
//             board[i-1][j+1] = filler;
//             board[i-2][j+2] = '2';
//         } else if (j>1 && i>1 && board[i-1][j-1]=='1' && board[i-2][j-2]==filler) {
//             board[i-1][j-1] = filler;
//             board[i-2][j-2] = '2';
//         } else {
//             return 0;
//         }
//         board[i][j] = filler;
//         cnt[0]--;
//         return 1;
//     } else {
//         return 0;
//     }
// }


int main(void) {
    char board[N][N];
    int n, steps;
    unsigned seed;
    scanf("%d %u %d", &n, &seed, &steps);
    srand(seed);
    cnt[0] = cnt[1] = 2 * n;
    start(board, n);
    for (int i = 0; i < steps; i++) {
        int ix, iy, attempts=0;
        const char turn = (i % 2 == 0) ? '1' : '2';
        do {
            ix = rnd(0, n);
            iy = rnd(0, n);
            attempts++;
            if(attempts > 1000) break; // safety break
        } while(board[ix][iy] != turn);
        if(attempts > 1000)
            break; // no available piece, end simulation early
        if (!capture(board, ix, iy, n)) {
            move(board, ix, iy, n);
        }
    }
    print(board, n);
    printf("%d %d\n", cnt[0], cnt[1]);

    return 0;
}

