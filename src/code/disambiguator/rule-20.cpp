#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-20.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule20::Rule20()
{
}

Rule20::~Rule20()
{
}

bool Rule20::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^pe([wy])([aiueo])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	rbuf_ = m0 + m1 + m2;

	return true;
}