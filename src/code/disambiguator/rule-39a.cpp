#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-39a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule39a::Rule39a()
{
}

Rule39a::~Rule39a()
{
}

bool Rule39a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^([bcdfghjklmnpqrstvwxyz])(em[aiueo])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	rbuf_ = m0 + m1 + m2;

	return true;
}