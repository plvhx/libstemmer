#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-36.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule36::Rule36()
{
}

Rule36::~Rule36()
{
}

bool Rule36::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^pe([bcdfghjkpqstvxz])(er[bcdfghjklmnpqrstvwxyz])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	rbuf_ = m0 + m1 + m2;

	return true;
}