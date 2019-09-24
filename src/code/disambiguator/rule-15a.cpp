#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-15a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule15a::Rule15a()
{
}

Rule15a::~Rule15a()
{
}

bool Rule15a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^men([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("n") + m0 + m1;

	return true;
}