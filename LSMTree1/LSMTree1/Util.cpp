#include "Util.h"
#include <algorithm>
using namespace std;

  vector<Entry>Util::compact(const vector<vector<Entry>>& inputs) {
	size_t n = inputs.size();
	vector <Entry> ret;
	vector <size_t> pose(n);
	size_t nonEmpty = 0;
	for (size_t i = 0; i < n; ++i)
		if (!inputs[i].empty())
			++nonEmpty;
	while (nonEmpty) {
		uint64_t key = 0;
		string value;
		//找到键值最小的value和key

		--nonEmpty;
		ret.emplace_back(key, value);
	}
}