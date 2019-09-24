#ifndef _UTIL_MACRO_HPP_
#define _UTIL_MACRO_HPP_

#include <stdexcept>
#include <sstream>

namespace stemmer {

#ifndef THROW_ERROR
# define THROW_ERROR(msg) do { \
	std::ostringstream oss; \
	oss << msg; \
	throw std::runtime_error(oss.str()); \
} while (0);
#endif

}

#endif /* _UTIL_MACRO_HPP_ */