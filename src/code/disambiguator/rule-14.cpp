#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-14.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule14::Rule14()
{
}

Rule14::~Rule14()
{
}

bool Rule14::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^men([cdjstz])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + m1;

	return true;
}