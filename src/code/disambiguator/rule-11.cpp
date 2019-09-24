#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-11.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule11::Rule11()
{
}

Rule11::~Rule11()
{
}

bool Rule11::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^mem([bfv])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + m1;

	return true;
}