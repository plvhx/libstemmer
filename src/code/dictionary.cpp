#include <cstdint>
#include <fstream>
#include <mutex>
#include <stemmer/dictionary.hpp>
#include <stemmer/hash.hpp>
#include <stemmer/util-macro.hpp>

using namespace stemmer;
using namespace std;

mutex mutex_;

Dictionary::Dictionary()
{
}

Dictionary::~Dictionary()
{
}

void Dictionary::add(string buf_)
{
	dict_.insert(make_pair(Hash().generate(buf_, DICT_CONST_HASH), buf_));
}

void Dictionary::remove(string buf_)
{
	for (map<uint32_t, string>::iterator iter_ = dict_.begin(); iter_ != dict_.end(); iter_++)
		if (buf_ == iter_->second) iter_ = dict_.erase(iter_);
}

void Dictionary::make(map<uint32_t, string> pdict_)
{
	dict_ = pdict_;
}

void Dictionary::makeFromFile(string file_)
{
	Hash ho_;
	ifstream df_;

	lock_guard<mutex> lock(mutex_);

	df_.open(file_);
	
	if (df_.is_open() && !df_.fail()) {
		string line_;

		while (getline(df_, line_)) {
			dict_.insert(make_pair(ho_.generate(line_, DICT_CONST_HASH), line_));
		}

		df_.close();
	}
}

bool Dictionary::search(string buf_)
{
	bool res_ = false;

	for (map<uint32_t, string>::iterator iter_ = dict_.begin(); iter_ != dict_.end(); iter_++) {
		if (buf_ == iter_->second) {
			res_ = true;
			break;
		}
	}

	return res_;
}

vector<string> Dictionary::items()
{
	vector<string> vval_(dict_.size());
	map<uint32_t, string>::iterator iter_;

	for (iter_ = dict_.begin(); iter_ != dict_.end(); iter_++) {
		vval_.push_back(iter_->second);
	}

	return vval_;
}

vector<uint32_t> Dictionary::keys()
{
	vector<uint32_t> vkey_(dict_.size());
	map<uint32_t, string>::iterator iter_;
	
	for (iter_ = dict_.begin(); iter_ != dict_.end(); iter_++) {
		vkey_.push_back(iter_->first);
	}

	return vkey_;
}

size_t Dictionary::size()
{
	return dict_.size();
}