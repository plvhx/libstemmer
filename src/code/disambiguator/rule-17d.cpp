#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-17d.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule17d::Rule17d()
{
}

Rule17d::~Rule17d()
{
}

bool Rule17d::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^meng([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("ng") + m0 + m1;

	return true;
}