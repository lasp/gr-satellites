/*
 * Copyright 2021 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(nrzi_encode.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(a546ea66d18820f702b93d16ee4c2d23)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <satellites/nrzi_encode.h>
// pydoc.h is automatically generated in the build directory
#include <nrzi_encode_pydoc.h>

void bind_nrzi_encode(py::module& m)
{

    using nrzi_encode = ::gr::satellites::nrzi_encode;


    py::class_<nrzi_encode,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<nrzi_encode>>(m, "nrzi_encode", D(nrzi_encode))

        .def(py::init(&nrzi_encode::make), D(nrzi_encode, make))


        ;
}
