#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-26b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule26b::Rule26b()
{
}

Rule26b::~Rule26b()
{
}

bool Rule26b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^pem([aiueo])(.*)$");
	string m0, m1;

	if (!reg_.FullMatch(buf_, &m0, &m1))
		return false;

	rbuf_ = string("p") + m0 + m1;

	return true;
}