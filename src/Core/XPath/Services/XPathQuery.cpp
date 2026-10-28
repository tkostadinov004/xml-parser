#include "Core/XPath/Services/XPathQuery.h"
#include "Core/XML/Models/XMLTextNode.h"
#include "Core/XPath/QueryParser\XPathQueryDeserializer.h"
#include "Core/XPath/Services/XPathSelectorFactory.h"
#include "Core/XPath/ResultSerializers\XPathQueryResultSerializer.h"

MyVector<const XMLNode*> XPathQuery::evaluate(const MySharedPtr<XMLElementNode>& root, const MyString& queryString)
{
	MyVector<const XMLNode*> result;
	result.push_back(root.get());

	XPathQueryDeserializer deserializer(queryString);
	MyVector<XPathQueryComponent> components = deserializer.deserialize();

	for (const XPathQueryComponent& currentComponent : components)
	{
		XPathSelectorFactory factory(currentComponent);
		result = factory.create()->execute(result, currentComponent);
	}

	return result;
}
