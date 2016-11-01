#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace configuration
{

  //---------------------------------------------------------------------------
  // The configuration::data is a simple map string (key, value) pairs.
  // The file is stored as a simple listing of those pairs, one per line.
  // The key is separated from the value by an equal sign '='.
  // Commentary begins with the first non-space character on the line a hash or
  // semi-colon ('#' or ';').
  //
  // Example:
  //   # This is an example
  //   source.directory = C:\Documents and Settings\Jennifer\My Documents\
  //   file.types = *.jpg;*.gif;*.png;*.pix;*.tif;*.bmp
  //
  // Notice that the configuration file format does not permit values to span
  // more than one line, commentary at the end of a line, or [section]s.
  //   
  /*
    std::multimap<std::string,int> mm;
    for( int i = 0; i != 10; ++i )
      mm.insert(make_pair("hello world"), i);
  */
struct graphData: std::map <std::string, std::string>
{
      bool iskey( const std::string& s ) const
      {
        return (count( s ) != 0);
      }
      int getintvalue( const std::string& key )
      {
        if (!iskey( key )) throw 0;
          std::istringstream ss( this->operator [] ( key ) );
          int result;
          ss >> result;
        if (!ss.eof()) throw 1;
          return result;
      }
};

  //---------------------------------------------------------------------------
  // The extraction operator reads configuration::data until EOF.
  // Invalid data is ignored.
  //


  //---------------------------------------------------------------------------
  // The insertion operator writes all configuration::data to stream.
  //
 std::istream& operator >> ( std::istream& ins, graphData& d ){
    std::string s, key, value;

    // For each (key, value) pair in the file
    while (std::getline( ins, s )){
        std::string::size_type begin = s.find_first_not_of( " \f\t\v" );

        // Skip blank lines
        if (begin == std::string::npos) continue;

       // Skip commentary
       if (std::string( "#;" ).find( s[ begin ] ) != std::string::npos) continue;

        // Extract the key value
        std::string::size_type end = s.find( ' ', begin );
        key = s.substr( begin, end - begin );

        // (No leading or trailing whitespace allowed)
        key.erase( key.find_last_not_of( " \f\t\v" ) + 1 );

        // No blank keys allowed
        if (key.empty()) continue;

        // Extract the value (no leading or trailing whitespace allowed)
        begin = s.find_first_not_of( " \f\n\r\t\v", end + 1 );
        end   = s.find_last_not_of(  " \f\n\r\t\v" ) + 1;

        value = s.substr( begin, end - begin );

        // Insert the properly extracted (key, value) pair into the map
        d[ key ] = value;
    }
    return ins;
}

std::ostream& operator << ( std::ostream& outs, const graphData& d )
    {
    graphData::const_iterator iter;
    for (iter = d.begin(); iter != d.end(); iter++)
      outs << iter->first << " = " << iter->second << endl;
    return outs;
    }
} // namespace configuration 
