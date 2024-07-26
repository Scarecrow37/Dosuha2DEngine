#include "pch.h"
#include "Base.h"

#include "../../Modifier/IModifier.h"

Input::Value Input::Trigger::Base::GetModifiedValue() const
{
    return std::accumulate(_modifiers.begin(), _modifiers.end(), _inputComponent.lock()->GetValue(),
                           [](const Value& value, const std::shared_ptr<IModifier>& modifier)
                           {
                               return modifier->operator()(value);
                           });
}
