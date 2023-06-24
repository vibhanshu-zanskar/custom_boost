/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8

// (C) Copyright 2002-4 Pavel Vozenilek .
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Provides non-intrusive serialization for zr_boost_1_81::optional.

#ifndef BOOST_SERIALIZATION_OPTIONAL_HPP_
#define BOOST_SERIALIZATION_OPTIONAL_HPP_

#if defined(_MSC_VER)
# pragma once
#endif

#include <boost/config.hpp>

#include <boost/optional.hpp>

#include <boost/serialization/item_version_type.hpp>
#include <boost/serialization/library_version_type.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/serialization/detail/is_default_constructible.hpp>

// function specializations must be defined in the appropriate
// namespace - zr_boost_1_81::serialization
namespace zr_boost_1_81 {
namespace serialization {

template<class Archive, class T>
void save(
    Archive & ar,
    const zr_boost_1_81::optional< T > & t,
    const unsigned int /*version*/
){
    // It is an inherent limitation to the serialization of optional.hpp
    // that the underlying type must be either a pointer or must have a
    // default constructor.  It's possible that this could change sometime
    // in the future, but for now, one will have to work around it.  This can
    // be done by serialization the optional<T> as optional<T *>
    #if ! defined(BOOST_NO_CXX11_HDR_TYPE_TRAITS)
        BOOST_STATIC_ASSERT(
            zr_boost_1_81::serialization::detail::is_default_constructible<T>::value
            || zr_boost_1_81::is_pointer<T>::value
        );
    #endif
    const bool tflag = t.is_initialized();
    ar << zr_boost_1_81::serialization::make_nvp("initialized", tflag);
    if (tflag){
        ar << zr_boost_1_81::serialization::make_nvp("value", *t);
    }
}

template<class Archive, class T>
void load(
    Archive & ar,
    zr_boost_1_81::optional< T > & t,
    const unsigned int version
){
    bool tflag;
    ar >> zr_boost_1_81::serialization::make_nvp("initialized", tflag);
    if(! tflag){
        t.reset();
        return;
    }

    if(0 == version){
        zr_boost_1_81::serialization::item_version_type item_version(0);
        zr_boost_1_81::serialization::library_version_type library_version(
            ar.get_library_version()
        );
        if(zr_boost_1_81::serialization::library_version_type(3) < library_version){
            ar >> BOOST_SERIALIZATION_NVP(item_version);
        }
    }
    if(! t.is_initialized())
        t = T();
    ar >> zr_boost_1_81::serialization::make_nvp("value", *t);
}

template<class Archive, class T>
void serialize(
    Archive & ar,
    zr_boost_1_81::optional< T > & t,
    const unsigned int version
){
    zr_boost_1_81::serialization::split_free(ar, t, version);
}

template<class T>
struct version<zr_boost_1_81::optional<T> > {
    BOOST_STATIC_CONSTANT(int, value = 1);
};

} // serialization
} // boost

#endif // BOOST_SERIALIZATION_OPTIONAL_HPP_
