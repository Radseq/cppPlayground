#ifndef VARIADIC_TEMPLATE_HPP
#define VARIADIC_TEMPLATE_HPP

#include "pch.hpp"

namespace variadicTemplate
{
	// we must set base template to be see for second template
	template <typename T> double sum (const T& t) { return t; }

	// we add first argument and first temlate args
	template <typename T, typename... Args> double sum (const T& t, const Args&... args) { return t + sum (args...); }

	template <typename T> using Scope = std::unique_ptr<T>;
	template <typename T, typename... Args> constexpr Scope<T> CreateScope (Args&&... args)
	{
		return std::make_unique<T> (std::forward<Args> (args)...);
	}

	template <typename T> using Ref = std::shared_ptr<T>;
	template <typename T, typename... Args> constexpr Ref<T> CreateRef (Args&&... args)
	{
		return std::make_shared<T> (std::forward<Args> (args)...);
	}

}  // namespace variadicTemplate

#endif  // #define VARIADIC_TEMPLATE_HPP
