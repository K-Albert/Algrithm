#include <iostream>
#include <array>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdint.h>
using namespace std;



array<uint32_t, 5> a = { 4, 2, 3, 1, 5 };


bool cmp(const pair<uint32_t, uint32_t> &a, const pair<uint32_t, uint32_t> &b)
{
	return a.second > b.second;
}

int lxy(void)
{
	map<uint32_t, uint32_t>  st;
	vector<pair<uint32_t, uint32_t>> ttt;
	uint8_t num = 0;
	for (array<uint32_t, 5>::iterator count = a.begin(); count != a.end(); count++)
	{
		st[num] = *count;
		num++;
	}

	for (map<uint32_t, uint32_t>::iterator count = st.begin(); count != st.end(); count++)
	{
		ttt.push_back(*count);
	}

	sort(ttt.begin(), ttt.end(), cmp);

	for (vector<pair<uint32_t, uint32_t>>::iterator count = ttt.begin(); count != ttt.end(); count++)
	{
		cout << count->first << ' ' << count->second << endl;
	}

	getchar();
	return 0;
}
