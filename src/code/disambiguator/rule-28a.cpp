#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-28a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule28a::Rule28a()
{
}

Rule28a::~Rule28a()
{
}

bool Rule28a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^pen([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("n") + m0 + m1;

	return true;
}