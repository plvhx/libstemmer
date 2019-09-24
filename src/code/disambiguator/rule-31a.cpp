#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-31a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule31a::Rule31a()
{
}

Rule31a::~Rule31a()
{
}

bool Rule31a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^peny([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("ny") + m0 + m1;

	return true;
}