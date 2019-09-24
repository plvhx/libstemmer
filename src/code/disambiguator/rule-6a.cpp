#include <pcrecpp.h>
#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-6a.hpp>

using namespace pcrecpp;
using namespace std;
using namespace stemmer::disambiguator;

Rule6a::Rule6a()
{
}

Rule6a::~Rule6a()
{
}

bool Rule6a::disambiguate(string buf_, string& rbuf_)
{
	RE reg_("^ter([aiueo].*)$");
	string m0;

	if (!reg_.FullMatch(buf_, &m0))
		return false;

	rbuf_ = m0;

	return true;
}