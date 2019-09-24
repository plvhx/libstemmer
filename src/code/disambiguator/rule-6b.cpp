#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-6b.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule6b::Rule6b()
{
}

Rule6b::~Rule6b()
{
}

bool Rule6b::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ter([aiueo].*)$");
	string m0;

	if (!reg_.FullMatch(buf_, &m0))
		return false;

	rbuf_ = string("r") + m0;

	return true;
}