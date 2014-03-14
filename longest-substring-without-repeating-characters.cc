#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
int pstrcmp(const void *data1, const void *data2)
{
    char **p = (char **) data1;
    char **q = (char **) data2;
    return strcmp(*p, *q);
}

class Solution {
  public:

    int comlen(char *p, char *q) {
	int i = 0;
	while (*p && (*p++ == *q++))
	    i++;
	 return i;
    } int lengthOfLongestSubstring1(string s) {
	int i, ch, n = 0, maxi, maxlen = 0;
	int MAXN = s.length();
	char c[MAXN + 1], *a[MAXN];
	strcpy(c, s.c_str());
	for (i = 0; i < MAXN; i++)
	    a[i] = c + i;
	qsort(a, MAXN, sizeof(char *), pstrcmp);
	for (i = 0; i < MAXN - 1; i++)
	    if (comlen(a[i], a[i + 1]) > maxlen) {
		maxlen = comlen(a[i], a[i + 1]);
		maxi = i;
	    }
	return maxlen;
    }

    int lengthOfLongestSubstring(string s) {
	int len = 0;
	string sub("");
	int count = 0;

	for (int i = 0; i < s.length(); i++) {
	    if (sub.find_first_of(s[i]) == std::string::npos) {
		sub += s[i];
	    } else {
		if (len < sub.length()) {
		    len = sub.length();
		}
		sub.clear();
		i = count++;
	    }
	}

	if (len < sub.length())
	    len = sub.length();

	return len;
    }
};

int main()
{
    //string str("123qwertyuioplkjhfdsa123");
    //string str("321");
    //string str("");
    string
	str
	("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    Solution S;
    cout << "max len:" << S.lengthOfLongestSubstring(str) << endl;

    return 0;
}
