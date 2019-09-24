#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-16.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule16::Rule16()
{
}

Rule16::~Rule16()
{
}

bool Rule16::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^meng([g|h|q|k])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + m1;

	return true;
}