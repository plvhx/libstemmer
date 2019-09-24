#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-34.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule34::Rule34()
{
}

Rule34::~Rule34()
{
}

bool Rule34::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^pe([bcdfghjklmnpqrstvwxyz])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	if (RE("^er(.*)$").FullMatch(m1))
		return false;

	rbuf_ = m0 + m1;
 
	return true;
}