//
// Copyright (c) 2017 James E. King III
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//   https://www.boost.org/LICENSE_1_0.txt)
//
// BCrypt provider for entropy
//

#include <cstddef>
#include <boost/config.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/move/core.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include <boost/winapi/bcrypt.hpp>
#include <boost/winapi/get_last_error.hpp>
#include <boost/throw_exception.hpp>

#if defined(BOOST_UUID_FORCE_AUTO_LINK) || (!defined(BOOST_ALL_NO_LIB) && !defined(BOOST_UUID_RANDOM_PROVIDER_NO_LIB))
#   define BOOST_LIB_NAME "bcrypt"
#   if defined(BOOST_AUTO_LINK_NOMANGLE)
#      include <boost/config/auto_link.hpp>
#   else
#      define BOOST_AUTO_LINK_NOMANGLE
#      include <boost/config/auto_link.hpp>
#      undef BOOST_AUTO_LINK_NOMANGLE
#   endif
#endif

namespace zr_boost_1_81 {
namespace uuids {
namespace detail {

class random_provider_base
{
    BOOST_MOVABLE_BUT_NOT_COPYABLE(random_provider_base)

public:
    random_provider_base()
      : hProv_(NULL)
    {
        zr_boost_1_81::winapi::NTSTATUS_ status =
            zr_boost_1_81::winapi::BCryptOpenAlgorithmProvider(
                &hProv_, 
                zr_boost_1_81::winapi::BCRYPT_RNG_ALGORITHM_,
                NULL,
                0);

        if (BOOST_UNLIKELY(status != 0))
        {
            BOOST_THROW_EXCEPTION(entropy_error(status, "BCryptOpenAlgorithmProvider"));
        }
    }

    random_provider_base(BOOST_RV_REF(random_provider_base) that) BOOST_NOEXCEPT : hProv_(that.hProv_)
    {
        that.hProv_ = NULL;
    }

    random_provider_base& operator= (BOOST_RV_REF(random_provider_base) that) BOOST_NOEXCEPT
    {
        destroy();
        hProv_ = that.hProv_;
        that.hProv_ = NULL;
        return *this;
    }

    ~random_provider_base() BOOST_NOEXCEPT
    {
        destroy();
    }

    //! Obtain entropy and place it into a memory location
    //! \param[in]  buf  the location to write entropy
    //! \param[in]  siz  the number of bytes to acquire
    void get_random_bytes(void *buf, std::size_t siz)
    {
        zr_boost_1_81::winapi::NTSTATUS_ status =
            zr_boost_1_81::winapi::BCryptGenRandom(
                hProv_,
                static_cast<zr_boost_1_81::winapi::PUCHAR_>(buf),
                zr_boost_1_81::numeric_cast<zr_boost_1_81::winapi::ULONG_>(siz),
                0);

        if (BOOST_UNLIKELY(status != 0))
        {
            BOOST_THROW_EXCEPTION(entropy_error(status, "BCryptGenRandom"));
        }
    }

private:
    void destroy() BOOST_NOEXCEPT
    {
        if (hProv_)
        {
            zr_boost_1_81::ignore_unused(zr_boost_1_81::winapi::BCryptCloseAlgorithmProvider(hProv_, 0));
        }
    }

private:
    zr_boost_1_81::winapi::BCRYPT_ALG_HANDLE_ hProv_;
};

} // detail
} // uuids
} // boost
