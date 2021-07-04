/**
 * KMP - Knuth-Morris-Pratt implementation in C++.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<vector>
#include<string>

using namespace std;

/**
 * Calculate prefix function of a string
 * @param  s string to calculate
 * @return   vector of prefix function.
 */
vector<int> calculateStringPrefixFunction(const string& s) {
  vector<int> prefixFunction(s.length(), 0);

  int border = 0;
  for (int i = 1; i < (int)s.length(); ++i) {
    while (border > 0 && s[i] != s[border])
      border = prefixFunction[border - 1];

    border = ((s[i] == s[border]) ? border + 1 : 0);

    prefixFunction[i] = border;
  }

  return prefixFunction;
}

/**
 * KMP - Knuth Morris Pratt.
 * @param  needle   string to find
 * @param  haystack where to find.
 * @return          vector of positions that needle appears in haystack,
 */
vector<int> KMP(const string& needle, const string& haystack) {
  vector<int> result;

  string Prattern = needle;
  Prattern += '$';
  Prattern += haystack;

  vector<int> test = calculateStringPrefixFunction(Prattern);

  for (int i = needle.length(); i < (int)Prattern.length(); ++i) {
    if (test[i] == (int)needle.length()) {
      result.push_back(i - 2 * needle.length());
    }
  }

  return result;
}

int main() {
  freopen("sample.inp", "r+", stdin);

  string needle, haystack; cin >> haystack >> needle;
  vector<int>appearence = KMP(needle, haystack);

  if (appearence.size() > 0) {
    cout << appearence.size() << '\n';
    for (const int& i : appearence) cout << i << ' ';
  }
  else cout << -1 << endl;
  return 0;
}
