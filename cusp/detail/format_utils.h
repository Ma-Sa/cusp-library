/*
 *  Copyright 2008-2009 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


#pragma once

#include <cusp/coo_matrix.h>
#include <cusp/csr_matrix.h>
#include <cusp/dia_matrix.h>
#include <cusp/ell_matrix.h>
#include <cusp/hyb_matrix.h>

namespace cusp
{
namespace detail
{

template <typename OffsetArray, typename IndexArray>
void offsets_to_indices(const OffsetArray& offsets, IndexArray& indices);

template <typename IndexArray, typename OffsetArray>
void indices_to_offsets(const IndexArray& indices, OffsetArray& offsets);
    
template <typename IndexType, typename ValueType, typename MemorySpace,
          typename ArrayType>
void extract_diagonal(const cusp::csr_matrix<IndexType,ValueType,MemorySpace>& A, ArrayType& output);
    
template <typename IndexType, typename ValueType, typename MemorySpace,
          typename ArrayType>
void extract_diagonal(const cusp::coo_matrix<IndexType,ValueType,MemorySpace>& A, ArrayType& output);
    
template <typename IndexType, typename ValueType, typename MemorySpace,
          typename ArrayType>
void extract_diagonal(const cusp::ell_matrix<IndexType,ValueType,MemorySpace>& A, ArrayType& output);

} // end namespace detail
} // end namespace cusp

#include <cusp/detail/format_utils.inl>
