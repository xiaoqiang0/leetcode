#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
	string res;
	int i = a.length() - 1, j = b.length() - 1;
	int flag = 0;

	while (i >= 0 && j >= 0) {
	    int cur = 0;
	    if (flag == 1)
		cur++;
	    if (a[i] == '1')
		cur++;
	    if (b[j] == '1')
		cur++;

	    switch (cur) {
	      case 0:
		res = "0" + res;
		flag = 0;
		break;

		case 1:res = "1" + res;
		flag = 0;
		break;
		case 2:res = "0" + res;
		flag = 1;
		break;
		case 3:res = "1" + res;
		flag = 1;
		break;
	    }
	    j--;
	    i--;
	}

	while (i >= 0) {
	    int cur = 0;
	    if (flag == 1)
		cur++;
	    if (a[i] == '1')
		cur++;

	    switch (cur) {
	      case 0:
		res = "0" + res;
		flag = 0;
		break;
	      case 1:
		res = "1" + res;
		flag = 0;
		break;
	      case 2:
		res = "0" + res;
		flag = 1;
		break;
	    }

	    i--;

	}

	while (j >= 0) {
	    int cur = 0;
	    if (flag == 1)
		cur++;
	    if (b[j] == '1')
		cur++;

	    switch (cur) {
	      case 0:
		res = "0" + res;
		flag = 0;
		break;
	      case 1:
		res = "1" + res;
		flag = 0;
		break;
	      case 2:
		res = "0" + res;
		flag = 1;
		break;
	    }

	    j--;
	}

        if (flag == 1)
            res = "1" + res;

	return res;
    }
};

int main()
{
    string a("11");
    string b("");
    Solution S;


    cout  <<S.addBinary(a, b)<<endl;
    return 0;
}
