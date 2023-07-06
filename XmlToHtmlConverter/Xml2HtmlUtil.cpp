#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "rapidxml/rapidxml.hpp"
#include "Xml2HtmlUtil.h"

using namespace rapidxml;

Xml2HtmlUtil::Xml2HtmlUtil(const std::string& fileName)
{
	m_fHandle.open(fileName.c_str(), std::ios::in);
}

Xml2HtmlUtil::~Xml2HtmlUtil()
{
	m_fHandle.close();
}

// Function to convert Xml2HtmlUtil to 2D table
void Xml2HtmlUtil::RunEngine()
{
	std::vector<char> fileBuf((std::istreambuf_iterator<char>(m_fHandle)), std::istreambuf_iterator<char>());
	fileBuf.push_back('\0');

	// Create RapidXML document
	xml_document<> doc;
	doc.parse<0>(&fileBuf[0]);

	xml_node<>* root = doc.first_node();
	if (!root) {
		std::cout << "Empty document" << std::endl;
		return;
	}

	if (!(root->first_node() && root->first_node()->first_node()))
	{
		std::cout << "xml can not be converted to 2D table" << std::endl;
		return;
	}

	std::cout << "<table>" << std::endl;

	// Parse the header row
	for (xml_node<>* child = root->first_node()->first_node(); child; child = child->next_sibling()) {
		std::cout << "    <th>" << child->name() << "</th>" << std::endl;
	}
	std::cout << "  </tr>" << std::endl;

	// Parse the data rows
	for (xml_node<>* row = root->first_node(root->first_node()->name()); row; row = row->next_sibling(root->first_node()->name())) {
		std::cout << "  <tr>" << std::endl;
		for (xml_node<>* child = row->first_node(); child; child = child->next_sibling()) {
			std::cout << "    <td>" << child->value() << "</td>" << std::endl;
		}
		std::cout << "  </tr>" << std::endl;
	}

	std::cout << "</table>" << std::endl;
}