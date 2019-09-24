#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-29.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule29::Rule29()
{
}

Rule29::~Rule29()
{
}

bool Rule29::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^peng([bcdfghjklmnpqrstvwxyz])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + m1;

	return true;
}