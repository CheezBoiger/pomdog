//
//  Copyright (C) 2013 mogemimi.
//
//  Distributed under the MIT License.
//  See accompanying file LICENSE.md or copy at
//  http://enginetrouble.net/pomdog/LICENSE.md for details.
//

#ifndef POMDOG_LOGSTREAM_HPP
#define POMDOG_LOGSTREAM_HPP

#if (_MSC_VER > 1000)
#	pragma once
#endif

#include "LoggingLevel.hpp"
#include <type_traits>
#include <sstream>

namespace Pomdog {

class LogChannel;

/// @addtogroup Framework
/// @{
/// @addtogroup Logging
/// @{

///@~Japanese
/// @brief ログストリームです。
class LogStream
{
private:
	std::stringstream cache;
	LogChannel & channel;
	LoggingLevel verbosity;

public:
	LogStream(LogChannel & channel, LoggingLevel verbosity);
	LogStream(LogStream const&);
	LogStream(LogStream &&) = default;

	LogStream() = delete;
	LogStream & operator=(LogStream const&) = delete;
	LogStream & operator=(LogStream &&) = delete;
	
	virtual ~LogStream();

	template <typename T>
	LogStream & operator<<(T const& message);

	struct Flush {};
	LogStream & operator<<(Flush const&);
};

/// @}
/// @}

namespace Details {

template<typename E>
auto ToIntegral(E e)->typename std::underlying_type<E>::type
{
	return static_cast<typename std::underlying_type<E>::type>(e);
}

template <typename T>
auto LogStreamInvork(T const& message, typename std::enable_if<std::is_enum<T>::value>::type* = nullptr)->decltype(Details::ToIntegral(message))
{
	return ToIntegral(message);
}

template <typename T>
T const& LogStreamInvork(T const& message, typename std::enable_if<!std::is_enum<T>::value>::type* = nullptr)
{
	return message;
}

}// namespace Details

template <typename T>
LogStream & LogStream::operator<<(T const& message)
{
	cache << Details::LogStreamInvork(message);
	return *this;
}

}// namespace Pomdog

#endif // !defined(POMDOG_LOGSTREAM_HPP)