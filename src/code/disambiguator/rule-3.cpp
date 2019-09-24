#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-3.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;
using namespace stemmer::disambiguator;

Rule3::Rule3()
{
}

Rule3::~Rule3()
{
}

bool Rule3::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ber([bcdfghjklmnpqrstvwxyz])([a-z])er([aiueo])(.*)$");
	string m0, m1, m2, m3;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2, &m3))
		return false;

	if (m0 == string("r"))
		return false;

	rbuf_ = m0 + m1 + string("er") + m2 + m3;

	return true;
}