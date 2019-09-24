#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-21b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule21b::Rule21b()
{
}

Rule21b::~Rule21b()
{
}

bool Rule21b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^pe(r[aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + m1;

	return true;
}