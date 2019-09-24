#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-13b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule13b::Rule13b()
{
}

Rule13b::~Rule13b()
{
}

bool Rule13b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^mem([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("p") + m0 + m1;

	return true;
}