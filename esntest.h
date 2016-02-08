/**
 * @author Sakya & Poramate 02.12.2013
 */

#ifndef __TestESN_H__
#define __TestESN_H__

// #################### definitions #####################

#include <math.h>
#include <string.h>
#include <stdio.h>

#include <vector>



///////// Save text////////////////////////
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
///////////////////////////////////////////


//Set parameters (for Students)
const int num_input_ESN = 12;
const int num_output_ESN = 1;
//const int num_input_ESN = 18;
//const int num_input_ESN = 11;
//const int num_output_ESN = 7;
const int num_hidden_ESN = 50; // Student Adjust!***

//set learning_mode = 1 for RLS (learning rate or forgetting factor needs to be large, e.g., 0.99)
//set learning mode =2  for LMS (learning rate needs to be small, e.g., 0.01)
const int learning_mode = 2;

//if learning_mode is 1 --> RLS this learning_rate_ESN is forgetting factor (Lambda)!
const double learning_rate_ESN = 0.01; // Student Adjust!***

// if leak = 1.0 means = no memory and no leak term used
// if leak = small vale (e.g., 0.3) = large memory (low leak)
// if leak = large vale (e.g., 0.7) = less memory (high leak)
const double leak = 0.33;

// if 70 means 70% sparsity; i.e., only 30% input projections to hidden neurons
const double input_sparsity = 70;



class TestESN
{
  public:

    TestESN();
    ~TestESN();


    // --- Save text------------//
    ofstream saveFile1;
    //-------------------------//
    double RecurrentNetwork(std::vector<double> i0, std::vector<double> d, bool train);
    bool store();
    double target_ESN;
    double input_ESN;
    double output_ESN;
    bool learn;
    double error;
    int washout_time;

};

#endif
