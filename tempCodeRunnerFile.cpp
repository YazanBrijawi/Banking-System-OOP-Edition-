#include <cstdio>

 int main() {
 int M[2][3] = {{1, 2, 3}, {4, 5, 6}};

 char* b = (char*)&M[0][0];

 printf("row by row:\n");
  for (int i = 0; i < 2; i++) // rows outside
  for (int j = 0; j < 3; j++) // columns inside
  printf( "M[%d][%d]=%d at +%2d\n", i, j, M[i][j],
  (int)((char*)&M[i][j] - b));
 
  printf("column by column:\n");
  for (int j = 0; j < 3; j++) // columns outside
 for (int i = 0; i < 2; i++) // rows inside
 printf("M[%d][%d]=%d at +%2d\n", i, j, M[i][j],
 (int)((char*)&M[i][j] - b));
 }