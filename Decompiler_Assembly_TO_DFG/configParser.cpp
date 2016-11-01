#include "configParser.h"


int main()
{
  configuration::graphData myconfigdata;
  ifstream f( "temp_out" );
  f >> myconfigdata;
  f.close();
  ofstream o("testConfig.txt");
  o << myconfigdata;
}