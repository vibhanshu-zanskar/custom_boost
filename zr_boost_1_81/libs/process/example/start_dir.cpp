// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/process.hpp>
#include <boost/process/filesystem.hpp>

namespace bp = zr_boost_1_81::process;

int main()
{
    bp::system(
        "test.exe",
        bp::start_dir="../foo"
    );

    zr_boost_1_81::process::filesystem::path exe = "test.exe";
    bp::system(
        zr_boost_1_81::process::filesystem::absolute(exe),
        bp::start_dir="../foo"
    );
}
