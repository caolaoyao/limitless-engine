#include <limitless/pipeline/particle_pass.hpp>

#include <limitless/fx/effect_renderer.hpp>

using namespace Limitless;

ParticlePass::ParticlePass(Pipeline& pipeline, fx::EffectRenderer& _renderer, ms::Blending _blending)
    : RenderPass(pipeline)
    , renderer {_renderer}
    , blending {_blending} {
}

void ParticlePass::draw([[maybe_unused]] Instances& instances, Context& ctx, const Assets& assets, [[maybe_unused]] const Camera& camera, UniformSetter& setter) {
    renderer.get().draw(ctx, assets, ShaderPass::Forward, blending, setter);
}