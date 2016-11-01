#include "TraceParser.h"
#include "TokenHelper.h"
#include "Decorator_X86.h"




int main(){
	//string trace_file;
	//cout << "trace file name:";
	//cin >> trace_file;
	/*Configuration Procedure*/
	string config;
	string tracefile;
	
	TraceParser thisTraceParser;
	cout<<"Enter the configuration file name:";
	cin>>config;
	//Step 1
	thisTraceParser.loadComponents(config);
	//Step 2
	cout<<"Enter the trace file's name: ";
	cin >> tracefile;
	thisTraceParser.ParseOne(tracefile, "test.dom");

	//Step 3 Read Modified trace Complete

	//Step 4 Graph 
	//testVec();
	DecoratorClass decorator;
	decorator.mainMethod();
	decorator.funcMapper();
	return 0;

}

/*

RUNNING TESTS
	
	vector<string> Instruction1;
	Instruction1.push_back("0x401153.0");
	Instruction1.push_back("@main+245.0");
	Instruction1.push_back("CMP_M_I");
	Instruction1.push_back("limm");
	Instruction1.push_back("t2d");
	Instruction1.push_back("0x3e8");

	vector<string> Instruction2;
	Instruction2.push_back("0x401153.1");
	Instruction2.push_back("@main+245.1");
	Instruction2.push_back("CMP_M_I");
	Instruction2.push_back("ld");
	Instruction2.push_back("t1d");
	Instruction2.push_back("DS");
	//auto func = [] (vector<string>& Instruction) { };

	map<string,void(*)(vector<string>&)> void_map;
    void_map["limm"] = limm;
    void_map["ld"] = ld;
	

    //void_map["limm"](Instruction1);
    //void_map["ld"](Instruction2);
	
	//func(Instruction);
	//string name;
	//cin >> name;
	//return global_address_book.findMatchAddresses(
	//	[&] (const string& addr) {return addr.find(name) != string::npos});

	//string 
	// Int map
	
    map<string,void(*)(vector<string>&)> void_map;
    void_map["limm"] = limm;
    void_map["ld"] = ld;
	

    //void_map["limm"](Instruction1);
    //void_map["ld"](Instruction2);
    //int_map["B"] = FuncB;
    // Call it
    //cout<<void_map["limm"](Instruction1)<<endl;
    //cout<<void_map["limm"](Instruction2)<<endl;
    //cout<<int_map["B"]()<<endl;

    // Add it to your map
    //map<string, void(*)()> any_map;
    //any_map["A"] = FuncA;
    //any_map["B"] = FuncB;

    // Call
    //cout<<reinterpret_cast<float(*)()>(any_map["B"])()<<endl;
    //Testing split function
    
    string word = "ADD_I_M";
    vector<string> output;
    split(word, '_', output);

    for (int i=0; i<output.size(); i++){
    	cout << output[i] <<endl;
    }
	
	
	std::cout << "Enter your age: ";
	int age;
	std::cin >> age;
 
	const int usersAge (age); // usersAge can not be changed
*/

