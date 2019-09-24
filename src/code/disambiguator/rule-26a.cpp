#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-26a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule26a::Rule26a()
{
}

Rule26a::~Rule26a()
{
}

bool Rule26a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^pem([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("m") + m0 + m1;

	return true;
}