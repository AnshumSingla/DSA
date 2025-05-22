#include <stdio.h>
#include <string>
using namespace std;

void bruteforce(int n, int m, string text, string pattern)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (text[i + j] != pattern[j])
        break;

      if (j == m - 1)
        printf("Pattern found at index %d\n", i);
    }
  }
}

int main()
{
  string text = "aabaacaadaabaaba";
  string pattern = "aaba";

  int n = text.length(), m = pattern.length();

  return 0;
}