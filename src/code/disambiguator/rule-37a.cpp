#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-37a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule37a::Rule37a()
{
}

Rule37a::~Rule37a()
{
}

bool Rule37a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^([bcdfghjklmnpqrstvwxyz])(er[aiueo])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	rbuf_ = m0 + m1 + m2;

	return true;
}