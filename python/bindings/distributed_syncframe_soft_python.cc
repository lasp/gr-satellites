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
/* BINDTOOL_HEADER_FILE(distributed_syncframe_soft.h) */
/* BINDTOOL_HEADER_FILE_HASH(569378679955c86ca9300f6cf1d68b4d)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <satellites/distributed_syncframe_soft.h>
// pydoc.h is automatically generated in the build directory
#include <distributed_syncframe_soft_pydoc.h>

void bind_distributed_syncframe_soft(py::module& m)
{

    using distributed_syncframe_soft = ::gr::satellites::distributed_syncframe_soft;


    py::class_<distributed_syncframe_soft,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<distributed_syncframe_soft>>(
        m, "distributed_syncframe_soft", D(distributed_syncframe_soft))

        .def(py::init(&distributed_syncframe_soft::make),
             py::arg("threshold"),
             py::arg("syncword"),
             py::arg("step"),
             D(distributed_syncframe_soft, make))


        ;
}
