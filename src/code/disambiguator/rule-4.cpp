#include <stemmer/disambiguator-abstract.hpp>
#include <stemmer/disambiguator/rule-4.hpp>

using namespace std;
using namespace stemmer::disambiguator;

Rule4::Rule4()
{
}

Rule4::~Rule4()
{
}

bool Rule4::disambiguate(string buf_, string& rbuf_)
{
	if (buf_ != string("belajar"))
		return false;

	rbuf_ = string("ajar");

	return true;
}