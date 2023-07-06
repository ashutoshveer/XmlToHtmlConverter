#ifndef XML_2_HTML_UTIL_HEADER
#define XML_2_HTML_UTIL_HEADER 

class Xml2HtmlUtil
{
public:
	Xml2HtmlUtil(const std::string& fileName);
	~Xml2HtmlUtil();

	void RunEngine();

private:
	std::ifstream m_fHandle;
};

#endif /* XML_2_HTML_UTIL_HEADER */


