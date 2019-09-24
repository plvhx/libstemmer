#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-15b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule15b::Rule15b()
{
}

Rule15b::~Rule15b()
{
}

bool Rule15b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^men([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("t") + m0 + m1;

	return true;
}