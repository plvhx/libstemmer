#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-39b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule39b::Rule39b()
{
}

Rule39b::~Rule39b()
{
}

bool Rule39b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^([bcdfghjklmnpqrstvwxyz])em([aiueo])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	rbuf_ = m0 + m1 + m2;

	return true;
}