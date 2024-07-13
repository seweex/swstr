#ifndef _SWSTR_INCLUDE_
#define _SWSTR_INCLUDE_

#include <string>

namespace seweex
{
	namespace detail
	{
		static constexpr char _KEY_NOT_CONTAINED[] = "the _Key is not contained in the _Str";
	}

	template<typename _Ty>
	using str_t = std::basic_string<_Ty>;

	template<typename _Ty>
	str_t<_Ty> substr_before_key(const str_t<_Ty>& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiter{ std::find(_Str.begin(), _Str.end(), _Key) };
		if (_keyiter == _Str.end()) 
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _Str.begin(), _keyiter);
		return _res;
	}
	template<typename _Ty>
	str_t<_Ty> substr_before_key(str_t<_Ty>&& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiter{ std::find(_Str.begin(), _Str.end(), _Key) };
		if (_keyiter == _Str.end())
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _Str.begin(), _keyiter);
		return _res;
	}

	template<typename _Ty>
	str_t<_Ty> substr_after_key(const str_t<_Ty>& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiter{ std::find(_Str.begin(), _Str.end(), _Key) };
		if (_keyiter == _Str.end())
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _keyiter + 1, _Str.end());
		return _res;
	}
	template<typename _Ty>
	str_t<_Ty> substr_after_key(str_t<_Ty>&& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiter{ std::find(_Str.begin(), _Str.end(), _Key) };
		if (_keyiter == _Str.end())
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _keyiter + 1, _Str.end());
		return _res;
	}

	template<typename _Ty>
	str_t<_Ty> substr_between_key(const str_t<_Ty>& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiterleft{ std::find(_Str.begin(), _Str.end(), _Key) };
		auto _keyiterright{ std::find(_Str.rbegin(), _Str.rend(), _Key) };
		if (_keyiterleft == _Str.end() or _keyiterright == _Str.rend())
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _keyiterleft + 1, _keyiterright.base() - 1);
		return _res;
	}
	template<typename _Ty>
	str_t<_Ty> substr_between_key(str_t<_Ty>&& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiterleft{ std::find(_Str.begin(), _Str.end(), _Key) };
		auto _keyiterright{ std::find(_Str.rbegin(), _Str.rend(), _Key) };
		if (_keyiterleft == _Str.end() or _keyiterright == _Str.rend())
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _keyiterleft + 1, _keyiterright.base() - 1);
		return _res;
	}

	/* Others */

	template<typename _Ty>
	str_t<_Ty> substr_before_key_lastin(const str_t<_Ty>& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiter{ std::find(_Str.rbegin(), _Str.rend(), _Key) };
		if (_keyiter == _Str.rend())
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _Str.begin(), _keyiter.base() - 1);
		return _res;
	}
	template<typename _Ty>
	str_t<_Ty> substr_before_key_lastin(str_t<_Ty>&& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiter{ std::find(_Str.rbegin(), _Str.rend(), _Key) };
		if (_keyiter == _Str.rend())
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _Str.begin(), _keyiter.base() - 1);
		return _res;
	}

	template<typename _Ty>
	str_t<_Ty> substr_after_key_lastin(const str_t<_Ty>& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiter{ std::find(_Str.rbegin(), _Str.rend(), _Key)};
		if (_keyiter == _Str.rend())
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _keyiter.base(), _Str.end());
		return _res;
	}
	template<typename _Ty>
	str_t<_Ty> substr_after_key_lastin(str_t<_Ty>&& _Str, _Ty _Key)
	{
		str_t<_Ty> _res{};
		_res.reserve(_Str.size());
		auto _keyiter{ std::find(_Str.rbegin(), _Str.rend(), _Key) };
		if (_keyiter == _Str.rend())
			std::_Xout_of_range(detail::_KEY_NOT_CONTAINED);
		_res.insert(_res.end(), _keyiter.base(), _Str.end());
		return _res;
	}
}
#endif