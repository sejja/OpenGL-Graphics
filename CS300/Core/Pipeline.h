#ifndef _PIPELINE__H_
#define _PIPELINE__H_

#include <queue>
#include <memory>
#include <glm/glm.hpp>

namespace Core {

	class Renderable;

	enum class GraphicsAPIS : unsigned char {
		OpenGL,
		Vulkan,
		DirectX11,
		DirectX12
	};

	class Pipeline {
	public:
		virtual void Init() = 0;
		virtual void PreRender() = 0;
		virtual void Render() = 0;
		virtual void PostRender() = 0;
		virtual void Shutdown() = 0;
		virtual void SetDimensions(const glm::lowp_u16vec2& dim) = 0;
	protected:
		std::priority_queue<std::shared_ptr<Renderable>> mRenderables;
	};
}

#endif