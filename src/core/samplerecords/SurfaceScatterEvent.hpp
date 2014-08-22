#ifndef SCATTEREVENT_HPP_
#define SCATTEREVENT_HPP_

#include "bsdfs/BsdfLobes.hpp"

#include "math/Vec.hpp"

namespace Tungsten {

class IntersectionInfo;
class SampleGenerator;
class UniformSampler;

struct SurfaceScatterEvent
{
    const IntersectionInfo *info;
    SampleGenerator *sampler;
    UniformSampler *supplementalSampler;
    Vec3f wi, wo;
    Vec3f throughput;
    float pdf;
    BsdfLobes requestedLobe;
    BsdfLobes sampledLobe;

    SurfaceScatterEvent(const IntersectionInfo *info_,
                 SampleGenerator *sampler_,
                 UniformSampler *supplementalSampler_,
                 const Vec3f &wi_,
                 BsdfLobes requestedLobe_)
    : info(info_),
      sampler(sampler_),
      supplementalSampler(supplementalSampler_),
      wi(wi_),
      wo(0.0f),
      throughput(1.0f),
      pdf(1.0f),
      requestedLobe(requestedLobe_)
    {
    }

    SurfaceScatterEvent(const SurfaceScatterEvent &o,
                        const Vec3f &wi_,
                        const Vec3f &wo_)
    : info(o.info),
      sampler(o.sampler),
      supplementalSampler(o.supplementalSampler),
      wi(wi_),
      wo(wo_),
      throughput(1.0f),
      pdf(1.0f),
      requestedLobe(o.requestedLobe),
      sampledLobe(o.sampledLobe)
    {
    }
};

}

#endif /* SCATTEREVENT_HPP_ */