#include "parseXML.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


IP_XML::IP_XML(char * docname){
	parseDoc(docname);
}
#if 0
void IP_XML::parseDoc(char * docname){
	doc = xmlParseFile(docname);
	if( doc == NULL )
	{
		printf("Fail to parse XML File.\n");
		return ;
	}
	cur = xmlDocGetRootElement(doc);
	if( cur == NULL)
	{
		printf("Fail to get root element\n");
		return;
	}

	if(xmlStrcmp(cur->name, BAD_CAST "work"))
	{
		fprintf(stderr,"document of the wrong type, root node != root");
		xmlFreeDoc(doc);
		return ;
	}

	while (cur != NULL)
	{
		if ((xmlStrcmp(cur->name, (const xmlChar *)"netinfo")))
		{
		}
		cur = cur->next;
	}

}
#endif

void IP_XML::parseNetwork (xmlDocPtr doc, xmlNodePtr cur) {
	xmlChar *key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"ip"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			ip = inet_addr((char * )key);
			printf("ip: %s, ip = %x \n", key, ip);
			xmlFree(key);
		}
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"port"))) {
			key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			port = atoi((char * )key);
			printf("port: %sport= %d\n", key, port);
			xmlFree(key);
		}
		cur = cur->next;
	}
	return;
}
void IP_XML::parseBody (xmlDocPtr doc, xmlNodePtr cur) {
}


void IP_XML::parseDoc(char *docname) {
	xmlDocPtr doc;
	xmlNodePtr cur;
	doc = xmlParseFile(docname);
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}

	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "work")) {
		fprintf(stderr,"document of the wrong type, root node != story");
		xmlFreeDoc(doc);
		return;
	}

	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"netinfo"))){
			parseNetwork (doc, cur);
		}
		cur = cur->next;
	}

	xmlFreeDoc(doc);
	return;
}


unsigned int IP_XML::getip(){
	return ip;
}
char * IP_XML::getipc(){
	return inet_ntoa( *(struct in_addr *)&ip);
}
unsigned short  IP_XML::getport(){
	return port;
}
