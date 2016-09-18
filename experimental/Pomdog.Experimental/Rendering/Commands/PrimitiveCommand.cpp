// Copyright (c) 2013-2016 mogemimi. Distributed under the MIT license.

#include "PrimitiveCommand.hpp"
#include <typeinfo>

namespace Pomdog {
namespace Rendering {

std::type_index PrimitiveCommand::GetType() const noexcept
{
    static const std::type_index index = typeid(PrimitiveCommand);
    return index;
}

float PrimitiveCommand::GetDrawOrder() const noexcept
{
    return drawOrder;
}

} // namespace Rendering
} // namespace Pomdog
