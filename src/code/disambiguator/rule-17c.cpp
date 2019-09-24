#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-17c.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule17c::Rule17c()
{
}

Rule17c::~Rule17c()
{
}

bool Rule17c::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^menge(.*)$");
	string m0;

	if (!reg_.FullMatch(buf_, &m0))
		return false;

	rbuf_ = m0;

	return true;
}