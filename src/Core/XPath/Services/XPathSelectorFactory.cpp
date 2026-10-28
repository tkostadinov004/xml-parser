#include "Core/XPath/Services/XPathSelectorFactory.h"
#include "Core/XPath/Selectors/XPathMixinSelector.h"
#include "Core/XPath/Selectors/AxisSelectors/XPathAncestorSelector.h"
#include "Core/XPath/Selectors/AxisSelectors/XPathAxisSelector.h"
#include "Core/XPath/Selectors/AxisSelectors/XPathChildSelector.h"
#include "Core/XPath/Selectors/AxisSelectors/XPathDescendantSelector.h"
#include "Core/XPath/Selectors/AxisSelectors/XPathParentSelector.h"
#include "Core/XPath/Selectors/AttributeSelectors/XPathAttributeByExistenceSelector.h"
#include "Core/XPath/Selectors/AttributeSelectors/XPathAttributeByValueSelector.h"

XPathSelectorFactory::XPathSelectorFactory(const XPathQueryComponent& component) : _component(component)
{
}

MySharedPtr<XPathSelector> XPathSelectorFactory::create() const
{
	MySharedPtr<XPathSelector> result;
	if (_component.getAxis() == "child")
	{
		result = new XPathChildSelector();
	}
	else if (_component.getAxis() == "descendant")
	{
		result = new XPathDescendantSelector();
	}
	else if (_component.getAxis() == "parent")
	{
		result = new XPathParentSelector();
	}
	else if (_component.getAxis() == "ancestor")
	{
		result = new XPathAncestorSelector();
	}

	if (_component.getAttributeFilter()._isQueryValue && !_component.getAttributeFilter()._key.empty())
	{
		result = new XPathMixinSelector(result, new XPathAttributeByValueSelector());
	}
	else if (!_component.getAttributeFilter()._key.empty() && !_component.getAttributeFilter()._isQueryValue)
	{
		result = new XPathMixinSelector(result, new XPathAttributeByExistenceSelector());
	}
    return result;
}