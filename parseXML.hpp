#ifndef __IP_XML_H
#define __IP_XML_H
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

class IP_XML{
	private:
	unsigned int ip;
	unsigned short int port;
	xmlDocPtr doc;
	xmlNodePtr cur;
	xmlChar *key;
	void parseNetwork(xmlDocPtr doc, xmlNodePtr cur) ;
	void parseBody(xmlDocPtr doc, xmlNodePtr cur) ;

	public:
	IP_XML(void);
	IP_XML(char * docname);
	unsigned int getip();
	char * getipc() ;
	unsigned short getport();
	void parseDoc(char *docname);
	~IP_XML(){
	}
};

#endif
