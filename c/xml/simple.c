#include <stdio.h>
#include <string.h>
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>

void printElementNames(xmlNode *node){
  xmlNode *curNode = NULL;

  for(curNode = node; curNode != NULL; curNode = curNode->next){
    if(curNode->type == XML_ELEMENT_NODE){
      printf("%s\n", curNode->name);
    }
    printElementNames(curNode->children);
  }
}

int main(int argc, char *argv[]){

  xmlDoc         *document;
  xmlNode        *root, *node;
  char           *filename;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename.xml\n", argv[0]);
    return 1;
  }
  
  filename = argv[1];

  LIBXML_TEST_VERSION

  document = xmlReadFile(filename, NULL, 0);
  root = xmlDocGetRootElement(document);
  /* fprintf(stdout, "Root is <%s> (%i)\n", root->name, root->type); */
  printElementNames(root);

  /* Free document. */
  xmlFreeDoc(document);

  /* Free globals */
  xmlCleanupParser();
  
  return 0;
}


	  
