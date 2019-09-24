#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-24.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;
using namespace stemmer::disambiguator;

Rule24::Rule24()
{
}

Rule24::~Rule24()
{
}

bool Rule24::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^per([bcdfghjklmnpqrstvwxyz])([a-z])er([aiueo])(.*)$");
	string m0, m1, m2, m3;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2, &m3))
		return false;

	if (m0 == string("r"))
		return false;

	rbuf_ = m0 + m1 + string("er") + m2 + m3;

	return true;
}