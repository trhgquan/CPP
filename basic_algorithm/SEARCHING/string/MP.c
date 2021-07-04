/**
 * Morris - Patt String Searching Algorithm.
 *
 *
 */
#include<stdio.h>
#include<string.h>

void MP_createNext(char* P, int N[]) {
  int m, i, j;
  m = strlen(P);
  N[0] = -1; i = 0; j = -1;
  while (i < m - 1) {
    if ((j == -1) || (P[i] == P[j])) {
      ++i; ++j; N[i] = j;
    }
    else j = N[j];
  }
}

int MP_stringSearch(char* P, char* T) {
  int N[strlen(P)];
  MP_createNext(P, N);

  int n = strlen(T);
  int m = strlen(P);
  int i = 0, j = 0;

  while (i < n) {
    if (T[i] == P[j]) {
      ++i; ++j;
      if (j == m) return i - j;
    }
    else {
      if (j > 0) j = N[j];
      else ++i;
    }
  }

  return -1;
}

int main() {
  freopen("sample.inp", "r+", stdin);
  char P[101], T[101]; scanf("%s%s", P, T);

  int indexResult = MP_stringSearch(T, P);
  if (indexResult == -1) printf("Cannot found %s inside %s.\n", T, P);
  else printf("Found %s at position %d inside %s.\n", T, indexResult, P);
  return 0;
}
