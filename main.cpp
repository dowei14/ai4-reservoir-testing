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

//Set parameters (for Students)
#define NUMBER_DATA  46821 //number of total data (if using Learning mode 1-4 & Testing Data_4900.txt)
#define BPM_ITER   46821   //set it equal to the number of total data (if using Learning mode 1-4 & Testing Data_4900.txt)


///////////////////////////////////////////
TestESN* test;
int t;
int i_text_loop;
int ii;
bool initialized;
double input_temp;
double target_temp;
double input;
double target;
float density;
int steps;

float *input_vector;
float *train_vector;


vector<double> m_r0_t;
vector<double> m_r1_t;

int main (int argc, char **argv)
{


  // ************ Essential parameter initialization **************
  steps = BPM_ITER;

  //*****************************************************************

  input_vector = new float [steps];
  train_vector = new float [steps];

  test = new TestESN();

  m_r0_t.resize(NUMBER_DATA);
  m_r1_t.resize(NUMBER_DATA);
  
  	int counter = 0;	
  	
	ifstream data_inputs("../data/inRNN.txt"); //opening an input stream for file test.txt
	ifstream data_outputs("../data/outRNN.txt"); //opening an input stream for file test.txt
	std::string line_out;
	for(std::string line_in; std::getline(data_inputs, line_in); )   //read stream line by line
	{

		// add inputs
		std::istringstream in(line_in);      //make a stream for the line itself
		for (int i=0;i<num_input_ESN;i++){
			in >> input;                  //and read the first whitespace-separated token
		}

		// add outputs
		std::getline(data_outputs, line_out);
		std::istringstream out(line_out);
		for (int o=0;o<num_output_ESN;o++){
			out >> target;                  //and read the first whitespace-separated token
		}
		
		//-----------Call ESN, recurrent network------------------//
		test->RecurrentNetwork(input,target);
		//--------------------------------------------------------//
    	std::cout<<"counter"<<" "<<counter<< "\n";
    	counter++;
	}




/*
  for (int i=1;i<BPM_ITER;i++) {

    if (use_file_data){
      //------------Read from the file--------------------------------------------//
      char str[10];

      //For students
      //ifstream b_file ("TestingData_4900.txt"); // 2 column data, first column = input, second column = target
      ifstream b_file ("TestingData_2000.txt"); // 2 column data, first column = input, second column = target


      if(!initialized)
      {i_text_loop = 0;
      while(b_file>>str) //time first column
      {
        input_temp = atof(str);//input
        m_r0_t.at(i_text_loop) = input_temp;

        b_file>> str;
        target_temp = atof(str);//target
        m_r1_t.at(i_text_loop) = target_temp;

        i_text_loop++;
      }
      initialized = true;
      }

      if(ii<i_text_loop)
      {
        ii++;
      }
      else
      {
        ii=0;
      }

      input = m_r0_t.at(ii);
      target = m_r1_t.at(ii);
      //--------------------------------------------------------//

    }

    else {
      input = input_vector[i];
      target = train_vector[i];
    }

    //-----------Call ESN, recurrent network------------------//
    test->RecurrentNetwork(input,target);
    //--------------------------------------------------------//


    std::cout<<"counter"<<" "<<i<< "\n";

  }
*/

  return 0;
}
