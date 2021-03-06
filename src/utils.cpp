#include "utils.h"

Utils& Utils::getInstance(std::string file){
    static Utils instance(file);
    return instance;
}

Utils::Utils(std::string file): fr(fileIO::getIntance()), fileName(file) {
    fr.setNameR(fileName);
    labelNum = atoi(fr.readLine().c_str());
    tMax = atoi(fr.readLine().c_str());
    cat_num = atoi(fr.readLine().c_str());
    pro_num = atoi(fr.readLine().c_str());
    vec.reserve(cat_num+pro_num);
    std::string temp = fr.readLine();
    while( !temp.empty() ) {
        vec.push_back(temp);
        temp = fr.readLine();
    }
    for(unsigned int i = 0; i < vec.size(); i++) {
         mapping[vec[i]] = i;
        // cout << vec[i] << ": "<< mapping[vec[i]] << endl;
    }
}
unordered_map<std::string, int> Utils::getTMap(){
    unordered_map<std::string, int> temp;
    temp["2012"] = 0;
    temp["2013"] = 1;
    temp["2014"] = 2;
    temp["2015"] = 3;
    temp["2016"] = 4;
    return temp;
}
vector<std::string> Utils::getVector() const {
    return vec;
}
unordered_map<std::string, int> Utils::getMapping() {
	//cout <<"================"<< mapping["2:2"] << endl;
    return mapping;
}
