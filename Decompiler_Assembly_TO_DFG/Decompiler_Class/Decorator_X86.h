#ifndef DECORATOR_X86_H
#define DECORATOR_X86_H
#define _CRT_SECURE_NO_WARNINGS
#include "includeAll.h"




class DecoratorClass
{
	private:
		vector< std::string > instrCol;
		vector<	vector<std::string> > instrRow;
		vector< std::string > graphCol;
		vector< vector<std::string> > graphRow;
		ofstream graphStream;
		//int blockRef = 0;

	public:
		void ADD(vector<string>& Instr);
		void ADDI(vector<string>& Instr);
		void ADC(vector<string>& Instr);
		void ADCI(vector<string>& Instr);
		void SUB(vector<string>& Instr);
		void SUBI(vector<string>& Instr);
		void MUL1S(vector<string>& Instr);
		void MUL1SI(vector<string>& Instr);
		void MUL1U(vector<string>& Instr);
		void MUL1UI(vector<string>& Instr);
		void MULEL(vector<string>& Instr);
		void MULEH(vector<string>& Instr);
		void OR(vector<string>& Instr);
		void ORI(vector<string>& Instr);
		void XOR(vector<string>& Instr);
		void MXOR(vector<string>& Instr);
		void XORI(vector<string>& Instr);
		void AND(vector<string>& Instr);
		void ANDI(vector<string>& Instr);
		void SLL(vector<string>& Instr);
		void SLLI(vector<string>& Instr);
		void SRL(vector<string>& Instr);
		void SRLI(vector<string>& Instr);
		void SRA(vector<string>& Instr);
		void SRAI(vector<string>& Instr);
		void ROR(vector<string>& Instr);
		void RORI(vector<string>& Instr);
		void RCRI(vector<string>& Instr);
		void ROL(vector<string>& Instr);
		void ROLI(vector<string>& Instr);
		void RCL(vector<string>& Instr);
		void RCLI(vector<string>& Instr);
		void MOV(vector<string>& Instr);
		void MOVSIGN(vector<string>& Instr);
		void MOV2INT(vector<string>& Instr);
		void MCMPI2R(vector<string>& Instr);
		void MOVI(vector<string>& Instr);
		void SEXT(vector<string>& Instr);
		void SEXTI(vector<string>& Instr);
		void ZEXT(vector<string>& Instr);
		void ZEXTI(vector<string>& Instr);
		void RUFLAG(vector<string>& Instr);
		void RUFLAGS(vector<string>& Instr);
		void WRUFLAGS(vector<string>& Instr);
		void WRUFLAGSI(vector<string>& Instr);
		void RDIP(vector<string>& Instr);
		void WRIP(vector<string>& Instr);
		void WRIPI(vector<string>& Instr);
		void LD(vector<string>& Instr);
		void LDFP(vector<string>& Instr);
		void LFPIMM(vector<string>& Instr);
		void LDM(vector<string>& Instr);
		void LDST(vector<string>& Instr);
		void LDSTL(vector<string>& Instr);
		void ST(vector<string>& Instr);
		void STF(vector<string>& Instr);
		void STFP(vector<string>& Instr);
		void STM(vector<string>& Instr);
		void STUPD(vector<string>& Instr);
		void LEA(vector<string>& Instr);
		void CDA(vector<string>& Instr);
		void CDAF(vector<string>& Instr);
		void CIA(vector<string>& Instr);
		void TIA(vector<string>& Instr);
		void LIMM(vector<string>& Instr);
		void MOVFP(vector<string>& Instr);
		void MOV2FP(vector<string>& Instr);
		void XORFP(vector<string>& Instr);
		void ADDFP(vector<string>& Instr);
		void SUBFP(vector<string>& Instr);
		void MULFP(vector<string>& Instr);
		void DIVFP(vector<string>& Instr);
		void COMPFP(vector<string>& Instr);
		void CVTF_I2D(vector<string>& Instr);
		void CVTF_I2D_HI(vector<string>& Instr);
		void CVTF_D2I(vector<string>& Instr);
		void FAULT(vector<string>& Instr);
		void LDDHA(vector<string>& Instr);
		void LDAHA(vector<string>& Instr);
		void BR(vector<string>& Instr);
		void MADDF(vector<string>& Instr);
		void MMULF(vector<string>& Instr);
		void GLOBGRAPH();
		void GraphFileHandler();
		void funcMapper();
		inline void mainMethod(); 
};
void DecoratorClass::GraphFileHandler(){
	graphStream.open("test.dot");
}
void DecoratorClass::ADD(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();

} 
void DecoratorClass::ADDI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
} 
void DecoratorClass::ADC(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
} 
void DecoratorClass::ADCI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
}
void DecoratorClass::SUB(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	/*if (std::stoi(Instr[0]) != blockRef){
		graphStream<<"\t\t\t"<<"}"<<endl;
		blockRef++;
	}
	else{
		 blockRef++;
		 continue;
	}*/
} 
void DecoratorClass::SUBI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
}
void DecoratorClass::MUL1S(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	/*if (std::stoi(Instr[0]) != blockRef){
		graphStream<<"\t\t\t"<<"}"<<endl;
		blockRef++;
	}
	else{
		 blockRef++;
		 continue;
	}*/
} 
void DecoratorClass::MUL1SI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
}
void DecoratorClass::MUL1U(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
}
void DecoratorClass::MUL1UI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
}
void DecoratorClass::MULEL(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
}
void DecoratorClass::MULEH(vector<string>& Instr){}
void DecoratorClass::OR(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
}
void DecoratorClass::ORI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
}
void DecoratorClass::XOR(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
	
}
void DecoratorClass::MXOR(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::XORI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::AND(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::ANDI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::SLL(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::SLLI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::SRL(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::SRLI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::SRA(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::SRAI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::ROR(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::RORI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::RCRI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::ROL(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::ROLI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::RCL(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::RCLI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MOV(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MOVSIGN(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MOV2INT(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MCMPI2R(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MOVI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::SEXT(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::SEXTI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::ZEXT(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::ZEXTI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::RUFLAG(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::RUFLAGS(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::WRUFLAGS(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::WRUFLAGSI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::RDIP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::WRIP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::WRIPI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LD(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LDFP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LFPIMM(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LDM(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LDST(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LDSTL(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::ST(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::STF(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::STFP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::STM(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::STUPD(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LEA(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::CDA(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::CDAF(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::CIA(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::TIA(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LIMM(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MOVFP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MOV2FP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::XORFP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::ADDFP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::SUBFP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MULFP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::DIVFP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::COMPFP(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::CVTF_I2D(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::CVTF_I2D_HI(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::CVTF_D2I(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::FAULT(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LDDHA(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::LDAHA(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::BR(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MADDF(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}
void DecoratorClass::MMULF(vector<string>& Instr){
	string blockNum = Instr[0];
	string lineNum = Instr[1];
	string Abs = Instr[2];
	string Rel = Instr[3];
	string Mac = Instr[4];
	string nodeLabel = Instr[5];
	string destLabel1 = Instr[6];
	string srcLabel1 = Instr[7];
	string srcLabel2 = Instr[8];
	string node = Instr[5] + "_" + Instr[0] + "_" + Instr[1];
	string dest = Instr[6] + "_" + Instr[0] + "_" + Instr[1];
	string src1 = Instr[7] + "_" + Instr[0] + "_" + Instr[1];
	string src2 = Instr[8]+ "_" + Instr[0] + "_" + Instr[1];
	graphCol.push_back(blockNum);
	graphCol.push_back(lineNum);
	graphCol.push_back(Abs);
	graphCol.push_back(Rel);
	graphCol.push_back(Mac);
	graphCol.push_back(nodeLabel);
	graphCol.push_back(destLabel1);
	graphCol.push_back(srcLabel1);
	graphCol.push_back(srcLabel2);
	graphCol.push_back(node);
	graphCol.push_back(dest);
	graphCol.push_back(src1);
	graphCol.push_back(src2);
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphCol.push_back("0");
	graphRow.push_back(graphCol);
	graphCol.clear();
}


void DecoratorClass::GLOBGRAPH(){
/*
	graphCol.push_back(blockNum) = 0,  		graphCol.push_back(lineNum) = 1,		graphCol.push_back(Abs) = 2,
	graphCol.push_back(Rel) = 3,			graphCol.push_back(Mac) = 4,			graphCol.push_back(nodeLabel) = 5,
	graphCol.push_back(destLabel1) = 6,		graphCol.push_back(srcLabel1) = 7,		graphCol.push_back(srcLabel2) = 8,
	graphCol.push_back(node) = 9,			graphCol.push_back(dest) = 10,			graphCol.push_back(src1) = 11,
	graphCol.push_back(src2) = 12,			graphCol.push_back("0") = 13,           graphCol.push_back("0") = 14,
	graphCol.push_back("0") = 15
*/
	graphStream << "digraph G{\n";
	for(int i = 0; i < graphRow.size(); ++i)
	{
		for (int j = i + 1; j < graphRow.size(); j++)
		{
			if ( graphRow[i][6] == graphRow[j][7])
			{
				if(graphRow[i][6] != "0")
				{
					if( (graphRow[j][13] ==  "0") && (graphRow[i][15] == "0") )
					{		
							graphRow[j][13] = "1";
							graphRow[i][15] = "1";
							graphStream <<"\t\t"<< graphRow[i][9]<<"[shape = box, label = \""<<graphRow[i][5]<<"\"]"<<endl;
							graphStream <<"\t\t"<< graphRow[j][9]<<"[shape = box, label = \""<<graphRow[j][5]<<"\"]"<<endl;
							graphStream <<"\t\t"<< graphRow[i][9]<<"->"<<graphRow[j][9]<<"[label = \""<<graphRow[j][7]<<"\"]"<<endl;
					}
				}
			}
			if (graphRow[i][6] == graphRow[j][8])
			{
				if( graphRow[i][6] != "0")
				{
					if( (graphRow[j][14] == "0")  &&  (graphRow[i][15] == "0") )
					{
							graphRow[j][14] = "1";
							graphRow[i][15] = "1";
							graphStream <<"\t\t"<< graphRow[i][9]<<"[shape = box, label = \""<<graphRow[i][5]<<"\"]"<<endl;
							graphStream <<"\t\t"<< graphRow[j][9]<<"[shape = box, label = \""<<graphRow[j][5]<<"\"]"<<endl;
							graphStream <<"\t\t"<< graphRow[i][9]<<"->"<<graphRow[j][9]<<"[label = \""<<graphRow[j][8]<<"\"]"<<endl;
					}
				}
			}
		}
	}//for(int i = 0; i < graphRow.size(); ++i)
	for (int i = 0; i < graphRow.size(); i++)
	{
		if (graphRow[i][15] == "0")
		{
			if(graphRow[i][6] != "0")
			{
				
				graphRow[i][15] = "1";
				graphStream << "\t\t" <<"F_"<<graphRow[i][0]<<"_"<<graphRow[i][1]<<"[shape = box, label = FINISH]"<<endl;
				graphStream << "\t\t" <<graphRow[i][9]<< "->" << "F_" << graphRow[i][0] <<"_" << graphRow[i][1];
				graphStream << "[label = \""<<graphRow[i][6]<<"\"]"<<endl;
				
			}
		}
		if (graphRow[i][13] == "0")
		{
			if(graphRow[i][7] != "0")
			{
				//if (graphRow[i][13] == "0") 
				//{
					graphRow[i][13] = "1";
					graphStream << "\t\t" <<"L_"<<graphRow[i][0]<<"_"<<graphRow[i][1]<<"[shape = box, label = start]"<<endl;
					graphStream << "\t\t" <<"L_"<<graphRow[i][0]<<"_"<<graphRow[i][1]<<"->"<<graphRow[i][9];
					graphStream << "[label = \""<<graphRow[i][7]<<"\"]"<<endl;
				//}
			}
		}
		if (graphRow[i][14] == "0")
		{
			if (graphRow[i][8] != "0")
			{
				//if (graphRow[i][14] == "0")
				//{
					graphRow[i][14] = "1";
					graphStream << "\t\t" <<"R_"<<graphRow[i][0]<<"_"<<graphRow[i][1]<<"[shape = box, label = start]"<<endl;
					graphStream << "\t\t" <<"R_"<<graphRow[i][0]<<"_"<<graphRow[i][1]<<"->"<<graphRow[i][9];
					graphStream << "[label = \""<<graphRow[i][8]<<"\"]"<<endl;
				//}
			}
		} 
	}
	graphStream<<"}";
	graphStream.close();
	//thisGraph.print_Block_Graph();
	//cout<<graphRow[0][0]<<endl;
}

void DecoratorClass::funcMapper(){
	//graphStream.open("test.dot");
	//graphStream << "digraph G {\n\t\t\t";
	for (int i =0; i < instrRow.size(); i++){
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "add") 	!= instrRow[i].end()) {
				ADD(instrRow[i]);  
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "addi") 	!= instrRow[i].end()) {
				ADDI(instrRow[i]); 
			}  
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "adc") 	!= instrRow[i].end()) {
				ADC(instrRow[i]);  
			} 
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "adci") 	!= instrRow[i].end()) {
				ADCI(instrRow[i]); 
			} 
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "sub") 	!= instrRow[i].end()) {
				SUB(instrRow[i]);  
			}  
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "subi")	!= instrRow[i].end()) {
				SUBI(instrRow[i]); 
			} 
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mul1s")	!= instrRow[i].end()) {
				MUL1S(instrRow[i]);  
			}  
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mul1si")	!= instrRow[i].end()) {
				MUL1SI(instrRow[i]); 
			} 
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mul1u")	!= instrRow[i].end()) { 
				MUL1U(instrRow[i]); 
			} 
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mul1ui")	!= instrRow[i].end()) { 
				MUL1UI(instrRow[i]);
			} 
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mulel")	!= instrRow[i].end()) { 
				MULEL(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "muleh")	!= instrRow[i].end()) { 
				MULEH(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "or")		!= instrRow[i].end()) { 
				OR(instrRow[i]);    
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ori")	!= instrRow[i].end()) { 
				ORI(instrRow[i]);   
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "xor")	!= instrRow[i].end()) { 
				XOR(instrRow[i]);   
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mxor")	!= instrRow[i].end()) { 
				MXOR(instrRow[i]);  
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "xori")	!= instrRow[i].end()) { 
				XORI(instrRow[i]);  
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "and")	!= instrRow[i].end()) { 
				AND(instrRow[i]);   
			} 
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "andi")	!= instrRow[i].end()) { 
				ANDI(instrRow[i]);  
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "sll")	!= instrRow[i].end()) { 
				SLL(instrRow[i]);  
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "slli")	!= instrRow[i].end()) { 
				SLLI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "srl")	!= instrRow[i].end()) { 
				SRL(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "srli")	!= instrRow[i].end()) { 
				SRLI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "sra")	!= instrRow[i].end()) { 
				SRA(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "srai")	!= instrRow[i].end()) { 
				SRAI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ror")	!= instrRow[i].end()) { 
				ROR(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "rori")	!= instrRow[i].end()) { 
				RORI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "rcri")	!= instrRow[i].end()) { 
				RCRI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "rol")	!= instrRow[i].end()) { 
				ROL(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "roli")	!= instrRow[i].end()) { 
				ROLI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "rcl")	!= instrRow[i].end()) { 
				RCL(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "rcli")	!= instrRow[i].end()) { 
				RCLI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mov")	!= instrRow[i].end()) { 
				MOV(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "movsign")	!= instrRow[i].end()) {  
				MOVSIGN(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mov2int")	!= instrRow[i].end()) {  
				MOV2INT(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mcmpi2r")	!= instrRow[i].end()) {  
				MCMPI2R(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "movi")		!= instrRow[i].end()) {  
				MOVI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "sext")		!= instrRow[i].end()) {  
				SEXT(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "sexti")		!= instrRow[i].end()) {  
				SEXTI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "zext")		!= instrRow[i].end()) {  
				ZEXT(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "zexti")		!= instrRow[i].end()) {  
				ZEXTI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ruflag")		!= instrRow[i].end()) {  
				RUFLAG(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ruflags")	!= instrRow[i].end()) {  
				RUFLAGS(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "wruflags")	!= instrRow[i].end()) {  
				WRUFLAGS(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "wruflagsi")	!= instrRow[i].end()) {  
				WRUFLAGSI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "rdip")		!= instrRow[i].end()) {  
				RDIP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "wrip")		!= instrRow[i].end()) {  
				WRIP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "wripi")		!= instrRow[i].end()) {  
				WRIPI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ld")			!= instrRow[i].end()) {  
				LD(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ldfp")		!= instrRow[i].end()) {  
				LDFP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "lfpimm")		!= instrRow[i].end()) {  
				LFPIMM(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ldm")		!= instrRow[i].end()) {  
				LDM(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ldst")		!= instrRow[i].end()) {  
				LDST(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ldstl")		!= instrRow[i].end()) {  
				LDSTL(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "st")			!= instrRow[i].end()) {  
				ST(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "stf")		!= instrRow[i].end()) {  
				STF(instrRow[i]);
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "stfp")		!= instrRow[i].end()) {  
				STFP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "stm")		!= instrRow[i].end()) {  
				STM(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "stupd")		!= instrRow[i].end()) {  
				STUPD(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "lea")		!= instrRow[i].end()) {  
				LEA(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "cda")		!= instrRow[i].end()) {  
				CDA(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "cdaf")		!= instrRow[i].end()) {  
				CDAF(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "cia")		!= instrRow[i].end()) {  
				CIA(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "tia")		!= instrRow[i].end()) {  
				TIA(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "limm")		!= instrRow[i].end()) {  
				LIMM(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "movfp")		!= instrRow[i].end()) {  
				MOVFP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mov2fp")		!= instrRow[i].end()) {  
				MOV2FP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "xorfp")		!= instrRow[i].end()) {  
				XORFP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "addfp")		!= instrRow[i].end()) {  
				ADDFP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "subfp")		!= instrRow[i].end()) {  
				SUBFP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mulfp")		!= instrRow[i].end()) {  
				MULFP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "divfp")		!= instrRow[i].end()) {  
				DIVFP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "compfp")		!= instrRow[i].end()) {  
				COMPFP(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "cvtf_i2d")	!= instrRow[i].end()) {  
				CVTF_I2D(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "cvtf_i2d_hi")	!= instrRow[i].end()) {  
				CVTF_I2D_HI(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "cvtf_")	!= instrRow[i].end()) {  
				CVTF_D2I(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "fault")	!= instrRow[i].end()) {  
				FAULT(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "lddha")	!= instrRow[i].end()) {  
				LDDHA(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "ldaha")	!= instrRow[i].end()) {  
				LDAHA(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "br")		!= instrRow[i].end()) {  
				BR(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "maddf")	!= instrRow[i].end()) {  
				MADDF(instrRow[i]); 
			}
			if (std::find(instrRow[i].begin(), instrRow[i].end(), "mmulf")	!= instrRow[i].end()) {  
				MMULF(instrRow[i]); 
			}
	}
	GLOBGRAPH();
}

inline void DecoratorClass::mainMethod(){
		GraphFileHandler();
		ifstream fin;
    	fin.open ("temp_out");
    	vector<string> thisinstr;
    	if (!fin.good()) return;
    	//Processing each line into single tokens
    	while (!fin.eof()){
        	char buf[512];
        	fin.getline(buf, 512);

        	//Reseting tokens after newline
        	int n = 0;

        	//storing tokens
        	const char* token[20] = {};

        	//Parsing each line from temp_out
        	token[0] = strtok(buf, " ");
        	if (token[0]) //false if line is blank
        	{
        		for (n = 1; n < 20; n++){
        			token[n] = strtok(0, " "); // Read other tokens
        			if(!token[n]) break;  //end of tokens
        		}
        	}
        	
        	if(n == 9){
        		for (int i = 0; i < n; i++) {
					instrCol.push_back(token[i]);
        		}
        		instrRow.push_back(instrCol);
        		instrCol.clear();
        	}//End of if(n == 8)
    	}//end of while loop
    	/*
    	for (int i=0; i < instrRow.size(); i++){
    		for(int j=0; j <instrRow[i].size(); j++){
    			cout<<instrRow[i][5];
    		}
    		cout<<endl;
    		//cout<<B[i]<<" "<<l[i]<<" "<<A[i]<<" "<<a[i]<<" "<<M[i]<<" "<<m[i]<<" "<<r1[i]<<" "<<r2[i]<<" "<<r3[i]<<endl;
    	
    	}
    	*/
}
/*
GraphViz example for graph blocks

digraph G {

	subgraph cluster_0 {
		style=filled;
		color=lightgrey;
		node [style=filled,color=white];
		a0 -> a1 -> a2 -> a3;
		label = "process #1";
	}

	subgraph cluster_1 {
		node [style=filled];
		b0 -> b1 -> b2 -> b3;
		label = "process #2";
		color=blue
	}
	start -> a0;
	start -> b0;
	a1 -> b3;
	b2 -> a3;
	a3 -> a0;
	a3 -> end;
	b3 -> end;

	start [shape=Mdiamond];
	end [shape=Msquare];
}

*/

//Implementation
/*
	map<string,void(*)(vector<string>&)> void_map;
    void_map["limm"] = limm;
    void_map["ld"] = ld;

    void_map["limm"](Instruction1);
    void_map["ld"](Instruction2);
*/
#endif

