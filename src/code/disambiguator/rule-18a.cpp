#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-18a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule18a::Rule18a()
{
}

Rule18a::~Rule18a()
{
}

bool Rule18a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^meny([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("ny") + m0 + m1;

	return true;
}