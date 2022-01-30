#include <string>
#include <algorithm>

//---------------------------------------------------
// 回文かどうかチェック O(max(L.length(), R.length()))
//---------------------------------------------------
bool is_kaibun(std::string &L, std::string &R)
{
	std::string tmp = R;
	std::reverse(tmp.begin(), tmp.end());
	return (L == tmp);
}