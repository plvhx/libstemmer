#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-30c.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule30c::Rule30c()
{
}

Rule30c::~Rule30c()
{
}

bool Rule30c::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^penge(.*)$");
	string m0;

	if (!reg_.FullMatch(buf_, &m0))
		return false;

	rbuf_ = m0;

	return true;
}