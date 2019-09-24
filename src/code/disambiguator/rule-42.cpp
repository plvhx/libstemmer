#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-42.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule42::Rule42()
{
}

Rule42::~Rule42()
{
}

bool Rule42::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^kau(.*)$");
	string m0;

	if (!reg_.FullMatch(buf_, &m0))
		return false;

	rbuf_ = m0;

	return true;
}