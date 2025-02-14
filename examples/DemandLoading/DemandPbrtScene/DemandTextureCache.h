//
// Copyright (c) 2024, NVIDIA CORPORATION. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#pragma once

#include "DemandTextureCacheStatistics.h"

#include <memory>
#include <string>

namespace demandLoading {
class DemandLoader;
}

namespace demandPbrtScene {

class ImageSourceFactory;

class DemandTextureCache
{
  public:
    virtual ~DemandTextureCache() = default;

    virtual unsigned int createDiffuseTextureFromFile( const std::string& path )   = 0;
    virtual bool         hasDiffuseTextureForFile( const std::string& path ) const = 0;

    virtual unsigned int createAlphaTextureFromFile( const std::string& path )   = 0;
    virtual bool         hasAlphaTextureForFile( const std::string& path ) const = 0;

    virtual unsigned int createSkyboxTextureFromFile( const std::string& path )   = 0;
    virtual bool         hasSkyboxTextureForFile( const std::string& path ) const = 0;

    virtual DemandTextureCacheStatistics getStatistics() const = 0;
};

using DemandLoaderPtr       = std::shared_ptr<demandLoading::DemandLoader>;
using DemandTextureCachePtr = std::shared_ptr<DemandTextureCache>;
using ImageSourceFactoryPtr = std::shared_ptr<ImageSourceFactory>;

DemandTextureCachePtr createDemandTextureCache( DemandLoaderPtr demandLoader, ImageSourceFactoryPtr imageSourceFactory );

}  // namespace demandPbrtScene
