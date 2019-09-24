#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-13a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule13a::Rule13a()
{
}

Rule13a::~Rule13a()
{
}

bool Rule13a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^mem([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("m") + m0 + m1;

	return true;
}