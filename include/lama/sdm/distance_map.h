/*
 * IRIS Localization and Mapping (LaMa)
 *
 * Copyright (c) 2019-today, Eurico Pedrosa, University of Aveiro - Portugal
 * All rights reserved.
 * License: New BSD
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University of Aveiro nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#pragma once

#include <fstream>

#include "map.h"

namespace lama {

/**
 * Calculates the distance to the closest occupied cells in the map.
 */
struct DistanceMap : public Map {

    DistanceMap(double resolution, size_t cell_size, uint32_t patch_size, bool is3d)
        : Map(resolution, cell_size, patch_size, is3d)
    {}

    DistanceMap(const DistanceMap& other)
        : Map(other)
    {}

    virtual ~DistanceMap()
    {}

    /**
     * Get the closest distance from the given coordinates.
     *
     * @param[in]  coordinates  Query coordinates.
     * @param[out] gradient     The gradient (or partial derivatives) at @p coordinates.
     *
     * @returns The distance to the closest occupied cell.
     */
    virtual double distance(const Vector3d& coordinates, Vector3d* gradient) const = 0;
    virtual double distance(const Vector3ui& coordinates) const = 0;

    virtual void setMaxDistance(double distance) = 0;
    virtual double maxDistance() const = 0;
};

} /* lama */

