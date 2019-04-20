// GEEKSFORGEEKS: LONGEST PALINDROME SUBSEQUENCE.
// SAME OUTPUT: https://ideone.com/jt4Vej
// DYNAMIC APPROACH.

#include <iostream>
#include <fstream>
#include <string>

std::ifstream afile("LONGESTPALIND.INP", std::ios::in);
std::ofstream bfile("LONGESTPALIND.OUT", std::ios::out);

int T;
std::string S;

int LONGESTPALIND(std::string s);

void read() {
    afile >> T;

    while (T--) {
        afile >> S;

        bfile << LONGESTPALIND(S) << std::endl;
    }
}

int main() {
    read();

    afile.close();
    bfile.close();
    return 0;
}

int LONGESTPALIND(std::string s) {
    int N = s.length();
    int L[N][N];

    for (int i = 0; i < N; ++i)
        L[i][i] = 1;

    for (int k = 2; k <= N; ++k)
        for (int i = 0; i < N - k + 1; ++i)
        {
            int j = i + k - 1;

			// EXPLANATION FOR « 2 »
			// WHEN 2 CHARACTER EACH SIDE IS THE SAME,
			// THEN THESE 2 CHARACTER MADE A PALINDROME.
			// SO THE LONGEST PALINDROME += 2.
			
            if (S[i] == S[j] && k == 2)
                L[i][j] = 2;
            else if (S[i] == S[j])
                L[i][j] = L[i + 1][j - 1] + 2;
            else L[i][j] = std::max(L[i][j - 1], L[i + 1][j]);
        }

    return L[0][N - 1];

}
