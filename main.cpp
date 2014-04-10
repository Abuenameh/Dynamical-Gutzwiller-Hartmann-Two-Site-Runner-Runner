/* 
 * File:   main.cpp
 * Author: abuenameh
 *
 * Created on November 14, 2013, 6:14 PM
 */

#include <cstdlib>

using namespace std;

#include <boost/lexical_cast.hpp>
#include <boost/process.hpp>

using boost::lexical_cast;
using namespace boost::process;
using namespace boost::process::initializers;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int seed0 = lexical_cast<int>(argv[1]);
    int nseed = lexical_cast<int>(argv[2]);
    double Wi = lexical_cast<double>(argv[3]);
    double Wf = lexical_cast<double>(argv[4]);
    double mu = lexical_cast<double>(argv[5]);
    double D = lexical_cast<double>(argv[6]);
    double dt = lexical_cast<double>(argv[7]);
    int dnsav = lexical_cast<int>(argv[8]);
    int tau0 = lexical_cast<int>(argv[9]);
    int tauf = lexical_cast<int>(argv[10]);
    int dtau = lexical_cast<int>(argv[11]);
    int numthreads = lexical_cast<int>(argv[12]);
    int res0 = lexical_cast<int>(argv[13]);
    int dres = lexical_cast<int>(argv[14]);
    
    int seed = seed0;
    int res = res0;
    for (int i = 0; i < nseed; i++, seed++, res += dres) {
#ifdef AMAZON
        string prog = "/home/ubuntu/dynamical_gutzwiller_hartmann_two_site_runner";
#elif defined(FSTSERVER)
        string prog = "C:/Users/Abuenameh/Documents/NetBeansProjects/Dynamical Gutzwiller Hartmann Two Site Runner/dist/Release/MinGW_TDM-Windows/dynamical_gutzwiller_hartmann_two_site_runner.exe";
#else
        string prog = "/Users/Abuenameh/NetBeansProjects/Dynamical Gutzwiller Hartmann Two Site Runner/dist/Release/GNU-MacOSX/dynamical_gutzwiller_hartmann_two_site_runner";
#endif
	vector<string> args;
	args.push_back(prog);
        args.push_back(lexical_cast<string>(seed));
        args.push_back(lexical_cast<string>(Wi));
        args.push_back(lexical_cast<string>(Wf));
        args.push_back(lexical_cast<string>(mu));
        args.push_back(lexical_cast<string>(D));
        args.push_back(lexical_cast<string>(dt));
        args.push_back(lexical_cast<string>(dnsav));
        args.push_back(lexical_cast<string>(res));
        args.push_back(lexical_cast<string>(tau0));
        args.push_back(lexical_cast<string>(tauf));
        args.push_back(lexical_cast<string>(dtau));
        args.push_back(lexical_cast<string>(numthreads));

        child c = execute(set_args(args), inherit_env());
        wait_for_exit(c);
    }

    return 0;
}

