#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-2.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule2::Rule2()
{
}

Rule2::~Rule2()
{
}

bool Rule2::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ber([bcdfghjklmnpqrstvwxyz])([a-z])(.*)$");
	string m0, m1, m2;

	if (!reg_.FullMatch(buf_, &m0, &m1, &m2))
		return false;

	if (RE("^er(.*)$").FullMatch(m2))
		return false;

	rbuf_ = m0 + m1 + m2;

	return true;
}