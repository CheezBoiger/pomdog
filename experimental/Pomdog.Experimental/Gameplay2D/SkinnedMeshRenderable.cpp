// Copyright (c) 2013-2017 mogemimi. Distributed under the MIT license.

#include "SkinnedMeshRenderable.hpp"
#include "../Rendering/Renderer.hpp"
#include "Pomdog.Experimental/Skeletal2D/SkeletonHelper.hpp"
#include "Pomdog.Experimental/Skeletal2D/SkinnedMesh.hpp"
#include "Pomdog.Experimental/Gameplay2D/Transform2D.hpp"

namespace Pomdog {
namespace {

//static Matrix3x2 CreateTransformMatrix3x2(Transform2D const& transform)
//{
//    return Matrix3x2::CreateScale(transform.Scale)
//        * Matrix3x2::CreateRotation(transform.Rotation)
//        * Matrix3x2::CreateTranslation(transform.Position);
//}

static Matrix4x4 CreateTransformMatrix4x4(Transform2D const& transform)
{
    return Matrix4x4::CreateScale({transform.Scale.X, transform.Scale.Y, 1.0f})
        * Matrix4x4::CreateRotationZ(transform.Rotation)
        * Matrix4x4::CreateTranslation({transform.Position.X, transform.Position.Y, 1.0f});
}

}// unnamed namespace

SkinnedMeshRenderable::SkinnedMeshRenderable(
    std::shared_ptr<Skeleton> const& skeletonIn,
    std::shared_ptr<SkeletonTransform> const& skeletonTransformIn,
    std::shared_ptr<SkinnedMesh> const& meshIn, std::shared_ptr<Texture2D> const& textureIn)
{
    command.skeleton = skeletonIn;
    command.skeletonTransform = skeletonTransformIn;
    command.mesh = meshIn;
    command.texture = textureIn;

    POMDOG_ASSERT(command.skeleton);
    POMDOG_ASSERT(command.skeletonTransform);
    POMDOG_ASSERT(command.mesh);
    POMDOG_ASSERT(command.texture);
}

void SkinnedMeshRenderable::Visit(GameObject & gameObject, Renderer & renderer)
{
    if (!IsVisible) {
        return;
    }

    command.drawOrder = DrawOrder;

    if (auto transform = gameObject.Component<Transform2D>()) {
        command.localToWorld = CreateTransformMatrix4x4(*transform);
    }
    else {
        command.localToWorld = Matrix4x4::Identity;
    }

    command.color = this->Material.Color;

    renderer.PushCommand(command);
}

}// namespace Pomdog
