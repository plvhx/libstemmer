#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-30a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule30a::Rule30a()
{
}

Rule30a::~Rule30a()
{
}

bool Rule30a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^peng([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = m0 + m1;

	return true;
}