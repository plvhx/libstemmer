#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-30b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule30b::Rule30b()
{
}

Rule30b::~Rule30b()
{
}

bool Rule30b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^peng([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("k") + m0 + m1;

	return true;
}