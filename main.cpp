/**
 * @author Sakya & Poramate 02.12.2013
 */


#include "esntest.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <fstream>


///////////////////////////////////////////
TestESN* test;
double input;
double target;



int main (int argc, char **argv)
{


  // ************ Essential parameter initialization **************

  //*****************************************************************
	ofstream saveFile1;
	saveFile1.open("error.txt",ios::out);
	saveFile1.precision(3);

int repretitions = 1;
int runs = 50;


for (int a=0;a<repretitions;a++){
	test = new TestESN();	
	bool train = true;	

	for (int i=0; i<runs;i++){
		train = true;
		std::cout<<"Training run: "<< i<< std::endl;
//		ifstream data_inputs("../data/train/inRNN_18.txt"); //opening an input stream for file test.txt
//		ifstream data_inputs("../data/train/inRNN_11.txt"); //opening an input stream for file test.txt
//		ifstream data_outputs("../data/train/outRNN_binary.txt"); //opening an input stream for file test.txt

		ifstream data_inputs("../data/train/inRNN_12.txt"); //opening an input stream for file test.txt
		ifstream data_outputs("../data/train/outRNN_scalar.txt"); //opening an input stream for file test.txt
		
		
		
		for(std::string line_in; std::getline(data_inputs, line_in); )   //read stream line by line
		{
			std::vector<double> inputs;
			// add inputs
			std::istringstream in(line_in);      //make a stream for the line itself
			for (int i=0;i<num_input_ESN;i++){
				in >> input;                  //and read the first whitespace-separated token
				inputs.push_back(input);
			}

			std::vector<double> targets;
			std::string line_out;		
			// add outputs
			std::getline(data_outputs, line_out);
			std::istringstream out(line_out);
			for (int o=0;o<num_output_ESN;o++){
				out >> target;                  //and read the first whitespace-separated token
				targets.push_back(target);
			}
		
			//-----------Call ESN, recurrent network------------------//
			test->RecurrentNetwork(inputs,targets, train);
			//--------------------------------------------------------//
			//if (counter % 1000 == 0)std::cout<<"counter"<<" "<<counter<< "\n";
		}
		train = false;
		int counter = 0;
		double error = 0.0;
	
//		ifstream data_inputs_test("../data/test/inRNN_18.txt"); //opening an input stream for file test.txt
//		ifstream data_inputs_test("../data/test/inRNN_11.txt"); //opening an input stream for file test.txt
//		ifstream data_outputs_test("../data/test/outRNN_binary.txt"); //opening an input stream for file test.txt

		ifstream data_inputs_test("../data/test/inRNN_12.txt"); //opening an input stream for file test.txt		
		ifstream data_outputs_test("../data/test/outRNN_scalar.txt"); //opening an input stream for file test.txt	

		for(std::string line_in; std::getline(data_inputs_test, line_in); )   //read stream line by line
		{
			std::vector<double> inputs;
			// add inputs
			std::istringstream in(line_in);      //make a stream for the line itself
			for (int i=0;i<num_input_ESN;i++){
				in >> input;                  //and read the first whitespace-separated token
				inputs.push_back(input);
			}

			std::vector<double> targets;
			std::string line_out;		
			// add outputs
			std::getline(data_outputs_test, line_out);
			std::istringstream out(line_out);
			for (int o=0;o<num_output_ESN;o++){
				out >> target;                  //and read the first whitespace-separated token
				targets.push_back(target);
			}
			//-----------Call ESN, recurrent network------------------//
			error = test->RecurrentNetwork(inputs,targets, train);
			//--------------------------------------------------------//
			//if (counter % 1000 == 0)std::cout<<"counter"<<" "<<counter<< "\n";
			counter++;
		}
		std::cout<<"Error: " << error <<" "<< counter<< " " <<error / (double)counter<<std::endl;
		saveFile1 << (i+1)*10 << " " <<error / (double)counter <<"\n";
	}
	/*****
	** Store network
	test->store();
	****/
}	
	
	saveFile1.close();

  return 0;
}
