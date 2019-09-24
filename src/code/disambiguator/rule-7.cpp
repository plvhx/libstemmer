#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-7.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule7::Rule7()
{
}

Rule7::~Rule7()
{
}

bool Rule7::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ter([bcdfghjklmnpqrstvwxyz])er([aiueo].*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + string("er") + m1;

	return true;
}