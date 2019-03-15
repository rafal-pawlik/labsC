#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>


unsigned int ToMinutes(std::string time_HH_MM); // input format HH:MM or H:MM
unsigned int MinimalTimeDifference(std::vector<std::string> times);


int main(int argc,char** argv){

    std::vector<std::string> v = {"10:10","20:20","10:20","10:01","11:20"};

    unsigned int min = MinimalTimeDifference(v);

    std::cout << min << '\n';


    return 0;
}


unsigned int ToMinutes(std::string time_HH_MM){

    std::string buff_H = "";
    std::string buff_M = "";

    bool flag = true; // wczytywanie do buff_H lub do buff_M

    for(auto& s: time_HH_MM){
        if(s == ':'){
            flag = false;
            continue;
        }
        if(flag) buff_H += s;
        else buff_M += s;
    }

    return (unsigned int)std::stoi(buff_H) * 60 + std::stoi(buff_M);
}



unsigned int MinimalTimeDifference(std::vector<std::string> times){

    unsigned int min;

    std::vector<unsigned int> v;

    for(auto x: times){
        v.push_back(ToMinutes(x));
    }

    if(v[0] - v[1] > 0){
        min = v[0] - v[1];
    } else if (v[1] - v[0]){
        min = v[1] - v[0];
    }


    for(auto t1: v){
        for(auto t2: v){
            if((t1 > t2 ) and (t1 - t2 < min)){
                min = t1 - t2;
            }
        }
    }



    return min;
}
