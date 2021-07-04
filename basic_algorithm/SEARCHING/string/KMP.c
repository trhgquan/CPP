/**
 * Knuth-Morris-Pratt (KMP) Algorithm to find all appearences of a substring inside a string.
 *
 * Implemented from Wikipedia's pseudocode.
 * https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm
 */

#include<stdio.h>
#include<string.h>

/**
 * This function finds the first appearence of needle inside haystack.
 * @param  needle   string to find
 * @param  haystack string to find needle inside it.
 * @return          position of the first appearence of needle inside haystack.
 */
int KMP_FA(char* needle, char* haystack) {
  int m = 0; int i = 0;
  int T[strlen(haystack) + 1]; memset(T, 0, sizeof(T));
  T[0] = -1;

  while (m + i < (int)strlen(haystack)) {
    if (needle[i] == haystack[m + i]) {
      ++i;
      if (i == (int)strlen(needle)) return m;
    } else {
      if (T[i] > -1) {
        i = T[i];
        m = m + i - T[i];
      } else {
        i = 0;
        ++m;
      }
    }
  }

  return strlen(haystack);
}

/**
 * This function find all indexes that needle existed inside haystack
 * @param needle   string to find
 * @param haystack string to find needle inside it.
 */
void KMP_list(char* needle, char* haystack) {
  int j, k; j = k = 0;
  int T[strlen(haystack) + 1]; memset(T, 0, sizeof(T)); T[0] = -1;

  // Computing the table.
  int currentPosition = 1;
  int currentCandidate = 0;

  while (currentPosition < (int)strlen(needle)) {
    if (needle[currentPosition] == needle[currentCandidate])
      T[currentPosition] = T[currentCandidate];
    else {
      T[currentPosition] = currentCandidate;
      currentCandidate = T[currentCandidate];

      while (currentCandidate >= 0 && (needle[currentPosition] != needle[currentCandidate]))
        currentCandidate = T[currentCandidate];
    }

    ++currentPosition; ++currentCandidate;
  }

  T[currentPosition] = currentCandidate;

  // From here the KMP Algorithm starts.
  int P[strlen(haystack) + 1];
  int nP = 0;

  while (j < (int)strlen(haystack)) {
    if (needle[k] == haystack[j]) {
      ++j; ++k;
      if (k == (int)strlen(needle)) {
        P[nP++] = j - k;
        k = T[k];
      }
    } else {
      k = T[k];
      if (k < 0) {
        ++j; ++k;
      }
    }
  }

  if (nP == 0) printf("Can't found the string %s inside %s.\n", needle, haystack);
  else {
    printf("Total %d indexes found:\n", nP);
    for (int i = 0; i < nP; ++i) printf("%d ", P[i]);
  }
}

int main() {
  freopen("sample.inp", "r+", stdin);
  char text[255]; char key[101]; scanf("%s%s", text, key);
  int foundPos = KMP_FA(key, text);

  if (foundPos == (int)strlen(text)) printf("Cannot found %s in %s.\n", key, text);
  else printf("Found %s first appeared at position %d in %s.\n", key, foundPos, text);

  KMP_list(key, text);
  return 0;
}
