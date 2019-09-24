#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-9.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;
using namespace stemmer::disambiguator;

Rule9::Rule9()
{
}

Rule9::~Rule9()
{
}

bool Rule9::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^te([bcdfghjklmnpqrstvwxyz])er([bcdfghjklmnpqrstvwxyz])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	if (m0 == string("r"))
		return false;

	rbuf_ = m0 + string("er") + m1 + m2;

	return true;
}