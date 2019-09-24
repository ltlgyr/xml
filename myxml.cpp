#include <iostream>
#include "parseXML.hpp"
using namespace std;

int main(int argc, char **argv) {
	char *docname;
	if (argc <= 1) {
		printf("Usage: %s docname\n", argv[0]);
		return 1;
	}
	docname = argv[1];
	IP_XML test(docname);
	cout << "ip:" <<test.getipc()<< "\nport:" << test.getport()<<endl;
	return 0;
}
