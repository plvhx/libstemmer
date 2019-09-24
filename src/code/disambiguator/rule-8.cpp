#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-8.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer;
using namespace stemmer::disambiguator;

Rule8::Rule8()
{
}

Rule8::~Rule8()
{
}

bool Rule8::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ter([bcdfghjklmnpqrstvwxyz])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	if (m0 == string("r") || RE("^er(.*)$").FullMatch(m1)) {
		return false;
	}
	
	rbuf_ = m0 + m1;

	return true;
}